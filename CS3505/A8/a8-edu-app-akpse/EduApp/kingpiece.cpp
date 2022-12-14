/*
// File name: kingpiece.cpp
// Author:    Michael, Allen
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
//      KingPiece implements the ChessPiece class as a King.
            See ChessPiece.cpp for details.
*/

#include "kingpiece.h"

using horizontal = ChessPosition::horizontal;
using vertical = ChessPosition::vertical;


///
/// \brief KingPiece::KingPiece     This constructor simply over-rides
///                                 that of the ChessPiece class.
/// \param white                    True if piece is white, false if black.
/// \sa                             ChessPiece::ChessPiece()
///
KingPiece::KingPiece(bool white) : ChessPiece(white)
{

}

///
/// \brief KingPiece::possibleMoves     This is a reimplementation of
///                                     ChessPiece::possibleMoves().
///                                     It is used to return all the possible
///                                     ChessMoves that KingPiece may do.
/// \sa                                 ChessPiece::possibleMoves()
///
QVector<ChessMove> KingPiece::possibleMoves(const ChessPosition& curPos, const QMap<ChessPosition, ChessPiece*>& board) const
{
    // Initialize variables
    QVector<ChessMove> newMoves;
    int posX = (int)curPos.hPos;
    int posY = (int)curPos.vPos;

    // Check all tiles directly next to the King
    addIfValid(newMoves, posX, posY + 1, curPos, board);        // Top
    addIfValid(newMoves, posX + 1, posY + 1, curPos, board);    // Top right
    addIfValid(newMoves, posX + 1, posY, curPos, board);        // Right
    addIfValid(newMoves, posX + 1, posY - 1, curPos, board);    // Bottom right
    addIfValid(newMoves, posX, posY - 1, curPos, board);        // Bottom
    addIfValid(newMoves, posX - 1, posY - 1, curPos, board);    // Bottom left
    addIfValid(newMoves, posX - 1, posY, curPos, board);        // Left
    addIfValid(newMoves, posX - 1, posY + 1, curPos, board);    // Top left

    return newMoves;
}


///
/// \brief print    This is a reimplementation of ChessPiece::print().
///                 It is used to print info about this King into qDebug().
/// \sa             ChessPiece::print()
///
QDebug KingPiece::print(QDebug debug) const
{
    QDebugStateSaver saver(debug);

    debug.nospace() << "King";

    return debug;
}


///
/// \brief operator <<  This is a reimplementation of ChessPiece::operator<<().
///                     It is used to print info about this King into qDebug().
/// \sa                 ChessPiece::operator<<()
///
QDebug operator<<(QDebug debug, const KingPiece& piece)
{
    return piece.print(debug);
}


///
/// \brief KingPiece::addIfValid    If a position is a valid move, it will add to the vector.
/// \param newMoves                 The QVector of moves to add to.
/// \param x                        The x position to move to.
/// \param y                        The y position to move to.
/// \param curPos                   The current position of the King
/// \param board                    The current chess board.
///
void KingPiece::addIfValid(QVector<ChessMove>& newMoves, int x, int y, const ChessPosition& curPos, const QMap<ChessPosition, ChessPiece*>& board) const
{
    // Edge Case: Desired position may not exist
    if(!ChessPosition::isValidPosition(x, y))
        return;

    // If position is unnocupied, King is free to move to it
    ChessPosition newPos = ChessPosition((horizontal)x, (vertical)y);
    if(!board.contains(newPos))
    {
        newMoves.append(ChessMove(curPos, newPos, false));
        return;
    }

    // Occupied positions with an enemy results in a capture
    if(!(board[newPos]->isWhite()))
        newMoves.append(ChessMove(curPos, newPos, true, newPos));
}
