#include "view.h"
#include "model.h"
#include "ui_view.h"
#include <QKeyEvent>

using namespace std;

/*
CS 3505 - A5 - QT SimonGame
10/28/2022

Emile Goulard - u1244855
Michael Sullivan - u0794378

*/
View::View(Model& model, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::View)
{
    ui->setupUi(this);

    // Actions
    connect(ui->RedButton,
            &QPushButton::clicked,
            &model,
            &Model::redButtonClicked);

    connect(ui->BlueButton,
            &QPushButton::clicked,
            &model,
            &Model::blueButtonClicked);

    connect(ui->StartButton,
            &QPushButton::clicked,
            &model,
            &Model::startGame);

    // Update High Score Functionality
    connect(&model,
            &Model::updateHighScore,
            ui->HighScoreVar,
            &QLabel::setText);

    // Set Visibility of View
    connect(&model,
            &Model::showStartButton,
            ui->StartButton,
            &QPushButton::setVisible);

    connect(&model,
            &Model::showLoseScreen,
            ui->LoseLabel,
            &QLabel::setVisible);

    connect(&model,
            &Model::showSimonButtons,
            ui->RedButton,
            &QPushButton::setVisible);

    connect(&model,
            &Model::showSimonButtons,
            ui->BlueButton,
            &QPushButton::setVisible);

    connect(&model,
            &Model::showProgressBar,
            ui->ProgressBar,
            &QProgressBar::setVisible);

    connect(&model,
            &Model::showProgressBar,
            ui->ProgressLabel,
            &QLabel::setVisible);

    connect(&model,
            &Model::progressChanged,
            ui->ProgressBar,
            &QProgressBar::setValue);

    connect(&model,
            &Model::showHighScore,
            ui->HighScoreLabel,
            &QLabel::setVisible);

    connect(&model,
            &Model::showHighScore,
            ui->HighScoreVar,
            &QLabel::setVisible);

    connect(&model,
            &Model::showProgressBar,
            ui->ProgressLabel,
            &QLabel::setVisible);

    connect(&model,
            &Model::showInstructions,
            ui->InstructionLabel,
            &QLabel::setVisible);

    connect(&model,
            &Model::showInstructions,
            ui->ControlLabelRed,
            &QLabel::setVisible);

    connect(&model,
            &Model::showInstructions,
            ui->ControlLabelBlue,
            &QLabel::setVisible);

    // Game Speed Control
    connect(&model,
            &Model::increaseGameSpeed,
            this,
            &View::increaseGameSpeed);

    // Red Color Set
    ui->RedButton->setStyleSheet( QString("QPushButton {background-color: rgb(200,50,50);} QPushButton:pressed {background-color: rgb(255,150,150);}"));

    // Blue Color Set
    ui->BlueButton->setStyleSheet( QString("QPushButton {background-color: rgb(50,50,200);} QPushButton:pressed {background-color: rgb(150,150,255);}"));

    // Lose Screen is hidden upon starting
    ui->LoseLabel->setVisible(false);

    // Buttons Screen are hidden upon starting
    ui->RedButton->setVisible(false);
    ui->BlueButton->setVisible(false);

    // Stats hidden upon starting
    ui->ProgressBar->setVisible(false);
    ui->ProgressBar->setValue(0);
    ui->ProgressLabel->setVisible(false);
    ui->HighScoreLabel->setVisible(false);
    ui->HighScoreVar->setVisible(false);
    ui->InstructionLabel->setVisible(false);
    ui->ControlLabelRed->setVisible(false);
    ui->ControlLabelBlue->setVisible(false);

    connect(&model,
            &Model::click,
            this,
            &View::startComputerBlink);
}

View::~View()
{
    delete ui;
}


void View::startComputerBlink(vector<string> colors)
{
    ui -> RedButton->setEnabled(false);
    ui->BlueButton->setEnabled(false);
    computerMoves = colors;
    computerIndex = 0;
    currentColor = computerMoves.at(computerIndex);
    QTimer::singleShot(gameSpeed, this, &View::computerPress);

}

void View::computerPress()
{

    if (currentColor == "Red")
    {
        ui->RedButton->setStyleSheet("background-color: rgb(255,150,150)");
    }
    else
    {
        ui->BlueButton->setStyleSheet("background-color: rgb(150,150,255)");
    }

    QTimer::singleShot(200, this, &View::computerRelease);
}

void View::computerRelease()
{
    if (currentColor == "Red")
    {
        ui->RedButton->setStyleSheet("background-color: rgb(200,50,50)");
    }
    else
    {
        ui->BlueButton->setStyleSheet("background-color: rgb(50,50,200)");
    }

    // Check if computer hasn't reached the end yet if there are more button presses to signal
    if (computerIndex != (int)computerMoves.size() - 1)
    {
        currentColor = computerMoves.at(++computerIndex);
        QTimer::singleShot(200, this, &View::computerPress);
    }
    else // give control back to player
    {
        // Red Color Set
        ui->RedButton->setStyleSheet( QString("QPushButton {background-color: rgb(200,50,50);} QPushButton:pressed {background-color: rgb(255,150,150);}"));

        // Blue Color Set
        ui->BlueButton->setStyleSheet( QString("QPushButton {background-color: rgb(50,50,200);} QPushButton:pressed {background-color: rgb(150,150,255);}"));

        ui -> RedButton->setEnabled(true);
        ui->BlueButton->setEnabled(true);
    }
}

void View::increaseGameSpeed(int speed){
    gameSpeed = speed;
}

void View::keyPressEvent(QKeyEvent* event)
{
    if (event->key() == Qt::Key_R || event->key() == Qt::Key_Left)
    {
        ui->RedButton->animateClick();
    }

    if (event->key() == Qt::Key_B || event->key() == Qt::Key_Right)
    {
        ui->BlueButton->animateClick();
    }
}

