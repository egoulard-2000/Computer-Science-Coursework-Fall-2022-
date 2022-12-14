/*
// File name: chesspiece.cpp
// Author:    Allen
// Assignment:Educational Program
// Group:     AKPSE
// Date:      12/8/2022
// Course:    CS 3505, University of Utah, School of Computing
// Copyright: CS 3505 and AKPSE - This work may not be copied for use in Academic Coursework.
//
// Our group, AKPSE, certifies that we wrote this code from scratch and did not copy it in part or whole from
// another source.
//
// File Contents
//
//      ChessPiece is an abstract class with polymorphic behavior, representing
//          any piece on a chess board. It can move around, as well as tell
//          the outside world what its possible moves are.
//
//      Note: Though a ChessPiece keeps track of whether it's white/black,
//          its move-set is assumed to only be used by the white/player side.
*/

#include "chesspiece.h"

///
/// \brief ChessPiece::ChessPiece   Default Constructor
/// \param white
///
ChessPiece::ChessPiece(bool white) : white(white) {}


///
/// \brief ChessPiece::~ChessPiece  Default Destructor
///
ChessPiece::~ChessPiece() {}


///
/// \brief ChessPiece::print    Prints the info in this ChessPiece into a QDebug.
/// \param debug                The debug to insert into.
/// \return QDebug              The debug message to print
///
QDebug ChessPiece::print(QDebug debug) const
{
    QDebugStateSaver saver(debug);

    debug.nospace() << "Chesspiece";

    return debug;
}


///
/// \brief ChessPiece::isWhite  Returns whether this ChessPiece is white or black.
/// \return                     True if white. False if black.
///
bool ChessPiece::isWhite() const
{
    return white;
}


///
/// \brief operator<<  Overloads the '<<' operator for qDebug
/// \param debug
/// \param piece       The ChessPiece to debug information from
/// \return QDebug     The Debug Object to refer to when overloading
///
QDebug operator<<(QDebug debug, const ChessPiece& piece)
{
    return piece.print(debug);
}
