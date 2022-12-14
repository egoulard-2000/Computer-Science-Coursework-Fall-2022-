/*
// File name: filehandling.cpp
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
//      This is the source file that implements the FrameButton class. This class is used to display
//      frames on the right side of view, allowing users to preview frames. It is composed of 3 buttons
//      in a layout.
*/


#include "filehandling.h"


///
/// \brief Default constructor, doesn't initialize anything.
///
FileHandling::FileHandling()
{
}


///
/// \brief Given a file, will serialize the passed animation into JSON and store it in the file.
/// \param file to write to
/// \param animation to save
///
/// \details For a given animation, stores 4 values: height, width, and number of frames, as well
///          as an object called frames, storing multiple objects named frameN, where N is the frame
///          index, which are arrays of arrays of pixels, which are 4 RGBA values from 0-255 inclusive.
///
void FileHandling::saveToFile(QFile& file, const Animation& animation)
{
    QJsonObject mainJson;
    mainJson["height"] = animation.height();
    mainJson["width"] = animation.width();
    mainJson["numberOfFrames"] = animation.frameCount();

    // Now handle the animation
    // Iterates on each frame, then on each row, then on each col, and at this point,
    // every element is a pixel, so we can push back the RGBA values.
    // After each loop, these are stored in JSON objects appropriately, before
    // being stored at the end.
    QJsonObject frameArray;
    for (int frameIndex = 0; frameIndex < animation.frameCount(); ++frameIndex)
    {
        QJsonArray frameRows;
        for (int row = 0; row < animation.height(); ++row)
        {
            QJsonArray frameCols;
            for (int col = 0; col < animation.width(); ++col)
            {
                QJsonArray pixelColor;
                // Col before rows because col is the x val, row is y val
                const QColor currColor = animation.getFrame(frameIndex).pixelColor(QPoint(col, row));
                pixelColor.push_back(currColor.red());
                pixelColor.push_back(currColor.green());
                pixelColor.push_back(currColor.blue());
                pixelColor.push_back(currColor.alpha());

                frameCols.push_back(pixelColor);
            }
            frameRows.push_back(frameCols);
        }
        QString frameName("frame" + QString::number(frameIndex));
        frameArray[frameName] = frameRows;
    }
    mainJson["frames"] = frameArray;

    file.write(QJsonDocument(mainJson).toJson());
    file.close();
}


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
Animation FileHandling::loadFromFile(QFile& file)
{
    QByteArray saveData = file.readAll();

    QJsonDocument loadDoc(QJsonDocument::fromJson(saveData));
    QJsonObject mainJson = loadDoc.object();

    // Checks to make sure the required fields exist
    if (!mainJson.contains("height"))
        throw std::invalid_argument("File does not have height field");
    if (!mainJson.contains("width"))
        throw std::invalid_argument("File does not have width field");
    if (!mainJson.contains("numberOfFrames"))
        throw std::invalid_argument("File does not have numberOfFrames field");
    if (!mainJson.contains("frames") || !mainJson["frames"].isObject())
        throw std::invalid_argument("File does not have frames field");

    const int height = mainJson["height"].toInt();
    const int width = mainJson["width"].toInt();
    const int numberOfFrames = mainJson["numberOfFrames"].toInt();

    // can now create the animation with this info, and modify it as needed
    Animation loadedAnimation(width, height);

    // We know a "frames" object exists, so get it
    const QJsonObject frames = mainJson["frames"].toObject();
    for (int frameIndex = 0; frameIndex < numberOfFrames; ++frameIndex)
    {
        // Need to check if framen exists
        const QString frameName("frame" + QString::number(frameIndex));
        if (!frames.contains(frameName) || !frames[frameName].isArray())
            throw std::invalid_argument("File does not have one or more frames");

        loadedAnimation.addFrame();
        const QJsonArray currFrame = frames[frameName].toArray();

        // Must check if current frame has height rows
        if (currFrame.size() != height)
            throw std::invalid_argument(frameName.toStdString() + " should have " + std::to_string(height) +
                                        " rows, but has " + std::to_string(currFrame.size()));

        for (int row = 0; row < height; ++row)
        {
            const QJsonArray currRow = currFrame[row].toArray();

            // Check if current row has width columns
            if (currRow.size() != width)
                throw std::invalid_argument(frameName.toStdString() + "'s row " + std::to_string(row) +
                                            " should have " + std::to_string(width) + " columns, but has " +
                                            std::to_string(currRow.size()));

            for (int col = 0; col < width; ++col)
            {
                const QJsonArray currPixel = currRow[col].toArray();

                // Check if pixel has 4 integer parameters
                if (currPixel.size() != 4)
                    throw std::invalid_argument(frameName.toStdString() + "'s pixel at row " + std::to_string(row) +
                                                ", column " + std::to_string(col) +
                                                " should have 4 paramemters, but instead has " +
                                                std::to_string(currPixel.size()));

                const int red = currPixel[0].toInt();
                const int green = currPixel[1].toInt();
                const int blue = currPixel[2].toInt();
                const int alpha = currPixel[3].toInt();

                // Check if all values are within the correct limits
                if (red > 255 || green > 255 || blue > 255 || alpha > 255 || red < 0 || green < 0 || blue < 0 ||
                    alpha < 0)
                    throw std::invalid_argument(frameName.toStdString() + "'s pixel at row " + std::to_string(row) +
                                                ", column " + std::to_string(col) +
                                                " has a color value for RGBA outside of 0-255 range.");

                const QColor colorHere(red, green, blue, alpha);
                loadedAnimation.changePixelColor(frameIndex, QPoint(col, row), colorHere);
            }
        }
    }

    return loadedAnimation;
}
