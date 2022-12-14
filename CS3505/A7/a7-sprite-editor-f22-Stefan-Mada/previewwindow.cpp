/*
// File name: previewwindow.cpp
// Author:    Emile
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
//      This is the source file that implements the previewwindow class. It contains
//      all the components necessary for handling running the animation in a separate window
//      and having the same updated parameters of the current animation
*/

#include "previewwindow.h"
#include "graphicsdrawview.h"
#include "ui_previewwindow.h"


///
/// \brief Preview Window constructor that sets up connections for user interface
/// \param QWidget* parent
///
PreviewWindow::PreviewWindow(QWidget* parent)
    : QDialog(parent), ui(new Ui::PreviewWindow), animation(QImage(":images/tester.png"))
{
    ui->setupUi(this);

    setWindowTitle("Preview Sprite");

    // Connect the adjust size checkbox to call adjust actual size
    connect(ui->actualSizeCheckbox, &QCheckBox::toggled, this, &PreviewWindow::adjustActualSize);
}


///
/// \brief update the canvas that displays the animation in the preview window
/// \param the new preview image being updated from the original main canvas
///
void PreviewWindow::updateCanvas(const QImage& newPreviewImage)
{
    ui->graphicsView->drawImage(newPreviewImage);
    ui->graphicsView->setGrid(false);
}


///
/// \brief Adjust the size of the animation/frame through toggling the
///        the checkbox in the previewwindow ui
///
void PreviewWindow::adjustActualSize()
{
    const bool toggled = ui->actualSizeCheckbox->isChecked();

    if (toggled)
    {
        ui->graphicsView->setMaximumWidth(animation.width());
        ui->graphicsView->setMaximumHeight(animation.height());
    }
    else
    {
        ui->graphicsView->setMaximumWidth(this->width());
        ui->graphicsView->setMaximumHeight(this->height());
    }
}


///
/// \brief Destructor for preview window
///
PreviewWindow::~PreviewWindow()
{
    delete ui;
}
