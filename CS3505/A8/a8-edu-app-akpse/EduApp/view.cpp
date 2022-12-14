/*
// File name: view.cpp
// Author:    Soli, Allen, Michal, Emile, Stefan
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
//      This is the view class that controls what appears on the GUI as well as signals for a chess puzzle game.
*/

#include <QListWidgetItem>
#include "view.h"
#include "Box2D/Collision/Shapes/b2PolygonShape.h"
#include "Box2D/Dynamics/b2Body.h"
#include "Box2D/Dynamics/b2Fixture.h"
#include "ui_view.h"


///
/// \brief View::View   Constructor for the view, initializes all connections and sets up ui for View
/// \param model        Model to attach signals and slots to
/// \param parent       Parent widget to attach to
///
View::View(Model& model, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::View)
    , world(gravity)
{
    ui->setupUi(this);


    connect(ui->rulesButton,
            &QPushButton::pressed,
            this,
            &View::openRulesPage);

    connect(ui->quitButton,
            &QPushButton::pressed,
            this,
            [this]()
    {
        ui->allPagesStackedWidget->setCurrentIndex(1);
    });

    // ui->chessBoardView->setPieceImage(QImage(":images/bBishop.png"));

//    connect(&chessBoard,
//            &ChessBoardView::itemDrop,
//            this,
//            ui->chessBoardView);


    // Sets up initial page to be the title screen
    ui->allPagesStackedWidget->setCurrentIndex(0);


    // TITLE SCREEN CONNECTIONS

    // Title play button is clicked, going to level selector page
    connect(ui->playButtonTitle,
            &QPushButton::clicked,
            this,
            [this]()
    {
        ui->allPagesStackedWidget->setCurrentIndex(1);
    });

    // Title help menu button is clicked, displaying help menu
    connect(ui->helpMenuButtonTitle,
            &QPushButton::pressed,
            this,
            [this]()
    {
        const QString helpText = "WHAT IS THIS PROGRAM?"
                                 "\n"
                                 "This is an educational chess puzzle game program to get player aquainted with the rules of chess and apply various strategies!"
                                 "\n"
                                 "\n"
                                 "PLAY"
                                 "\n"
                                 "To begin playing, press the 'Play' button and navigate to the Level Select Menu."
                                 "\n"
                                 "\n"
                                 "LEADERBOARD"
                                 "\n"
                                 "The leaderboard will display all the best times for any given level. \n"
                                 "Your name will be displayed as 'Player' on the leaderboard page!"
                                 "\n"
                                 "\n"
                                 "RULES"
                                 "\n"
                                 "This will open an website page showing the user how to play chess! \n"
                                 "In that page, you can look at how each chess piece works and learn rules for the game.";

        QMessageBox::information(this, "Help Menu", helpText);
    });

    // Title rules button is clicked, displaying rules window
    connect(ui->rulesButtonTitle,
            &QPushButton::pressed,
            this,
            &View::openRulesPage);

    // Title quit button is clicked, exiting the application
    connect(ui->quitButtonTitle,
            &QPushButton::pressed,
            this,
            &QCoreApplication::quit);


    // LEVEL SELECTOR (LS) SCREEN CONNECTIONS

    // LS back button is clicked, going back to title page
    connect(ui->backButton,
            &QPushButton::clicked,
            this,
            [this]()
    {
        ui->allPagesStackedWidget->setCurrentIndex(0);
    });

    // A level button is clicked
    QList<QPushButton*> levelButtons = {ui->levelOneEasyButton, ui->levelTwoEasyButton, ui->levelThreeEasyButton, ui->levelFourEasyButton,
                                       ui->levelOneMediumButton, ui->levelTwoMediumButton, ui->levelThreeMediumButton, ui->levelFourMediumButton,
                                       ui->levelOneHardButton, ui->levelTwoHardButton, ui->levelThreeHardButton, ui->levelFourHardButton};
    for (auto levelButton : levelButtons)
    {
        // Go to the chess page
        connect(levelButton,
                &QPushButton::pressed,
                this,
                &View::goToChessForm);
    }

    // Loads a level
    connect(this,
            &View::loadLevelSignal,
            &model,
            &Model::loadLevel);

    connect(&model,
            &Model::updateLevelTextGui,
            this,
            &View::updateLevelTextGui);

    // Chess board view and the model
    connect(ui->chessBoardView,
            &ChessBoardView::getBoardPosition,
            &model,
            &Model::getBoardPosition);

    connect(&model,
            &Model::updatePieces,
            ui->chessBoardView,
            &ChessBoardView::updatePieces);

    // If the model updates the board and the timer is not running (such as when you retry a puzzle),
    // then restart the timer
    connect(&model,
            &Model::updatePieces,
            ui->chessBoardView,
            [this]{if(!ui->puzzleTimer->isRunning())
            {
                ui->puzzleTimer->resetTimer();
                ui->puzzleTimer->startTimer();
            }});

    connect(&model,
            &Model::updateHighlightedMoves,
            ui->chessBoardView,
            &ChessBoardView::updateHighlightedMoves);

    connect(&model,
            &Model::updateDisplayedTurn,
            this,
            &View::updateDisplayedTurn);

    connect(&model,
            &Model::endOfGame,
            this,
            &View::processWinOrLose);

    // LEADERBOARD CONNECTIONS

    // Leaderboard back button is clicked, goes back to title page from leaderboard view
    connect(ui->leaderboardBackButton,
            &QPushButton::clicked,
            this,
            [this]()
    {
        //ui->leaderboardListWidget->clear();
        ui->allPagesStackedWidget->setCurrentIndex(0);
        ui->leaderboardListWidget->clear();
    });

    // Leaderboards button is clicked, load the contents of it
    connect(ui->leaderboardButton,
            &QPushButton::clicked,
            &model,
            &Model::loadLeaderboard);

    connect(&model,
            &Model::updateLeaderboard,
            this,
            &View::loadLeaderboard);

    connect(&model,
            &Model::updateLeaderboardEntry,
            this,
            &View::updateLeaderboardEntry);

    // display leaderboard window when leaderboard option is pressed
    connect(ui->leaderboardButton,
            &QPushButton::clicked,
            this,
            [this]()
    {
        ui->allPagesStackedWidget->setCurrentIndex(3);
    });

    // Connect hint and retry buttons to model
    connect(ui->hintButton,
            &QPushButton::clicked,
            &model,
            &Model::processHint);

    connect(ui->retryButton,
            &QPushButton::clicked,
            &model,
            &Model::processRetry);

    // Connect time signal to model's slot that processes leaderboard given a time
    connect(this,
            &View::currentTime,
            &model,
            &Model::processLeaderboard);

    // connect the page changes of the stacked widget
    connect(ui->allPagesStackedWidget, &QStackedWidget::currentChanged, this, &View::processFormChange);

    // Now initialize Box2D
    // =====================
    // Define ground body
    b2BodyDef groundBodyDef;
    groundBodyDef.position.Set(-40.0f, -50.3f);

    // Call the body factory which allocates memory for the ground body
    // from a pool and creates the ground box shape (also from a pool).
    // The body is also added to the world.
    groundBody = world.CreateBody(&groundBodyDef);

    // Define the ground box shape.
    b2PolygonShape groundBox;

    // The extents are the half-widths of the box.
    groundBox.SetAsBox(groundWidth, groundHeight);

    // Add the ground fixture to the ground body.
    groundBody->CreateFixture(&groundBox, 0.0f);

    // At this point, world and ground are established

    // Now initialize timer that processes world steps
    constexpr float32 timeStep = 1.0f / 60.0f;
    constexpr int32 velocityIterations = 8;
    constexpr int32 positionIterations = 3;

    simulationTimer = new QTimer(this);
    simulationTimer->setInterval(timeStep * 1000);
    simulationTimer->setTimerType(Qt::PreciseTimer);

    connect(simulationTimer, &QTimer::timeout, this, [this]
    {
        const float xOffset = rand() % 9 - 4;
        const float yOffset = rand() % 9 - 4;
        if(stepCounter % 40 == 0)
            physicsChessPieces.push_back(PhysicsChessPiece(world, -40.0f + xOffset, 15.0f + yOffset, dynamicWidth, dynamicHeight));
        world.Step(timeStep, velocityIterations, positionIterations);
        repaint();
        ++stepCounter;
    });

    // This code below is a little jank, but QStackedWidget needs to send a currentChanged
    // signal to the first page (the main menu), as this is how Box2D will initialize
    ui->allPagesStackedWidget->setCurrentIndex(1);
    ui->allPagesStackedWidget->setCurrentIndex(0);
}


