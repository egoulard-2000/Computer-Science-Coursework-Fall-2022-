/*
// File name: view.h
// Author:    Stefan, Allen, Soli
// Assignment:Educational Program
// Group:     AKPSE
// Date:      11/23/2022
// Course:    CS 3505, University of Utah, School of Computing
// Copyright: CS 3505 and AKPSE - This work may not be copied for use in Academic Coursework.
//
// Our group, AKPSE, certifies that we wrote this code from scratch and did not copy it in part or whole from
// another source.
//
// File Contents
//
//      view.h is the header file for view.cpp. This is a view to model
//      a puzzle chess game model.
*/

#ifndef VIEW_H
#define VIEW_H

#include <QMainWindow>
#include <QTextBrowser>
#include <QMessageBox>
#include "Box2D/Dynamics/b2World.h"
#include "chessboardview.h"
#include "leaderboard.h"
#include "model.h"
#include "physicschesspiece.h"

QT_BEGIN_NAMESPACE
namespace Ui { class View; }
QT_END_NAMESPACE

class View : public QMainWindow
{
    Q_OBJECT

public:
    ///
    /// \brief View::View   Constructor for the view, initializes all connections and sets up ui for View
    /// \param model        Model to attach signals and slots to
    /// \param parent       Parent widget to attach to
    ///
    View(Model& model, QWidget *parent = nullptr);

    ///
    /// \brief View::~View  Destructor that deletes the ui
    ///
    ~View();

public slots:

    ///
    /// \brief View::openRulesPage  Opens a QTextBrowser window showing the basic rules of chess
    ///
    void openRulesPage();

    ///
    /// \brief Processes when the stackedwidget changes forms
    /// \param index of form being changed to
    ///
    void processFormChange(int index); // used primarily to initialize Box2D on the main page

    ///
    /// \brief View::goToChessForm  Switches to the chess page
    ///
    void goToChessForm();

    ///
    /// \brief View::updateDisplayedTurn    Updates which turn it is
    /// \param playerTurn                   Whether it is the player or CPU's turn
    ///
    void updateDisplayedTurn(bool playerTurn);

    ///
    /// \brief View::loadLeaderboard Loads the leaderboard when first playing
    ///
    void loadLeaderboard(const QString levelName, const QMap<QTime, QString>& leaderboard);

    ///
    /// \brief View::updateLeaderboard  Updates the leaderboard with the player's time on a specified level.
    ///                                 This is called when the player wins and has an entry that could be better
    ///                                 than a current time.
    ///
    void updateLeaderboardEntry(const Level level, const QTime& timeEntry, const QString nameEntry);

    ///
    /// \brief updateLevelTextGui   Updates the text on the chess page to display the level's information
    /// \param levelTextInfo        The info necessary to display
    ///
    void updateLevelTextGui(QVector<QString> levelTextInfo);

    ///
    /// \brief View::processWinOrLose   Processes win or lose signal from model
    /// \param winOrLose                True if won, false otherwise
    ///
    void processWinOrLose(QString winOrLose);

signals:
    void loadLevelSignal(QString levelName);
    void currentTime(const QTime time);

private:
    b2Body* createDynamicBody(const float32 x, const float32 y);

    ///
    /// \brief View::levelToLoad        Sends signal to model to load a level
    /// \param buttonName               Name of level to attempt loading
    ///
    void levelToLoad(QString levelName);

    ///
    /// \brief Used to draw Box2D objects onto the screen
    ///
    void paintEvent(QPaintEvent *) override;

    Ui::View *ui;

    // Implement Box2D on main menu
    const b2Vec2 gravity = {0.0f, -20.0f};
    const float32 groundWidth = 15.0f;
    const float32 groundHeight = 1.0f;
    const float32 dynamicWidth = 3.0f;
    const float32 dynamicHeight = 3.0f;
    b2World world;
    b2Body* groundBody;
    b2Body* dynamicBody = nullptr;

    std::vector<PhysicsChessPiece> physicsChessPieces;
    int stepCounter = 0;
    QTimer* simulationTimer = nullptr;
};
#endif // VIEW_H
