/*
// File name: previewwindow.h
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
//      This is the header file that defines the previewwindow class. It contains
//      all the components necessary for handling running the animation in a separate window
//      and having the same updated parameters of the current animation
*/


#ifndef PREVIEWWINDOW_H
#define PREVIEWWINDOW_H

#include "animation.h"
#include <QDialog>


namespace Ui
{
class PreviewWindow;
}


///
/// \brief Pop out window to display animation enlarged and in true pixel size.
///
class PreviewWindow : public QDialog
{
    Q_OBJECT

  public:
    ///
    /// \brief Preview Window constructor that sets up connections for user interface
    /// \param QWidget* parent
    ///
    explicit PreviewWindow(QWidget* parent = nullptr);

    ///
    /// \brief Destructor for preview window
    ///
    ~PreviewWindow();

  public slots:

    ///
    /// \brief update the canvas that displays the animation in the preview window
    /// \param the new preview image being updated from the original main canvas
    ///
    void updateCanvas(const QImage& newPreviewImage);

    ///
    /// \brief Adjust the size of the animation/frame through toggling the
    ///        the checkbox in the previewwindow ui
    ///
    void adjustActualSize();

  private:
    Ui::PreviewWindow* ui;

    /// \brief Needed animation class for previewing real time frames
    Animation animation;
};

#endif // PREVIEWWINDOW_H
