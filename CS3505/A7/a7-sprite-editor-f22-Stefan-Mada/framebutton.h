/*
// File name: framebutton.h
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
//      This is the header file that defines the FrameButton class. This class is used to display
//      frames on the right side of view, allowing users to preview frames. It is composed of 3 buttons
//      in a layout.
*/

#ifndef FRAMEBUTTON_H
#define FRAMEBUTTON_H

#include <QPushButton>
#include <QVBoxLayout>

using std::shared_ptr;


///
/// \brief The FrameButton class. This class is used to display
///        frames on the right side of view, allowing users to preview frames. It is composed of 3 buttons
///        in a layout.
///
class FrameButton
{
  public:
    ///
    /// \brief Initializes a new framebutton, with three buttons arranged vertically in a layout.
    ///
    FrameButton();

    ///
    /// \brief Returns pointer to top button
    /// \return Pointer to button
    ///
    QPushButton* getUpButton() const;

    ///
    /// \brief Returns pointer to bottom button
    /// \return Pointer to button
    ///
    QPushButton* getDownButton() const;

    ///
    /// \brief Returns pointer to center button
    /// \return Pointer to button
    ///
    QPushButton* getCenterButton() const;

    ///
    /// \brief Returns pointer to layout
    /// \return Pointer to layout
    ///
    QVBoxLayout* getLayout() const;

    ///
    /// \brief Sets the central button's icon to the input image
    /// \param Image to set icon to
    ///
    void setIcon(const QImage& image);

  private:
    // These are shared pointers, so that copying and assigning works
    // without creating memory leaks.

    shared_ptr<QPushButton> centerButton;
    shared_ptr<QVBoxLayout> layoutFrame;
    shared_ptr<QPushButton> reorderButtonUp;
    shared_ptr<QPushButton> reorderButtonDown;
};

#endif // FRAMEBUTTON_H
