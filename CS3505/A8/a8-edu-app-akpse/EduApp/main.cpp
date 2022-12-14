/*
// File name: main.cpp
// Author:    Emile, Soli, Stefan, Michal
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
//      This file implements main.cpp, which is the entrypoint for this chess program.
//      Defines a model and view using that model, then executes this program.
*/

#include "view.h"

#include <QApplication>
#include <QStyleFactory>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setStyle(QStyleFactory::create("Fusion"));
    Model model;
    View w(model);
    w.show();
    return a.exec();
}
