/*
// File name: graphicsdrawview.h
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
//      This is the header file that defines the graphicsdrawview class. It contains
//      all the components necessary for handling drawing on the main canvas and updating
//      the canvas with that updated drawing in real time.
*/


#ifndef GRAPHICSDRAWVIEW_H
#define GRAPHICSDRAWVIEW_H

#include <QGraphicsView>


///
/// \brief The GraphicsDrawView class, provides special functionality to QGraphicsView
///
class GraphicsDrawView : public QGraphicsView
{
    Q_OBJECT

  public:
    using QGraphicsView::QGraphicsView;

    ///
    /// \brief Draws the specified image to the graphics draw view.
    /// \param the image to draw on
    void drawImage(const QImage& image);

    ///
    /// \brief Grabs the image of a given frame
    /// \return the current canvas chosen
    ///
    const QImage* getImage();

    ///
    /// \brief Sets whether the grid is turned on or not.
    /// \param setting
    ///
    void setGrid(bool setting);

  signals:
    /// \brief The mouse position in relation ONLY to the main canvas
    void getMouseImagePosition(const QPoint& point, bool mousePressed);

  private:
    /// \brief A pointer to constant QImage, images can change (switching frames), but this class should never directly modify an image.
    const QImage* currentCanvasImage = nullptr;
    bool gridOn;

    /// \details Default to out-of-bounds until updated
    QPoint currMousePixel = QPoint(-1, -1);

    ///
    /// \brief Handle when the mouse has moved while interacting with the main canvas
    /// \param the mouse event to handle
    ///
    void mouseMoveEvent(QMouseEvent* event) override;

    ///
    /// \brief Handle when the mouse has began interacting with the main canvas
    /// \param the mouse event to handle
    ///
    void mousePressEvent(QMouseEvent* event) override;

    ///
    /// \brief Handle when the mouse has stopped interacting with the main canvas
    /// \param the mouse event to handle
    ///
    void mouseReleaseEvent(QMouseEvent* event) override;

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
    void emitMouseImagePosition(QMouseEvent* event, bool mousePressed);

    ///
    /// \brief update the main canvas view and also ensure the aspect ratio is maintained
    ///
    /// \details For any given frame, set the scene and fit into view.
    ///          This method currently handles pixels being added to the screen using pixmaps with the graphics draw scene.
    ///          It also shows the gridlines in real time.
    void updateView();

    ///
    /// \brief Sends an update when the widget is resized on the main canvas
    /// \param QResizeEvent pointer to send
    void resizeEvent(QResizeEvent*) override;

    ///
    /// \brief Sends an update when the widget is shown on the main canvas
    /// \param QShowEvent pointer to send
    ///
    void showEvent(QShowEvent*) override;

};

#endif // GRAPHICSDRAWVIEW_H
