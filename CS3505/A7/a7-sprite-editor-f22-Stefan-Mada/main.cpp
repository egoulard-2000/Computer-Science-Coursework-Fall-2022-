/*
// File name: main.cpp
// Author:    Stefan, Michael, Soli, Allen, and Emile
// Assignment:Sprite Editor
// Group:     AKPSE
// Date:      11/15/2022
// Course:    CS 3505, University of Utah, School of Computing
// Copyright: CS 3505 and AKPSE - This work may not be copied for use in Academic Coursework.
//
// Our group, AKPSE, certifies that we wrote this code from scratch and did not copy it in part or whole from
// another source.
//
// File Contents
//
//      This is the file where the program runs from.
*/

#include "model.h"
#include "view.h"

#include <QApplication>

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);
    Model model;
    View w(model);
    w.show();
    return a.exec();
}
