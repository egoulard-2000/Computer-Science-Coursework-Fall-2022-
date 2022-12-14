/*
// File name: framebutton.cpp
// Author:    Stefan
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
//      This is the source file that implements the framebutton class. Initializes the correct layout,
//      and a few helper functions.
*/


#include "framebutton.h"

using std::make_shared;


///
/// \brief Initializes a new framebutton, with three buttons arranged vertically in a layout.
///        Uses shared pointers so that copying and assigning works as intended.
///
FrameButton::FrameButton()
{
    centerButton = make_shared<QPushButton>();
    reorderButtonDown = make_shared<QPushButton>();
    reorderButtonUp = make_shared<QPushButton>();
    layoutFrame = make_shared<QVBoxLayout>();

    centerButton->setFixedSize(QSize(100, 100));

    // Creates a layout with up button, new frame button, and down button
    layoutFrame->setSpacing(0);

    reorderButtonUp->setFixedSize(QSize(100, 20));
    reorderButtonUp->setText("Move Up");

    reorderButtonDown->setFixedSize(QSize(100, 20));
    reorderButtonDown->setText("Move Down");

    layoutFrame->addWidget(reorderButtonUp.get());
    layoutFrame->addWidget(centerButton.get());
    layoutFrame->addWidget(reorderButtonDown.get());
}


///
/// \brief Returns pointer to top button
/// \return Pointer to button
///
QPushButton* FrameButton::getUpButton() const
{
    return reorderButtonUp.get();
}


///
/// \brief Returns pointer to bottom button
/// \return Pointer to button
///
QPushButton* FrameButton::getDownButton() const
{
    return reorderButtonDown.get();
}


///
/// \brief Returns pointer to center button
/// \return Pointer to button
///
QPushButton* FrameButton::getCenterButton() const
{
    return centerButton.get();
}


///
/// \brief Returns pointer to layout
/// \return Pointer to layout
///
QVBoxLayout* FrameButton::getLayout() const
{
    return layoutFrame.get();
}


///
/// \brief Sets the central button's icon to the input image
/// \param Image to set icon to
///
void FrameButton::setIcon(const QImage& image)
{
    QPixmap newFrame(QPixmap::fromImage(image));
    newFrame = newFrame.scaled(QSize(100, 100), Qt::KeepAspectRatio);
    QIcon buttonIcon(newFrame);

    centerButton->setIcon(buttonIcon);
    centerButton->setIconSize(QSize(100, 100));
}
