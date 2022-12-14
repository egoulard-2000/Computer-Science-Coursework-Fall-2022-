/*
// File name: physicschesspiece.cpp
// Author:    Stefan
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
//      This is the source file that implements the PhysicsChessPiece class. This initializes physics pieces
//      that are bouncy and attaches them to an input world object.
*/


#include "physicschesspiece.h"
#include "Box2D/Collision/Shapes/b2PolygonShape.h"
#include "Box2D/Dynamics/b2Fixture.h"
#include "Box2D/Dynamics/b2World.h"


///
/// \brief PhysicsChessPiece::PhysicsChessPiece     Initializes a chess piece physics object with width, height dimensions,
///                                                 at x, y pos (centered), attached to the world object
/// \param world    Object to attach piece to
/// \param x        Center of object's x position
/// \param y        Center of object's y position
/// \param width    Object's width
/// \param height   Object's height
///
PhysicsChessPiece::PhysicsChessPiece(b2World& world, const float32 x, const float32 y, const int width, const int height)
    : body(*createBody(world, x, y, width, height)),
      image(createImage()),
      width(width),
      height(height)
{

}


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
b2Body* PhysicsChessPiece::createBody(b2World& world, const float32 x, const float32 y, const int width, const int height) const
{
    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    bodyDef.position.Set(x, y);
    b2Body* dynamicBody = world.CreateBody(&bodyDef);

    // Define another box shape for our dynamic body.
    b2PolygonShape dynamicBox;
    dynamicBox.SetAsBox(width, height);

    // Define the dynamic body fixture.
    b2FixtureDef fixtureDef;
    fixtureDef.shape = &dynamicBox;

    // Set the box density to be non-zero, so it will be dynamic.
    fixtureDef.density = 1.0f;

    // Override the default friction.
    fixtureDef.friction = 0.3f;

    // Velocites above this will bounce the object
    fixtureDef.restitution = 0.5f;

    // Add the shape to the body.
    dynamicBody->CreateFixture(&fixtureDef);

    return dynamicBody;
}


///
/// \brief PhysicsChessPiece::createImage   Creates a random image from several chess piece images,
///                                         as well as an Among Us image.
/// \return QImage initialized to a random possible image.
///
QImage PhysicsChessPiece::createImage() const
{
    const QVector<QString> imageStrings = {
        ":images/bBishop.png",
        ":images/bKnight.png",
        ":images/bKing.png",
        ":images/bPawn.png",
        ":images/bQueen.png",
        ":images/bRook.png",
        ":images/wBishop.png",
        ":images/wKnight.png",
        ":images/wKing.png",
        ":images/wPawn.png",
        ":images/wQueen.png",
        ":images/wRook.png",
        ":images/amongus.png"
    };

    // Choose a random string from the images above
    return QImage(imageStrings.at(rand() % imageStrings.size()));
}
