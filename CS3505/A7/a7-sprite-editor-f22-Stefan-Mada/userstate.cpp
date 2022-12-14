/*
// File name: userstate.cpp
// Author:    Stefan, Emile, Allen, and Soli
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
//      This is the source file for holding and updating information about the current settings
//      the project is on such as tools and color.
*/

#include "userstate.h"

///
/// \brief UserState::UserState     Default constructor for UserState
///
UserState::UserState()
{
}


///
/// \brief UserState::useCurrentTool    Use of the current tool detected as one move
/// \param animation                    The set of frames in current project
/// \param point                        The pixel point where the mouse sent an event
/// \param frameIndex                   Current animation frame's index
/// \param mousePressed                 If the mouse button is pressed
///
void UserState::useCurrentTool(Animation& animation, const QPoint& point, const int frameIndex, bool mousePressed)
{
    bool saveHistory = DrawingTools::useCurrentTool(animation, point, frameIndex, currentColor, mousePressed);

    if (saveHistory)
    {
        emit saveCurrentAnimation();
    }
}


///
/// \brief UserState::setPenTool    Sets the current tool to the pen tool
///
void UserState::setPenTool()
{
    DrawingTools::currentTool = DrawingTools::PEN;
}


///
/// \brief UserState::setEraserTool Sets the current tool to the eraser tool
///
void UserState::setEraserTool()
{
    DrawingTools::currentTool = DrawingTools::ERASER;
}


///
/// \brief UserState::setClearCanvasTool    Sets the current tool to the clear canvas tool
///
void UserState::setClearCanvasTool()
{
    DrawingTools::currentTool = DrawingTools::CLEAR_CANVAS;
}


///
/// \brief UserState::setBucketFillTool Sets the current tool to the bucket fill tool
///
void UserState::setBucketFillTool()
{
    DrawingTools::currentTool = DrawingTools::BUCKET_FILL;
}


///
/// \brief UserState::setTintTool   Sets the current tool to the tint tool
///
void UserState::setTintTool()
{
    DrawingTools::currentTool = DrawingTools::TINT;
}


///
/// \brief UserState::setShadeTool  Sets the current tool to the shade tool
///
void UserState::setShadeTool()
{
    DrawingTools::currentTool = DrawingTools::SHADE;
}


///
/// \brief UserState::setColor  Sets the color to be used by the various drawing tools
/// \param newColor             The new color to be stored
///
void UserState::setColor(const QColor newColor)
{
    currentColor = newColor;
}
