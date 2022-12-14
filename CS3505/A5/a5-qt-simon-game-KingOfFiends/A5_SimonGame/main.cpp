#include "view.h"

#include <QApplication>
#include "model.h"

/*
CS 3505 - A5 - QT SimonGame
10/28/2022

Emile Goulard - u1244855
Michael Sullivan - u0794378

*/
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Model model;
    View w(model);
    w.show();
    return a.exec();
}
