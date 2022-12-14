/*
// File name: animation.h
// Author:    Stefan, Emile, and Soli
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
//      This is the header file that defines the animation class. This class contains a sequence of frames,
//      and contains methods to manipulate frames as well as the animation as a whole.
*/


#ifndef ANIMATION_H
#define ANIMATION_H

#include <QImage>
#include <QVector>


///
/// \brief Class that stores and manipulates a sequence of frames.
///
class Animation
{
  public:
    ///
    /// \brief Constructor that takes in a size, and creates an animation with one blank image.
    /// \param width in pixels
    /// \param height in pixels
    Animation(const int width, const int height);

    ///
    /// \brief Initializes the Animation to use the passed in image as the first frame.
    /// \param width in pixels
    /// \param height in pixels
    ///
    Animation(QImage image);

    ///
    /// \brief Appends a blank Image to the animation
    ///
    void addFrame();

    ///
    /// \brief Removes a frame from the end of the animation, safe when empty
    ///
    void removeFrame();


    ///
    /// \brief Swaps two frames in the animation
    /// \param First index to swap
    /// \param Second index to swap
    ///
    void swapFrames(const int indexOne, const int indexTwo);

    ///
    /// \brief Returns the number of frames in the animation
    /// \return Animation size
    ///
    int frameCount() const;

    ///
    /// \brief Returns width of each frame in pixels
    /// \return Width in pixels
    ///
    int width() const;

    ///
    /// \brief Returns height of each frame in pixels
    /// \return Height in pixels
    int height() const;

    ///
    /// \brief Returns true if animation has no frames
    /// \return true or false
    ///
    bool isEmpty() const;

    ///
    /// \brief Returns a const reference to frame at an index, or if doesn't exist, returns a null image (0 x 0 image)
    /// \param Index of frame to get
    /// \return Const reference to frame
    ///
    const QImage& getFrame(const int index) const;

    ///
    /// \brief Replaces the color of a pixel at the specified frame index and location with newColor
    ///        Throws exception if not valid index, does NOT throw exception if invalid location
    /// \param frameIndex - index of frame to modify
    /// \param location - pixel coordinate to modify, (0,0) is top left
    /// \param newColor - color to replace pixel with
    ///
    void changePixelColor(const int frameIndex, const QPoint location, const QColor newColor);

    ///
    /// \brief Clears the frame at frameIndex, setting it a blank image.
    ///        Throws if not a valid index.
    /// \param Index of frame to clear
    ///
    void clearFrame(const int frameIndex);

  private:
    ///
    /// \brief Creates a fully  transparent image
    /// \param width to create image
    /// \param height to create image
    /// \return the new image
    ///
    QImage createBlankImage(const int width, const int height) const;


    /// \brief Stores every frame in the Animation
    QVector<QImage> allFrames;

    /// \brief  Stores width and height of all frames.
    std::pair<int, int> dimensions;

    /// \brief This is a blank image, it is initialized to the dimensions passed in
    QImage blankImage;


    /// \brief The type of format all images will be stored in
    static constexpr QImage::Format CURRENTFORMAT = QImage::Format_ARGB32;

    /// \brief a 0 by 0 image, returned when invalid index is requested
    static const QImage nullImage;
};

#endif // ANIMATION_H
