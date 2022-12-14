/*
// File name: model.cpp
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
//      This is the source file that controls the model side of the project, that uses data received from the view as well as data
//      stored within this class to manipulate what the users see on the GUI.
*/


#include "model.h"
#include "filehandling.h"


///
/// \brief Initializes the animationTimeLine and connections of the model.
/// \param parent object to be tied to
///
Model::Model(QObject* parent) : QObject{parent}, animation(QImage(":images/tester.png")), userHistory(animation)
{

    // repeat forever
    animationTimeLine.setLoopCount(0);
    animationTimeLine.setStartFrame(0);

    // This sets the framerate to be constant, otherwise frames are drawn at erratic speeds
    animationTimeLine.setEasingCurve(QEasingCurve::Linear);
    animationTimeLine.setCurrentTime(1'000); // Starts at 1 FPS, need this so first signal is not really slow

    // Connect the timeline's frameChanged signal to the model's requestedFrameChange
    // Will re-draw the images for the view
    connect(&animationTimeLine, &QTimeLine::frameChanged, this, &Model::requestedFrameChange);

    // Allow the UserState to update the history when they want
    connect(&userState, &UserState::saveCurrentAnimation, this, &Model::saveFramesToHistory);
}


///
/// \brief Slot that processes the view requesting a change of frame.
///        Does not change the frame if requested frame does not exist.
/// \param frame index requested
///
void Model::requestedFrameChange(const int frameIndex)
{
    if (animation.isEmpty())
        return;

    if (frameIndex >= 0 && frameIndex < animation.frameCount())
    {
        emit updateCanvas(animation.getFrame(frameIndex), frameIndex);
        currentFrameIndex = frameIndex;
    }
}


///
/// \brief  Model::requestedNextFrame
///         Slot that is called when the user wants to move to the next frame from where they are.
///
void Model::requestedNextFrame()
{
    requestedFrameChange(currentFrameIndex + 1);
}


///
/// \brief  Model::requestedPreviousFrame
///         Slot that is called when the user wants to move back from the current frame they are on.
///
void Model::requestedPreviousFrame()
{
    requestedFrameChange(currentFrameIndex - 1);
}


///
/// \brief Slot that handles adding a new frame to the animation
///
void Model::addFrame()
{
    // Add the frame, and save this state to history
    animation.addFrame();
    animationTimeLine.setEndFrame(animation.frameCount());
    userHistory.saveAnimationToHistory(animation);

    // Adding a new frame, means duration must be adjusted
    updateFPS(currentFPS);

    // If after adding a frame, there is only 1 frame, we need to draw it!
    if (animation.frameCount() == 1)
    {
        currentFrameIndex = 0;
        emit updateCanvas(animation.getFrame(currentFrameIndex), currentFrameIndex);
    }
}


///
/// \brief Slot that handles removing a new frame from the animation
///
void Model::removeFrame()
{
    // Remove the frame, and save this state to history
    animation.removeFrame();
    animationTimeLine.setEndFrame(animation.frameCount());
    userHistory.saveAnimationToHistory(animation);

    // Removing a frame, means duration must be adjusted
    updateFPS(currentFPS);

    // If frame that the user is looking at is removed, need to go to previous frame
    // Note, if there is only 1 frame, currentFrameIndex will become -1 on deletion,
    // but the getFrame will return a 0 by 0 image in this case
    if (animation.frameCount() == currentFrameIndex)
    {
        --currentFrameIndex;
        emit updateCanvas(animation.getFrame(currentFrameIndex), currentFrameIndex);
    }
}


///
/// \brief Slot that handles swapping frames
///        If currently viewing one of the swapped frames,
///        you will still view that image after the swap.
///        Otherwise, you stay at the same frame you were on before
///
void Model::swapFrames(const int frameIndexOne, const int frameIndexTwo)
{
    animation.swapFrames(frameIndexOne, frameIndexTwo);
    userHistory.saveAnimationToHistory(animation);

    emit updateCanvas(animation.getFrame(frameIndexOne), frameIndexOne);
    emit updateCanvas(animation.getFrame(frameIndexTwo), frameIndexTwo);

    // This checks if one of the frames being swapped was the currentFrame,
    // if so follows that frame after the swap.
    int finalDisplayIndex = currentFrameIndex;
    if (currentFrameIndex == frameIndexOne)
        finalDisplayIndex = frameIndexTwo;
    else if (currentFrameIndex == frameIndexTwo)
        finalDisplayIndex = frameIndexOne;

    currentFrameIndex = finalDisplayIndex;

    emit updateCanvas(animation.getFrame(currentFrameIndex), currentFrameIndex);
}


///
/// \brief  Model::toggleAnimationPlayback
///         This is the slot that is used when the user would like the animation of multiple frames
///         to be displayed.
///
void Model::toggleAnimationPlayback()
{
    if (currentlyPlayingAnimation)
    {
        animationTimeLine.stop();
    }
    else
    {
        animationTimeLine.start();
    }

    currentlyPlayingAnimation = !currentlyPlayingAnimation;
}


///
/// \brief Slot that takes in FPS number from UI and adjusts timeline as necessary
/// \param fps to set to
///
void Model::updateFPS(int fps)
{
    currentFPS = fps;

    // First calculate how many milliseconds each frame should take
    const int msPerFrame = 1000 / fps;

    // Then calculate how long the entire TimeLine must be
    const int newDuration = msPerFrame * animation.frameCount();

    // Finally, adjust the TimeLine
    animationTimeLine.setDuration(newDuration);

    // This line is necessary to keep the timeline from starting very late (a known bug)
    animationTimeLine.setCurrentTime(newDuration); // Starts at 1 FPS, need this so first signal is not really slow
}


///
/// \brief  Model::setPenTool
///         Slot that updates current tool being used to the pen.
///
void Model::setPenTool()
{
    userState.setPenTool();
}


///
/// \brief  Model::setEraserTool
///         Slot that updates current tool being used to the eraser.
///
void Model::setEraserTool()
{
    userState.setEraserTool();
}


///
/// \brief  Model::setClearCanvasTool
///         Slot that updates current tool being used to clear canvas.
///
void Model::setClearCanvasTool()
{
    userState.setClearCanvasTool();
}


///
/// \brief  Model::setBucketFillTool
///         Slot that updates current tool being used to bucket fill.
///
void Model::setBucketFillTool()
{
    userState.setBucketFillTool();
}


///
/// \brief  Model::setTintTool
///         Slot that updates current tool being used to tinting tool.
///
void Model::setTintTool()
{
    userState.setTintTool();
}


///
/// \brief  Model::setShadeTool
///         Slot that updates current tool being used to shading tool.
///
void Model::setShadeTool()
{
    userState.setShadeTool();
}


///
/// \brief Uses the current tool, has checks to ensure the frame actually exists
/// \param point to use tool on
/// \param mousePressed true if mouse was pressed
///
void Model::useCurrentTool(const QPoint& point, bool mousePressed)
{
    if (animation.isEmpty())
        return;

    if (currentFrameIndex >= 0 && currentFrameIndex < animation.frameCount())
    {
        userState.useCurrentTool(animation, point, currentFrameIndex, mousePressed);
        emit updateCanvas(animation.getFrame(currentFrameIndex), currentFrameIndex);
    }
}


///
/// \brief  This slot is used when the user wants to save to a file
/// \param  file to save to
///
void Model::saveToFile(QFile& file)
{
    FileHandling::saveToFile(file, animation);
}


///
/// \brief This slot is used when the user wants to load in a file
/// \param file to load from
///
void Model::loadFromFile(QFile& file)
{
    try
    {
        animation = FileHandling::loadFromFile(file);
        emit successfulLoad(animation.isEmpty(), file.fileName());
        // Send all frames to the view, allows right animation bar to be populated
        // Send 0 frame at the end, so loads into first frame
        for (int frameIndex = 0; frameIndex < animation.frameCount(); ++frameIndex)
            emit updateCanvas(animation.getFrame(frameIndex), frameIndex);

        emit updateCanvas(animation.getFrame(0), 0);

        // Now, need to update the end frame for playback and updateFPS
        animationTimeLine.setEndFrame(animation.frameCount());
        updateFPS(currentFPS);

        currentFrameIndex = 0;
        userHistory = UserHistory(animation);
    }
    catch (const std::invalid_argument& exception)
    {
        emit sendErrorMessage(exception.what());
    }
}


///
/// \brief Model::updateStoredColor     Updates the color used by the drawing tools
/// \param newColor                     The new color to store
///
void Model::updateStoredColor(const QColor newColor)
{
    userState.setColor(newColor);
}


///
/// \brief  When view clicks on new dialog box, this is called
///         Creates an animation with specified width and height, and adds one frame
///         Simultaneously, it resets the associated history
/// \param width of new animation
/// \param height of new animation
///
void Model::createNewAnimation(const int width, const int height)
{
    // Create new Animation
    animation = Animation(width, height);
    animation.addFrame();
    emit updateCanvas(animation.getFrame(0), 0);
    currentFrameIndex = 0;

    // Reset History
    userHistory = UserHistory(animation);
}


///
/// \brief Model::saveFramesToHistory   A signal that saves the current Animation to the UserHistory class.
///
void Model::saveFramesToHistory()
{
    userHistory.saveAnimationToHistory(animation);
}


///
/// \brief Model::undoAction    A slot that reverts the current Animation/Sprite to the previous saved state.
///                             If no previous saved state exists, nothing changes.
///
void Model::undoAction()
{
    // Guard clause: If undo isn't possible, this call is ignored.
    if (!userHistory.canUndo())
        return;

    // Revert the current Animation to a previous state
    animation = userHistory.undoAction();

    // Update all the frames in the View
    QVector<QImage> newImages;
    for (int i = 0; i < animation.frameCount(); i++)
    {
        newImages.append(animation.getFrame(i));
    }
    emit bulkUpdateAnimation(newImages);

    // Tell the View what frame to display (if the frame was deleted, show the first frame)
    if (currentFrameIndex >= animation.frameCount())
        currentFrameIndex = 0;
    emit updateCanvas(animation.getFrame(currentFrameIndex), currentFrameIndex);
}


///
/// \brief Model::redoAction    A slot that reverts the current Animation/Sprite to the future saved state.
///                             ("future" only being defined if undo has been previously called)
///                             If no future saved state exists, nothing changes.
///
void Model::redoAction()
{
    // Guard clause: If undo isn't possible, this call is ignored.
    if (!userHistory.canRedo())
        return;

    // Revert the current Animation to a future state
    animation = userHistory.redoAction();

    // Update all the frames in the View
    QVector<QImage> newImages;
    for (int i = 0; i < animation.frameCount(); i++)
    {
        newImages.append(animation.getFrame(i));
    }
    emit bulkUpdateAnimation(newImages);

    // Tell the View what frame to display (if the frame was deleted, show the first frame)
    if (currentFrameIndex >= animation.frameCount())
        currentFrameIndex = 0;
    emit updateCanvas(animation.getFrame(currentFrameIndex), currentFrameIndex);
}
