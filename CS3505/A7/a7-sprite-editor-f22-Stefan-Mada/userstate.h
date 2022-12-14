/*
// File name: userstate.h
// Author:    Stefan, Michael, Emile, Allen, and Soli
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
//      This is the header file for userstate.cpp that contains the methods, fields, signal, and slots.
*/


#ifndef USERSTATE_H
#define USERSTATE_H

#include "drawingtools.h"


///
/// \brief UserState class, keeps track of current tool and color being used
///
class UserState : public QObject
{
    Q_OBJECT

  public:

    ///
    /// \brief UserState::UserState     Default constructor for UserState
    ///
    UserState();


  signals:
    /// \brief Emitted to save animation for undo/redo
    void saveCurrentAnimation();

  public slots:
    ///
    /// \brief UserState::useCurrentTool    Use of the current tool detected as one move
    /// \param animation                    The set of frames in current project
    /// \param point                        The pixel point where the mouse sent an event
    /// \param frameIndex                   Current animation frame's index
    /// \param mousePressed                 If the mouse button is pressed
    ///
    void useCurrentTool(Animation& animation, const QPoint& point, const int frameIndex, bool mousePressed);

    ///
    /// \brief UserState::setPenTool    Sets the current tool to the pen tool
    ///
    void setPenTool();

    ///
    /// \brief UserState::setEraserTool Sets the current tool to the eraser tool
    ///
    void setEraserTool();

    ///
    /// \brief UserState::setClearCanvasTool    Sets the current tool to the clear canvas tool
    ///
    void setClearCanvasTool();

    ///
    /// \brief UserState::setBucketFillTool Sets the current tool to the bucket fill tool
    ///
    void setBucketFillTool();

    ///
    /// \brief UserState::setTintTool   Sets the current tool to the tint tool
    ///
    void setTintTool();

    ///
    /// \brief UserState::setShadeTool  Sets the current tool to the shade tool
    ///
    void setShadeTool();

    ///
    /// \brief UserState::setColor  Sets the color to be used by the various drawing tools
    /// \param newColor             The new color to be stored
    ///
    void setColor(const QColor color);

private:
    DrawingTools::Tool currentTool;
    QColor currentColor = QColorConstants::Black; // default color is black
                                                  // Animation currentFrame;
};

#endif // USERSTATE_H