///
/// \brief View::~View  Destructor that deletes the ui
///
View::~View()
{
    delete ui;
}


///
/// \brief View::openRulesPage  Opens a QTextBrowser window showing the basic rules of chess
///
void View::openRulesPage()
{
    const QString htmlString = R"(
        <h2>Basics of Chess</h2>
        <p style="font-size: 1.5em;">You start with several different types of pieces, listed below. The goal of the game is to <strong>checkmate</strong> the opponent's king. This occurs when the opponent's king can not escape being captured by your pieces, regardless of what moves they play.</p>
        <h2>Pieces</h2>
        <p style="font-size: 1.5em;">The <strong>king</strong> can move one square in any direction, including diagonally. <a href="https://herculeschess.com/how-does-the-king-move-in-chess/">Read more.</a></p>
        <br><b><img src=":images/wKing.png" alt="king image" style="width:20px;height:20px;">
        <p style="font-size: 1.5em;">The <strong>queen</strong> can move any number of squares horizontally, vertically, or diagonally. <a href="https://herculeschess.com/how-does-the-queen-move-in-chess/">Read more.</a></p>
        <br><b><img src=":images/wQueen.png" alt="queen image" style="width:20px;height:20px;"><br><br>
        <p style="font-size: 1.5em;">The <strong>bishop</strong> can move any number of squares diagonally. <a href="https://herculeschess.com/how-does-the-bishop-move-in-a-chess-game/">Read more.</a></p>
        <br><b><img src=":images/wBishop.png" alt="bishop image" style="width:20px;height:20px;"><br><br>
        <p style="font-size: 1.5em;">The <strong>rook</strong> can move any number of squares horizontally and vertically. <a href="https://chesseasy.com/rooks-in-chess-how-do-rooks-move-in-chess/">Read more.</a></p>
        <br><b><img src=":images/wRook.png" alt="rook image" style="width:20px;height:20px;"><br><br>
        <p style="font-size: 1.5em;">The <strong>knight</strong> move in an L shape, going 2 squares vertically or horizontally, plus one perpendicularly in either direction. The knight is the only piece that can jump over other pieces. <a href="https://chesseasy.com/knights-in-chess-how-do-knights-move-in-chess/">Read more.</a></p>
        <br><b><img src=":images/wKnight.png" alt="knight image" style="width:20px;height:20px;"><br><br>
        <p style="font-size: 1.5em;">The <strong>pawn</strong> moves only one square directly ahead of it at a time, however it can move two squares forward if it has not moved yet. Additionally, the pawn can capture <strong>only</strong> towards squares 1 tile diagonally ahead of it. When a pawn reaches the other side of the board, it can be promoted to a queen, bishop, rook, or knight. <a href="https://herculeschess.com/how-do-the-pawns-move-in-a-chess-game/">Read more.</a></p>
        <br><b><img src=":images/wPawn.png" alt="pawn image" style="width:20px;height:20px;"><br><br>
        <h2>Further resources</h2>
        <p style="font-size: 1.5em;">To learn more about the rules, use <a href="https://www.thechesswebsite.com/learn-to-play-chess/">this resource.</a></p>
        )";
    QTextBrowser *tb = new QTextBrowser();
    tb->setMinimumSize(800, 600);
    tb->setOpenExternalLinks(true);
    tb->setHtml(htmlString);
    tb->show();
}


