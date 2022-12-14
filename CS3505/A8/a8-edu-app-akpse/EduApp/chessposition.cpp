/*
// File name: chessposition.cpp
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
//      ChessPosition is a class that stores a position on a chess board.
//          The reason for having this class is to have a consistent API
//          that all other classes can use to communicate board positions,
//          rather than having multiple standards.
//
//      The coordinate system sets (0,0) at the bottom left of the board,
//          viewed from the white side of the chess board.
*/

#include "chessposition.h"


///
/// \brief ChessPosition::ChessPosition     Initializes the position.
/// \param h                                Horizontal/X position.
/// \param v                                Vertical/Y position.
///
ChessPosition::ChessPosition(horizontal h, vertical v) : hPos(h), vPos(v) {}


///
/// \brief ChessPosition::isValidPosition   Returns whether or not an (int, int)
///                                         position is a valid chess position.
/// \param h                                The horizontal/X coordinate
/// \param v                                The vertical/Y coordinate
/// \return                                 True if position is valid. False otherwise.
///
bool ChessPosition::isValidPosition(int h, int v)
{
    // Do not exceed the boundaries given on the chessboard
    if(h < MIN_H || MAX_H < h)
        return false;

    if(v < MIN_V || MAX_V < v)
        return false;

    return true;
}


///
/// \brief ChessPosition::operator==   Comparison operator for whether
///                                     the positions are equal.
/// \param other                        The other position to compare to.
/// \return                             True if positions are equal, false otherwise.
///
bool ChessPosition::operator==(const ChessPosition& other) const
{
    return (this->hPos == other.hPos) && (this->vPos == other.vPos);
}


///
/// \brief ChessPosition::operator!=   Non-comparison operator for whether
///                                     the positions are equal.
/// \param other                        The other position to compare to.
/// \return                             True if positions are unequal, false otherwise.
///
bool ChessPosition::operator!=(const ChessPosition& other) const
{
    return !(*this == other);
}


///
/// \brief ChessPosition::operator<    Operator overload for <.
/// \param other                        The other position to compare to.
/// \return                             this < other.
///
bool ChessPosition::operator<(const ChessPosition& other) const
{
    if(vPos == other.vPos)
        return (int)hPos < (int)other.hPos;

    return (int)vPos < other.vPos;
}


///
/// \brief operator<<  Allows "qDebug() << ChessPosition" to work.
/// \param debug        The QDebug object to insert into.
/// \param pos          The ChessPosition to print.
/// \return QDebug      The Debug Object to refer to when overloading
///
QDebug operator<<(QDebug debug, const ChessPosition& pos)
{
    QDebugStateSaver saver(debug);
    debug.nospace() << "(" << pos.hPos << "," << pos.vPos << ")";
    return debug;
}
