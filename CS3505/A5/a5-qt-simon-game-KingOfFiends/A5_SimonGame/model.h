#ifndef MODEL_H
#define MODEL_H

#include <QObject>
#include <QTimer>
#include <QThread>
#include <QString>

using namespace std;

/*
CS 3505 - A5 - QT SimonGame
10/28/2022

Emile Goulard - u1244855
Michael Sullivan - u0794378

*/
class Model : public QObject
{
    Q_OBJECT

private:
    vector<string> playerMoves;
    vector<string> computerMoves;

    bool isPlayerTurn;
    int moveCounter;
    int playerIndex;
    int gameTime;
    double playerProgress;
    int computerIndex;

    int currentScore;
    int highScore;

public:
    explicit Model(QObject *parent = nullptr);
    void printVector();

public slots:
        void startGame();
        void gameMoves();
        void endMoves();
        void isPlayerCorrect(int index);
        void redButtonClicked();
        void blueButtonClicked();

signals:
        void showHighScore(bool isVisible);
        void showProgressBar(bool isVisible);
        void showSimonButtons(bool isVisible);
        void showLoseScreen(bool isVisible);
        void showStartButton(bool isVisible);
        void showInstructions(bool isVisible);
        void updateHighScore(QString val);
        void progressChanged(double playerProgress);
        void increaseGameSpeed(int gameTime);
        void click(std::vector<std::string> colors);

};

#endif // MODEL_H
