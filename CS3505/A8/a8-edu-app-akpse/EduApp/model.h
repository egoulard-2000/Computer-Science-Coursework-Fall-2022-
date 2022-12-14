/*
// File name: model.h
// Author:    Soli, Emile
// Assignment:Educational Program
// Group:     AKPSE
// Date:      12/08/2022
// Course:    CS 3505, University of Utah, School of Computing
// Copyright: CS 3505 and AKPSE - This work may not be copied for use in Academic Coursework.
//
// Our group, AKPSE, certifies that we wrote this code from scratch and did not copy it in part or whole from
// another source.
//
// File Contents
//
//      model.h is the header file for model.cpp. Please see said file for details.
*/

#ifndef MODEL_H
#define MODEL_H

#include "lcdclock.h"
#include "levelloader.h"
#include "levelsdatabase.h"
#include <QObject>

class Model : public QObject
{
    Q_OBJECT
public:
    Model();

signals:
    void updatePieces(QMap<ChessPosition, ChessPiece*> board);
    void updateHighlightedMoves(QVector<ChessPosition> moves);
    void updateLeaderboard(QString levelName, QMap<QTime, QString> leaderboard);
    void updateLeaderboardEntry(Level level, QTime timeEntry, QString nameEntry);
    void endOfGame(QString winOrLose);
    void updateDisplayedTurn(bool playerTurn);
    void updateLevelTextGui(QVector<QString> levelTextInfo);

public slots:
    void loadLevel(QString levelName);

    void getBoardPosition(ChessPosition position);

    void updateDisplayFromLevel();
    void loadLeaderboard();

    void processHint();
    void processRetry();

    void processLeaderboard(const QTime& time);

private:
    QVector<Level> allLevels;
    LevelLoader levelLoader;
    LevelsDatabase levelsDatabase;

    QString currentLevelName;
};

#endif // MODEL_H
