/*
// File name: drawingtools.h
// Author:    Allen Shumway, Stefan
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
//      This is the header file for drawingtools class, which uses specific
//      tools on an animation frame. Please see the .cpp file for more details.
*/


#ifndef DRAWINGTOOLS_H
#define DRAWINGTOOLS_H

#include "animation.h"
#include <QObject>
#include <queue>
#include <vector>

///
/// \brief Class that defines and stores the tools used for drawing
///
class DrawingTools
{

  public:
    /// \brief A public enum that allows external code what tool we would like to use.
    enum Tool
    {
        PEN,
        ERASER,
        CLEAR_CANVAS,
        BUCKET_FILL,
        TINT,
        SHADE
    };

    /// \brief Tool currently in use
    static Tool currentTool;

    ///
    /// \brief DrawingTools::useCurrentTool     Updates the Animation based on the currently used tool
    /// \param animation                        The The Animation to update
    /// \param point                            The point on the image that the tool was used on.
    /// \param frameIndex                       The current frame in Animation that's being edited.
    /// \param color                            The color of the tool.
    /// \param mousePressed                     Whether the mouse was pressed, or released
    /// \return bool                            True if the image is ready to save to history, false otherwise.
    ///
    static bool useCurrentTool(Animation& animation, const QPoint& point, const int frameIndex, const QColor& color,
                               const bool mousePressed);

  private:
    ///
    /// \brief DrawingTools::bucketFill     Updates the Animation by performing a bucket fill on it.
    /// \param animation                    The The Animation to update
    /// \param point                        The point on the image that the tool was used on.
    /// \param frameIndex                   The current frame in Animation that's being edited.
    /// \param color                        The color of the tool.
    /// \param mousePressed                 Whether the mouse was pressed, or released
    /// \return bool                        True if the image is ready to save to history, false otherwise.
    ///
    static void bucketFill(Animation& animation, const QPoint& point, const int frameIndex, const QColor& color);
};

#endif // DRAWINGTOOLS_H
