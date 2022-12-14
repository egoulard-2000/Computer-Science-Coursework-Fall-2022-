/*
// File name: model.h
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
//      This is the header file for model.cpp containing all the fields, methods, signals, and slots.
*/


#ifndef MODEL_H
#define MODEL_H

#include "animation.h"
#include "userhistory.h"
#include "userstate.h"
#include <QColor>
#include <QFile>
#include <QObject>
#include <QTimeLine>


///
/// \brief Implements all signals and slots for interacting with a sprite editor view.
///
class Model : public QObject
{
    Q_OBJECT
  public:

    ///
    /// \brief Initializes the animationTimeLine and connections of the model.
    /// \param parent object to be tied to
    ///
    explicit Model(QObject* parent = nullptr);

  signals:
    /// \brief Signal is sent to view to update displayed color
    void changeColor(const QColor);

    /// \brief  Signal is sent to the view to change the image being viewed
    ///         is a constant reference because view can never modify it directly
    void updateCanvas(const QImage& currentWorkingImage, const int currentFrame);

    /// \brief Update the right animation bar entirely
    void bulkUpdateAnimation(const QVector<QImage> newFrames);

    /// \brief Signal that sends an error message for view to display
    void sendErrorMessage(const QString& message);

    /// \brief  This signal is sent when a file is successfully loaded
    ///         Basically tells the view that it's good to clear its frameButtons vector
    void successfulLoad(bool animationIsEmpty, const QString fileName);

  public slots:

    ///
    /// \brief Slot that processes the view requesting a change of frame.
    ///        Does not change the frame if requested frame does not exist.
    /// \param frame index requested
    void requestedFrameChange(const int frameIndex);

    ///
    /// \brief  Model::requestedNextFrame
    ///         Slot that is called when the user wants to move to the next frame from where they are.
    ///
    void requestedNextFrame();

    ///
    /// \brief  Model::requestedPreviousFrame
    ///         Slot that is called when the user wants to move back from the current frame they are on.
    ///
    void requestedPreviousFrame();

    ///
    /// \brief Slot that handles adding a new frame to the animation
    ///
    void addFrame();

    ///
    /// \brief Slot that handles removing a new frame from the animation
    void removeFrame();

    ///
    /// \brief Slot that handles swapping frames
    ///        If currently viewing one of the swapped frames,
    ///        you will still view that image after the swap.
    ///        Otherwise, you stay at the same frame you were on before
    ///
    void swapFrames(const int frameIndexOne, const int frameIndexTwo);

    ///
    /// \brief  Model::toggleAnimationPlayback
    ///         This is the slot that is used when the user would like the animation of multiple frames
    ///         to be displayed.
    ///
    void toggleAnimationPlayback();

    ///
    /// \brief Slot that takes in FPS number from UI and adjusts timeline as necessary
    /// \param fps to set to
    void updateFPS(int fps);

    ///
    /// \brief  Model::setPenTool
    ///         Slot that updates current tool being used to the pen.
    ///
    void setPenTool();

    ///
    /// \brief  Model::setEraserTool
    ///         Slot that updates current tool being used to the eraser.
    ///
    void setEraserTool();

    ///
    /// \brief  Model::setClearCanvasTool
    ///         Slot that updates current tool being used to clear canvas.
    ///
    void setClearCanvasTool();

    ///
    /// \brief  Model::setBucketFillTool
    ///         Slot that updates current tool being used to bucket fill.
    ///
    void setBucketFillTool();

    ///
    /// \brief  Model::setTintTool
    ///         Slot that updates current tool being used to tinting tool.
    ///
    void setTintTool();

    ///
    /// \brief  Model::setShadeTool
    ///         Slot that updates current tool being used to shading tool.
    ///
    void setShadeTool();

    ///
    /// \brief Uses the current tool, has checks to ensure the frame actually exists
    /// \param point to use tool on
    /// \param mousePressed true if mouse was pressed
    ///
    void useCurrentTool(const QPoint& point, bool mousePressed);

    ///
    /// \brief  This slot is used when the user wants to save to a file
    /// \param  file to save to
    ///
    void saveToFile(QFile& file);

    ///
    /// \brief This slot is used when the user wants to load in a file
    /// \param file to load from
    ///
    void loadFromFile(QFile& file);

    ///
    /// \brief Model::updateStoredColor     Updates the color used by the drawing tools
    /// \param newColor                     The new color to store
    ///
    void updateStoredColor(QColor newColor);

    ///
    /// \brief  When view clicks on new dialog box, this is called
    ///         Creates an animation with specified width and height, and adds one frame
    ///         Simultaneously, it resets the associated history
    /// \param width of new animation
    /// \param height of new animation
    ///
    void createNewAnimation(const int width, const int height);

    ///
    /// \brief Model::saveFramesToHistory   A signal that saves the current Animation to the UserHistory class.
    ///
    void saveFramesToHistory();

    ///
    /// \brief Model::undoAction    A slot that reverts the current Animation/Sprite to the previous saved state.
    ///                             If no previous saved state exists, nothing changes.
    ///
    void undoAction();

    ///
    /// \brief Model::redoAction    A slot that reverts the current Animation/Sprite to the future saved state.
    ///                             ("future" only being defined if undo has been previously called)
    ///                             If no future saved state exists, nothing changes.
    ///
    void redoAction();

  private:
    /// \brief Stores all frame data
    Animation animation;

    /// \brief TimeLine is used to draw the animation on a certain frequency
    QTimeLine animationTimeLine;
    bool currentlyPlayingAnimation = false;
    int currentFPS = 1;

    /// \brief Used to implent undo/redo
    UserState userState;
    UserHistory userHistory;

    /// \brief The current frame the view is seeing
    int currentFrameIndex = 0;
};

#endif // MODEL_H
