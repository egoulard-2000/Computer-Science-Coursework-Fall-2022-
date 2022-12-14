/*
// File name: drawingtools.cpp
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
//      This is the source file that implements the drawingtools class. This class encapsulates the functionality of various
//      tools in the Sprite Editor. Generally, external classes can call useCurrentTool(),
//      and get a new Animation class that's been edited correctly.
*/


#include "drawingtools.h"

using std::queue;
using std::vector;


/// \brief default current tool is pen tool
DrawingTools::Tool DrawingTools::currentTool = DrawingTools::PEN;


///
/// \brief DrawingTools::useCurrentTool     Updates the Animation based on the currently used tool
/// \param animation                        The The Animation to update
/// \param point                            The point on the image that the tool was used on.
/// \param frameIndex                       The current frame in Animation that's being edited.
/// \param color                            The color of the tool.
/// \param mousePressed                     Whether the mouse was pressed, or released
/// \return bool                            True if the image is ready to save to history, false otherwise.
///
bool DrawingTools::useCurrentTool(Animation& animation, const QPoint& point, const int frameIndex, const QColor& color,
                                  const bool mousePressed)
{
    // The previous color of the pixel we're editing.
    const QColor prevColor = animation.getFrame(frameIndex).pixelColor(point);

    // The color amount difference.
    const int lightColorDifference = 115;

    // Go through an enum to determine what tool we're usibg.
    switch (currentTool)
    {
    case PEN:
        animation.changePixelColor(frameIndex, point, color);
        return !mousePressed; // Save when mouse is released.

    case ERASER:
        animation.changePixelColor(frameIndex, point, QColor(0, 0, 0, 0));
        return !mousePressed; // Save when mouse is released.

    case CLEAR_CANVAS:
        animation.clearFrame(frameIndex);
        return !mousePressed; // Save when mouse is released.

    case BUCKET_FILL:
        bucketFill(animation, point, frameIndex, color);
        return !mousePressed; // Save when mouse is released.
    case TINT:
        if (prevColor.alpha() != 0 && mousePressed)
        {
            animation.changePixelColor(
                frameIndex, point,
                (QColor(prevColor.red() + 1, prevColor.green() + 1, prevColor.blue() + 1)).lighter(lightColorDifference));
        }
        return !mousePressed; // Save when mouse is released.
    case SHADE:
        if (mousePressed)
        {
            animation.changePixelColor(frameIndex, point, prevColor.darker(lightColorDifference));
        }
        return !mousePressed; // Save when mouse is released.
    default:
        throw std::invalid_argument("Tool type does not exist in drawingtools.cpp");
        return false;
    }
}


///
/// \brief DrawingTools::bucketFill     Updates the Animation by performing a bucket fill on it.
/// \param animation                    The The Animation to update
/// \param point                        The point on the image that the tool was used on.
/// \param frameIndex                   The current frame in Animation that's being edited.
/// \param color                        The color of the tool.
/// \param mousePressed                 Whether the mouse was pressed, or released
/// \return bool                        True if the image is ready to save to history, false otherwise.
///
void DrawingTools::bucketFill(Animation& animation, const QPoint& point, const int frameIndex, const QColor& color)
{
    const int width = animation.width();
    const int height = animation.height();

    // first, ensure user has clicked inside the bounds
    // inside own scope to keep xPos and yPos from propagating
    {
        const auto& [xPos, yPos] = point;
        if (xPos < 0 || yPos < 0 || xPos >= width || yPos >= height)
            return;
    }

    // must store the color at point, as this is the color that will be filled
    const QColor prevColor = animation.getFrame(frameIndex).pixelColor(point);

    // if colors are the same, no filling will be done, so return
    if (color == prevColor)
        return;

    // then, create a vector to track what squares have been visited
    // initialized to false, as nothing visited just yet
    // Important that first index is xPos, second is yPos
    vector<vector<bool>> visited(width, vector<bool>(height, false));

    // will use BFS, so need a queue
    queue<QPoint> bfsQueue;

    // Add the passed in point to the queue, and set it as visited, and change its color
    bfsQueue.push(point);
    visited[point.x()][point.y()] = true;
    animation.changePixelColor(frameIndex, point, color);

    // This vector stores all possible directions that a BFS can traverse adjacent to one another
    // So first, you can go (-1, 0) to go up 1, then (0, 1) to go right 1, etc.
    const vector<int> directions = {-1, 0, 1, 0, -1};

    while (!bfsQueue.empty())
    {
        const QPoint currentPoint = bfsQueue.front();
        const auto& [xPos, yPos] = currentPoint;
        bfsQueue.pop();

        for (int direction = 0; direction < 4; ++direction)
        {
            const int newX = xPos + directions[direction];
            const int newY = yPos + directions[direction + 1];

            // if the point is valid and not visited
            if (newX >= 0 && newY >= 0 && newX < width && newY < height && !visited[newX][newY])
            {
                // one more check to see if the color is equal to prevColor
                const QPoint pointHere(newX, newY);
                const QColor colorHere = animation.getFrame(frameIndex).pixelColor(pointHere);

                if (colorHere != prevColor)
                    continue;

                // if the color matches prevColor, this is a valid place to fill in, so add to queue, visit it, and
                // color it
                visited[newX][newY] = true;
                bfsQueue.push(pointHere);
                animation.changePixelColor(frameIndex, pointHere, color);
            }
        }
    }
}
