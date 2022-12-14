/*
// File name: view.h
// Author:    Stefan, Michael, Soli, Allen, and Emile
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
//      This is the header file for view.cpp containing all the fields, methods, signals, and slots.
*/

#ifndef VIEW_H
#define VIEW_H

#include "framebutton.h"
#include "model.h"
#include "previewwindow.h"
#include <QColorDialog>
#include <QFile>
#include <QMainWindow>
#include <QFileDialog>
#include <QIODevice>
#include <QInputDialog>
#include <QMessageBox>

QT_BEGIN_NAMESPACE

namespace Ui
{
class View;
}

QT_END_NAMESPACE


///
/// \brief The View class that provides the view for a SpriteEditor program
///
class View : public QMainWindow
{
    Q_OBJECT

  public:
    ///
    /// \brief  Constructor for the view class, makes all necessary connections with
    ///         model and UI.
    /// \param  model to connect to for logic
    /// \param  parent widget to be attached to
    ///
    View(Model& model, QWidget* parent = nullptr);

    ///
    /// \brief Destructor for view
    ///
    ~View();

  signals:
    /// \brief  Signal that requests a change to working frame (what's displayed). Requests the specified frame from the model
    void changeWorkingFrame(int frameIndex);

    /// \brief Requests previous frame from model
    void getPreviousFrame();

    /// \brief Requests next frame from model
    void getNextFrame();

    /// \brief Gets a frame at frameIndex from model
    void getCurrentFrame(const int frameIndex);

    /// \brief Swaps frames between 2 indices
    void swapFrames(int frameIndexOne, int frameIndexTwo);

    /// \brief Sets the grid setting
    void setGrid(bool setting);

    /// \brief  Signal that requests to the model to change the pixel at point on the frame
    ///         at frameIndex. The color is stored by the model, so it is not sent.
    void setImagePixel(const QPoint& point, bool mousePressed);

    /// \brief Requests model to save animation to file
    void saveToFile(QFile& fileName);

    /// \brief Requests model to load animation from file
    void loadfromFile(QFile& fileName);

    /// \brief Updates the color the model is using to draw
    void updateModelColor(const QColor newColor);

    /// \brief Creates a new animation with specified dimensions
    void getNewAnimation(const int width, const int height);

  private slots:
    ///
    /// \brief View::updateCanvas   Slot setting the graphicsDrawView's image to the currentWorkingImage
    /// \param newWorkingImage      New image to set canvas to
    /// \param currentIndex         What the index of that image is in the animation
    ///
    void updateCanvas(const QImage& newWorkingImage, const int currentFrame);

    ///
    /// \brief View::getToolPos     Gets the position of a user's mouse on the canvas, and emits the signal to the model to draw
    /// \param pos                  Mouse's position in pixels
    /// \param mousePressed         If the mouse was pressed
    ///
    void getToolPos(const QPoint& pos, bool mousePressed);

    ///
    /// \brief View::updateCurrentPos
    /// \param  New mouse position
    /// This method uses the position of the mouse when its clicked
    /// to update the bottom info bar with information about where the mouse is,
    /// as well as updating what color is currently being used by the user to draw the sprites.
    ///
    void updateCurrentPos(const QPoint& pos);

    ///
    /// \brief View::getSaveFileName    Opens file dialog to get fileName to save to
    ///
    void getSaveFileName();

    ///
    /// \brief View::getLoadFileName    Opens file dialog to get fileName to load from
    ///
    void getLoadFileName();

    ///
    /// \brief View::onChooseColorButtonPressed
    ///                     Allows the user to update their currently selected color.
    ///                     (this is triggered by the chooseColorButton)
    ///
    void onChooseColorButtonPressed();

    ///
    /// \brief Creates a new framebutton for the right animation bar
    ///
    void createNewButton();

    ///
    /// \brief Sets a framebutton's image
    /// \param image to use in the frame
    /// \param index in the animation to set
    ///
    void setButtonImage(const QImage& frameImage, int index);

    ///
    /// \brief Displays errors from the model
    void displayError(const QString& errorMessage);

    ///
    /// \brief Gets user input for new animation, then requests it from model
    ///
    void processNewAnimation();

    ///
    /// \brief Shows the preview window with the animation.
    ///
    void showPreviewWindow();

    ///
    /// \brief  Method that communicates with the canvas
    ///         graphics view to toggle on or off a grid
    /// \param  Whether to toggle on or off
    ///
    void showGrid(bool toggled);

    ///
    /// \brief Slot attached to new framebuttons in animation bar to swap locations up
    ///
    void moveFrameUp();

    ///
    /// \brief Slot attached to new framebuttons in animation bar to swap locations down
    ///
    void moveFrameDown();

    ///
    /// \brief View::deleteFrameButton  Method called when remove frame button is pressed
    ///
    void deleteFrameButton();

    ///
    /// \brief View::switchToFrame
    ///                     Allows the user to switch directly to the frame
    ///                     being clicked on in the right scroll area
    ///
    void switchToClickedFrame();

    ///
    /// \brief View::bulkRefreshFrames  Updates all the displayed frames in the right animation bar
    /// \param newFrames                The new frames to display
    ///
    void bulkRefreshFrames(const QVector<QImage> newFrames);

    ///
    /// \brief View::successfulLoad     Slot that processes when the model has successfully loaded an animation.
    /// \param animationIsEmpty         Check if the animation contains any frames or not
    /// \param fileName                 Name of the file load
    ///
    void successfulLoad(bool animationIsEmpty, const QString fileName);

    ///
    /// \brief View::processSave    Slot that processes the save button press, not save as
    ///
    void processSave();

    ///
    /// \brief View::showHelpMenu   Shows help menu
    ///
    void showHelpMenu();

    ///
    /// \brief View::setCursorIconPen   Sets the mouse cursor icon to the pen tool icon
    ///
    void setCursorIconPen();

    ///
    /// \brief View::setCursorIconEraser    Sets the mouse cursor icon to the eraser tool icon
    ///
    void setCursorIconEraser();

    ///
    /// \brief View::setCursorIconClearCanvas   Sets the mouse cursor icon to the clear canvas tool icon
    ///
    void setCursorIconClearCanvas();

    ///
    /// \brief View::setCursorIconBucketFill    Sets the mouse cursor icon to the bucket fill tool icon
    ///
    void setCursorIconBucketFill();

    ///
    /// \brief View::setCursorIconTint      Sets the mouse cursor icon to the tint tool icon
    ///
    void setCursorIconTint();

    ///
    /// \brief View::setCursorIconShade     Sets the mouse cursor icon to the shade tool icon
    ///
    void setCursorIconShade();

  private:
    ///
    /// \brief View::updateWindowTitle  Updates window title with a fileName, if empty, just sets it as SpriteEditor
    /// \param fileName                 Name of the file to be saved with
    ///
    void updateWindowTitle(const QString& fileName);

    Ui::View* ui;
    PreviewWindow preview;
    int currentFrameIndex;
    QVector<FrameButton> frameButtons;
    QString lastSavedFileName = "";
};
#endif // VIEW_H
