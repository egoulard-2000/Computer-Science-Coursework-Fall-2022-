/*
// File name: graphicsdrawview.cpp
// Author:    Stefan, Allen, and Michael
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
//      This is the source file that implements from the graphicsdrawview class. It contains
//      all the components necessary for handling drawing on the main canvas and updating
//      the canvas with that updated drawing in real time.
*/


#include "graphicsdrawview.h"
#include <QMouseEvent>


///
/// \brief Handle when the mouse has moved while interacting with the main canvas
/// \param the mouse event to handle
///
void GraphicsDrawView::mouseMoveEvent(QMouseEvent* event)
{
    emitMouseImagePosition(event, true);
}


///
/// \brief Handle when the mouse has began interacting with the main canvas
/// \param the mouse event to handle
///
void GraphicsDrawView::mousePressEvent(QMouseEvent* event)
{
    emitMouseImagePosition(event, true);
}


///
/// \brief Handle when the mouse has stopped interacting with the main canvas
/// \param the mouse event to handle
///
void GraphicsDrawView::mouseReleaseEvent(QMouseEvent* event)
{
    emitMouseImagePosition(event, false);
}


///
/// \brief This slot handles where the mouse's position is on the main canvas.
/// \param the mouse event to handle
/// \param is the mouse is pressed or not
///
/// \details This method will speak with the bottom info bar in the view class.
///          It simply takes in a point on the mapped scene and updates the info bar
///          with x and y coordinates of the mouse. This will be helpful for also
///          placing pixels on the canvas at said position.
///
void GraphicsDrawView::emitMouseImagePosition(QMouseEvent* event, bool mousePressed)
{
    // Must have a frame to update at all times
    if (currentCanvasImage == nullptr)
        return;

    // Calculate the pixel the mouse is currenty hovering over
    const QPointF posFloat = mapToScene(event->pos());
    const QPoint pos((int)posFloat.x(), (int)posFloat.y());

    // If the current pixel remains unchanged, don't emit any signal
    if (mousePressed && currMousePixel == pos)
        return;

    currMousePixel = pos;

    emit getMouseImagePosition(pos, mousePressed);
}


///
/// \brief Draws the specified image to the graphics draw view.
/// \param the image to draw on
///
void GraphicsDrawView::drawImage(const QImage& image)
{
    currentCanvasImage = &image;
    updateView();
}


///
/// \brief Grabs the image of a given frame
/// \return the current canvas chosen
///
const QImage* GraphicsDrawView::getImage()
{
    return currentCanvasImage;
}

///
/// \brief Sets whether the grid is turned on or not.
/// \param setting
///
void GraphicsDrawView::setGrid(bool setting)
{
    gridOn = setting;
}


///
/// \brief Sends an update when the widget is resized on the main canvas
/// \param QResizeEvent pointer to send
///
void GraphicsDrawView::resizeEvent(QResizeEvent*)
{
    updateView();
}


///
/// \brief Sends an update when the widget is shown on the main canvas
/// \param QShowEvent pointer to send
///
void GraphicsDrawView::showEvent(QShowEvent*)
{
    updateView();
}


///
/// \brief update the main canvas view and also ensure the aspect ratio is maintained
///
/// \details For any given frame, set the scene and fit into view.
///          This method currently handles pixels being added to the screen using pixmaps with the graphics draw scene.
///          It also shows the gridlines in real time.
///
void GraphicsDrawView::updateView()
{
    // Must have a frame to update at all times
    if (currentCanvasImage == nullptr)
        return;

    auto scene = new QGraphicsScene(this);
    scene->setSceneRect(currentCanvasImage->rect());
    scene->addPixmap(QPixmap::fromImage(*currentCanvasImage));

    if (gridOn)
    {
        // These two for loops are used to draw the grid lines across each pixel's location within the image.
        for(int x = 0; x <= scene->width() - 1; x++)
            scene->addLine(x, 0, x, scene->width(), QPen(Qt::black, 0, Qt::DashLine, Qt::RoundCap));

        for(int y = 0; y <= scene->height(); y++)
            scene->addLine(0, y, scene->height(), y, QPen(Qt::black, 0, Qt::DashLine, Qt::RoundCap));
    }
    else
    {
        // These two for loops are used to draw the grid lines across each pixel's location within the image.
        for(int x = 0; x <= scene->width() - 1; x++)
            scene->addLine(x, 0, x, scene->width(), QPen(Qt::transparent, 0, Qt::DashLine, Qt::RoundCap));

        for(int y = 0; y <= scene->height(); y++)
            scene->addLine(0, y, scene->height(), y, QPen(Qt::transparent, 0, Qt::DashLine, Qt::RoundCap));
    }

    setScene(scene);
    fitInView(scene->sceneRect(), Qt::AspectRatioMode::KeepAspectRatio);
}
