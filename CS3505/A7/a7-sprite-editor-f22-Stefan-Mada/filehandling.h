/*
// File name: filehandling.h
// Author:    Stefan
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
//      This is the header file that defines the FileHandling class. This class provides static functions
//      to load a file into an animation, and to save an animation into a file.
*/

#ifndef FILEHANDLING_H
#define FILEHANDLING_H

#include "animation.h"
#include <QFile>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>


///
/// \brief Implements saveToFile and loadFromFile for the animation class.
///
class FileHandling
{
  public:
    ///
    /// \brief Default constructor, doesn't initialize anything.
    ///
    FileHandling();

    ///
    /// \brief Given a file, will serialize the passed animation into JSON and store it in the file.
    /// \param file to write to
    /// \param animation to save
    ///
    /// \details For a given animation, stores 4 values: height, width, and number of frames, as well
    ///          as an object called frames, storing multiple objects named frameN, where N is the frame
    ///          index, which are arrays of arrays of pixels, which are 4 RGBA values from 0-255 inclusive.
    ///
    static void saveToFile(QFile& file, const Animation& animation);

    ///
    /// \brief Given a file, will load the filefrom  JSON and return the deserialized animation.
    /// \param file to read from
    /// \return The deserialized animation
    ///
    /// \throws std::invalid_argument if json is not in the proper format
    ///
    /// \details For a given animation, reads 4 values: height, width, and number of frames, as well
    ///          as an object called frames, storing multiple objects named frameN, where N is the frame
    ///          index, which are arrays of arrays of pixels, which are 4 RGBA values from 0-255 inclusive.
    ///          If any element does not exist, or the height and width of the arrays don't match, or the pixel
    ///          values are outside of a 0-255 range, then an exception will throw.
    ///
    static Animation loadFromFile(QFile& file);
};

#endif // FILEHANDLING_H
