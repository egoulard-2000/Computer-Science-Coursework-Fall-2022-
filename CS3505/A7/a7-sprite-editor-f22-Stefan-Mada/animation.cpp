/*
// File name: animation.cpp
// Author:    Stefan, Michael, and Soli
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
//      This is the source file that implements the animation header. It adds the functionality for creating
//      and manipulating frames in the animation class.
*/


#include "animation.h"


///
/// \brief Initializes a null image for being drawn when animation is empty
///
const QImage Animation::nullImage(0, 0, CURRENTFORMAT);


///
/// \brief Constructor that takes in a size, and creates an animation with one blank image.
/// \param width in pixels
/// \param height in pixels
///
Animation::Animation(const int width, const int height)
    : dimensions(width, height), blankImage(createBlankImage(width, height))
{
}


///
/// \brief Initializes the Animation to use the passed in image as the first frame.
/// \param width in pixels
/// \param height in pixels
///
Animation::Animation(QImage image) : Animation(image.width(), image.height())
{
    auto newImage = image.convertToFormat(CURRENTFORMAT);
    allFrames.append(newImage);
}

///
/// \brief Appends a blank Image to the animation
///
void Animation::addFrame()
{
    allFrames.append(blankImage);
}


///
/// \brief Removes a frame from the end of the animation
///
void Animation::removeFrame()
{
    if (!allFrames.isEmpty())
        allFrames.removeLast();
}


///
/// \brief Swaps two frames in the animation
/// \param First index to swap
/// \param Second index to swap
///
void Animation::swapFrames(const int indexOne, const int indexTwo)
{
    QImage tempImage = allFrames[indexOne];

    allFrames[indexOne] = allFrames[indexTwo];
    allFrames[indexTwo] = tempImage;
}


///
/// \brief Returns the number of frames in the animation
/// \return Animation size
///
int Animation::frameCount() const
{
    return allFrames.size();
}


///
/// \brief Returns width of each frame in pixels
/// \return Width in pixels
///
int Animation::width() const
{
    return dimensions.first;
}


///
/// \brief Returns height of each frame in pixels
/// \return Height in pixels
///
int Animation::height() const
{
    return dimensions.second;
}


///
/// \brief Returns true if animation has no frames
/// \return true or false
///
bool Animation::isEmpty() const
{
    return allFrames.isEmpty();
}


///
/// \brief Returns a const reference to frame at an index, or if doesn't exist, returns a null image (0 x 0 image)
/// \param Index of frame to get
/// \return Const reference to frame
///
const QImage& Animation::getFrame(const int index) const
{
    if (index >= frameCount() || index < 0)
        return nullImage;
    else
        return allFrames.at(index);
}


///
/// \brief Replaces the color of a pixel at the specified frame index and location with newColor
///        Throws exception if not valid index, does NOT throw exception if invalid location
/// \param frameIndex - index of frame to modify
/// \param location - pixel coordinate to modify, (0,0) is top left
/// \param newColor - color to replace pixel with
///
void Animation::changePixelColor(const int frameIndex, const QPoint location, const QColor newColor)
{
    QImage& selectedFrame = allFrames[frameIndex];
    selectedFrame.setPixelColor(location, newColor);
}


///
/// \brief Creates a fully  transparent image
/// \param width to create image
/// \param height to create image
/// \return the new image
///
QImage Animation::createBlankImage(const int width, const int height) const
{
    QImage newImage(width, height, CURRENTFORMAT);
    newImage.fill(QColor(0, 0, 0, 0)); // Completely see through, full alpha
    return newImage;
}


///
/// \brief Clears the frame at frameIndex, setting it a blank image.
///        Throws if not a valid index.
/// \param Index of frame to clear
///
void Animation::clearFrame(const int frameIndex)
{
    allFrames[frameIndex] = blankImage;
}