///
/// \brief View::updateDisplayedTurn    Updates which turn it is
/// \param playerTurn                   Whether it is the player or CPU's turn
///
void View::updateDisplayedTurn(bool playerTurn)
{
    if(playerTurn)
    {
        ui->turnLabel->setText("Player Turn");
        ui->turnLabel->setStyleSheet("QLabel { color : green; }");
    }
    else
    {
        ui->turnLabel->setText("Opponent Turn");
        ui->turnLabel->setStyleSheet("QLabel { color : red; }");
    }
}


///
/// \brief Processes when the stackedwidget changes forms
/// \param index of form being changed to
///
void View::processFormChange(int index)
{
    if(index == 0)
    {
        simulationTimer->start();
    }
    else if(index != 0)
    {
        // clear all dynamic bodies if switch pages, stop simulation
        simulationTimer->stop();
        for(auto& piece : physicsChessPieces)
            world.DestroyBody(&piece.getBody());
        physicsChessPieces.clear();
        stepCounter = 0;
        repaint();
    }

    if(index == 2)
    {
        ui->puzzleTimer->resetTimer();
        ui->puzzleTimer->startTimer();
        ui->chessBoardView->update();
    }
}


///
/// \brief View::goToChessForm  Switches to the chess page
///
void View::goToChessForm()
{
    ui->allPagesStackedWidget->setCurrentIndex(2);

    // Figure out which level is selected
    levelToLoad(qobject_cast<QPushButton*>(qobject_cast<QPushButton*>(sender()))->objectName());
}


