/*
// File name: chessmove.cpp
// Author:    Allen
// Assignment:Educational Program
// Group:     AKPSE
// Date:      11/23/2022
// Course:    CS 3505, University of Utah, School of Computing
// Copyright: CS 3505 and AKPSE - This work may not be copied for use in Academic Coursework.
//
// Our group, AKPSE, certifies that we wrote this code from scratch and did not copy it in part or whole from
// another source.
//
// File Contents
//
//      ChessMove is a class used to uniquely identify any moves in chess.
            It specifies what piece originally moved, where it's moving,
            and any captures that occur.
            Note: Once a ChessMove object is created, it may become outdated
            if the chess board changes i.e any moves are made.
*/

#include "chessmove.h"

///
/// \brief ChessMove::ChessMove     An object that uniquely describes a chess move.
/// \param oldPos                   The old position of the moving piece.
/// \param newPos                   The new position the piece will move to.
/// \param capture                  Whether a capture occurs or not.
/// \param capturedPos              The position of the captured piece (if no capture occurs, can remain undefined)
///
ChessMove::ChessMove(ChessPosition oldPos, ChessPosition newPos, bool capture, ChessPosition capturedPos) :
            oldPosition(oldPos),
            newPosition(newPos),
            captureOccured(capture),
            capturedPosition(capturedPos)
{

}


///
/// \brief ChessMove::getOldPosition    Returns the old position that the moving piece occupied.
///
ChessPosition ChessMove::getOldPosition() const
{
    return oldPosition;
}


///
/// \brief ChessMove::getNewPosition    Returns the new position that the moving piece will occupy.
///
ChessPosition ChessMove::getNewPosition() const
{
    return newPosition;
}


///
/// \brief ChessMove::hasCaptured   Returns whether this move will result in a capture.
/// \return                         True if a capture occurs. False otherwise.
///
bool ChessMove::hasCaptured() const
{
    return captureOccured;
}


///
/// \brief ChessMove::whoWasCaptured    Specifies the position of a captured piece.
/// \return                             The position of the captured piece.
///                                     If no capture occurred, the return value is undefined.
///
ChessPosition ChessMove::whoWasCaptured() const
{
    return capturedPosition;
}


///
/// \brief ChessMove::operator ==   Comparison operator for whether
///                                 the chess moves are equal.
/// \param other                    The other chess moves to compare to.
/// \return                         True if moves are equal, false otherwise.
///
bool ChessMove::operator==(const ChessMove& other) const
{
    if(!(oldPosition == other.oldPosition)) // != is undefined for ChessPosition
        return false;
    if(!(newPosition == other.newPosition))
        return false;
    if(captureOccured != other.captureOccured)
        return false;

    // The capturePosition is only defined if captureOccured is true, so only check equality if so
    if(captureOccured && other.captureOccured)
    {
        if(!(capturedPosition == other.capturedPosition))
            return false;
    }

    return true;
}


///
/// \brief operator <<  Allows "qDebug() << ChessMove" to work.
/// \param debug        The QDebug object to insert into.
/// \param move         The ChessMove to print.
/// \return             The QDebug that was inserted into.
///
QDebug operator<<(QDebug debug, const ChessMove& move)
{
    QDebugStateSaver saver(debug);

    debug.nospace() << "Old:" << move.getOldPosition() << " New:" << move.getNewPosition();
    if(move.hasCaptured())
        debug.nospace() << " Captured:" << move.whoWasCaptured();

    return debug;
}
