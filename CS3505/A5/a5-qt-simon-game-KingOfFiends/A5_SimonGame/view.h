#ifndef VIEW_H
#define VIEW_H

#include <QMainWindow>
#include "model.h"

QT_BEGIN_NAMESPACE
namespace Ui { class View; }
QT_END_NAMESPACE

/*
CS 3505 - A5 - QT SimonGame
10/28/2022

Emile Goulard - u1244855
Michael Sullivan - u0794378

*/
class View : public QMainWindow
{
    Q_OBJECT

private:
    // These are here for the computer to make button "blinks" on the UI
    vector<string> computerMoves;
    string currentColor;
    int computerIndex;
    int gameSpeed;

public:
    View(Model& Model, QWidget *parent = nullptr);
    ~View();

    void computerPress();
    void computerRelease();

private:
    Ui::View *ui;

public slots:
    // Functions called for "blinking" pseduo button presses
    void startComputerBlink(std::vector<std::string> colors);
    void increaseGameSpeed(int speed);
    void keyPressEvent(QKeyEvent* event);

};
#endif // VIEW_H