///
/// \brief View::loadLeaderboard Loads the leaderboard when first playing
///
void View::loadLeaderboard(const QString levelName, const QMap<QTime, QString>& leaderboard)
{
    ui->leaderboardListWidget->addItem("Best Times for Level: " + levelName);

    // Load the leaderboard stats for that level
    // Add the current entries to leaderboard
    int rankNum = 1;
    QMap<QTime, QString>::const_iterator it;
    for (it = leaderboard.begin(); it != leaderboard.end(); it++)
    {
        const QString name = it.value();
        const QTime time = it.key();
        const QString item = QString::number(rankNum++) + ". " + name + " ---------- " + time.toString();
        ui->leaderboardListWidget->addItem(item);
    }

    ui->leaderboardListWidget->addItem("\n");
}


///
/// \brief View::updateLeaderboard  Updates the leaderboard with the player's time on a specified level.
///                                 This is called when the player wins and has an entry that could be better
///                                 than a current time.
///
void View::updateLeaderboardEntry(const Level level, const QTime& timeEntry, const QString nameEntry)
{
    level.leaderboard->addNewRecord(timeEntry, nameEntry);
}


///
/// \brief View::levelToLoad        Sends signal to model to load a level
/// \param buttonName               Name of level to attempt loading
///
void View::levelToLoad(QString buttonName)
{
    emit loadLevelSignal(buttonName);
}


///
/// \brief Used to draw Box2D objects onto the screen
///
void View::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.eraseRect(0, 0, 1000, 1000);

    // Guard clause, if not on main menu, don't do any special drawing logic
    if(ui->allPagesStackedWidget->currentIndex() != 0)
        return;

    QPen pen(Qt::black);
    int penWidth = 5;
    constexpr int scale = 10;
    pen.setWidth(penWidth);
    painter.setPen(pen);
    painter.setBrush(Qt::blue);

    // Now that ground is drawn, draw the dynamic body
    for(const auto& piece : physicsChessPieces)
    {
        const auto& [bodyXPos, bodyYPos] = piece.getBody().GetPosition();

        const qreal angle = piece.getBody().GetAngle() * 180 / 3.14159265358979323846264;

        // This bodyRect defines the size of the image
        const QRect bodyRect(0, 0, piece.getWidth() * 2 * scale, piece.getHeight() * 2 * scale);

        const int bodyCenterX = -bodyXPos * scale;
        const int bodyCenterY = -bodyYPos * scale;

        const int upperLeftOffsetX = -piece.getWidth() * scale;
        const int upperLeftOffsetY = -piece.getHeight() * scale;

        // This mess is just a conversion of coordinate systems
        // First, translates the painter to the center of the Box2D object
        // Then, rotates around this center point
        // Then, translates to the upper left corner of object (this is where images are drawn from)
        // Then it can draw the image rotatedly
        // Afterwards, undoes all the rotations
        painter.translate(bodyCenterX, bodyCenterY);
        painter.rotate(angle);
        painter.translate(upperLeftOffsetX, upperLeftOffsetY);

        // painter.drawRect(bodyRect);
        painter.drawImage(bodyRect, piece.getImage());

        painter.translate(-upperLeftOffsetX, -upperLeftOffsetY);
        painter.rotate(-angle);
        painter.translate(-bodyCenterX, -bodyCenterY);
    }
}


///
/// \brief updateLevelTextGui   Updates the text on the chess page to display the level's information
/// \param levelTextInfo        The info necessary to display
///
void View::updateLevelTextGui(QVector<QString> levelTextInfo)
{
    ui->puzzleNumberLabel->setText("Puzzle #: " + levelTextInfo[0]);
    ui->puzzleNameLabel->setText("Name: " + levelTextInfo[1]);
    ui->puzzleDifficultyLabel->setText("Difficulty: " + levelTextInfo[2]);
}


///
/// \brief View::processWinOrLose   Processes win or lose signal from model
/// \param winOrLose                True if won, false otherwise
///
void View::processWinOrLose(QString winOrLose)
{
    QString windowName;
    QString resultText;

    if (winOrLose.toLower() == "win")
    {
        windowName = "Victory!";
        resultText = "You Win!";
        emit currentTime(ui->puzzleTimer->getTime());
        ui->puzzleTimer->stopTimer();
    }
    else
    {
        windowName = "Wrong Move.";
        resultText = "Incorrect move. Try again..";
    }
    QMessageBox::information(this, windowName, resultText);
}
