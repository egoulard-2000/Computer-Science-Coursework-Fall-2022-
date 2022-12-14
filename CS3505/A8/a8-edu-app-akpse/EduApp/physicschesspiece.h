/*
// File name: physicschesspiece.h
// Author:    Stefan, Allen
// Assignment:Educational Program
// Group:     AKPSE
// Date:      12/08/2022
// Course:    CS 3505, University of Utah, School of Computing
// Copyright: CS 3505 and AKPSE - This work may not be copied for use in Academic Coursework.
//
// Our group, AKPSE, certifies that we wrote this code from scratch and did not copy it in part or whole from
// another source.
//
// File Contents
//
//      This is the header file that defines the PhysicsChessPiece class. This class implements physics pieces
//      that are bouncy and attaches them to an input world object.
*/

#ifndef PHYSICSCHESSPIECE_H
#define PHYSICSCHESSPIECE_H

#include "Box2D/Dynamics/b2Body.h"
#include <QImage>

class PhysicsChessPiece
{
public:
    ///
    /// \brief PhysicsChessPiece::PhysicsChessPiece     Initializes a chess piece physics object with width, height dimensions,
    ///                                                 at x, y pos (centered), attached to the world object
    /// \param world    Object to attach piece to
    /// \param x        Center of object's x position
    /// \param y        Center of object's y position
    /// \param width    Object's width
    /// \param height   Object's height
    ///
    PhysicsChessPiece(b2World& world, const float32 x, const float32 y, const int width, const int height);

    ///
    /// \brief getBody  Returns a pointer to the stored b2Body object
    /// \return         Pointer to b2Body object
    ///
    inline b2Body& getBody() const {return body;}

    ///
    /// \brief getImage Returns the image associated with this physics object
    /// \return         QImage associated with this object
    ///
    inline QImage getImage() const {return image;}

    ///
    /// \brief getWidth Returns width of physics object
    /// \return         Width as an int
    ///
    inline int getWidth() const {return width;}

    ///
    /// \brief getHeight    Returns height of physics object
    /// \return             Height as an int
    ///
    inline int getHeight() const {return height;}

private:
    ///
    /// \brief PhysicsChessPiece::createBody    Method that creates a b2Body physics object with width, height dimensions,
    ///                                         at x, y pos (centered), attached to the world object
    /// \param world    Object to attach piece to
    /// \param x        Center of object's x position
    /// \param y        Center of object's y position
    /// \param width    Object's width
    /// \param height   Object's height
    /// \return         Pointer to created b2Body object
    ///
    b2Body* createBody(b2World& world, const float32 x, const float32 y, const int width, const int height) const;

    ///
    /// \brief PhysicsChessPiece::createImage   Creates a random image from several chess piece images,
    ///                                         as well as an Among Us image.
    /// \return QImage initialized to a random possible image.
    ///
    QImage createImage() const;

    b2Body& body;
    QImage image;
    int width;
    int height;
};

#endif // PHYSICSCHESSPIECE_H
