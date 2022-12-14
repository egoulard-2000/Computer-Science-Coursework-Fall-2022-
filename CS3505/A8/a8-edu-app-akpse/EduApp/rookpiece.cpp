/*
// File name: rookpiece.cpp
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
//      RookPiece implements the ChessPiece class as a Rook.
            See ChessPiece.cpp for details.
*/

#include "rookpiece.h"

using horizontal = ChessPosition::horizontal;
using vertical = ChessPosition::vertical;


///
/// \brief RookPiece::RookPiece     This constructor simply over-rides
///                                 that of the ChessPiece class.
/// \param white                    True if piece is white, false if black.
/// \sa                             ChessPiece::ChessPiece()
///
RookPiece::RookPiece(bool white) : ChessPiece(white)
{

}


///
/// \brief RookPiece::possibleMoves     This is a reimplementation of
///                                     ChessPiece::possibleMoves().
///                                     It is used to return all the possible
///                                     ChessMoves that RookPiece may do.
/// \sa                                 ChessPiece::possibleMoves()
///
QVector<ChessMove> RookPiece::possibleMoves(const ChessPosition& curPos, const QMap<ChessPosition, ChessPiece*>& board) const
{
    // Initialize variables
    QVector<ChessMove> newMoves;
    int posX;
    int posY;

    // Add all moves going up
    posX = curPos.hPos;
    posY = curPos.vPos + 1;
    while(addIfValid(newMoves, posX, posY, curPos, board))
    {
        posY += 1;
    }

    // Add all moves going down
    posX = curPos.hPos;
    posY = curPos.vPos - 1;
    while(addIfValid(newMoves, posX, posY, curPos, board))
    {
        posY -= 1;
    }

    // Add all moves going left
    posX = curPos.hPos - 1;
    posY = curPos.vPos;
    while(addIfValid(newMoves, posX, posY, curPos, board))
    {
        posX -= 1;
    }

    // Add all moves going right
    posX = curPos.hPos + 1;
    posY = curPos.vPos;
    while(addIfValid(newMoves, posX, posY, curPos, board))
    {
        posX += 1;
    }

    return newMoves;
}


///
/// \brief print    This is a reimplementation of ChessPiece::print().
///                 It is used to print info about this Rook into qDebug().
/// \sa             ChessPiece::print()
///
QDebug RookPiece::print(QDebug debug) const
{
    QDebugStateSaver saver(debug);

    debug.nospace() << "Rook";

    return debug;
}


///
/// \brief operator <<  This is a reimplementation of ChessPiece::operator<<().
///                     It is used to print info about this Rook into qDebug().
/// \sa                 ChessPiece::operator<<()
///
QDebug operator<<(QDebug debug, const RookPiece& piece)
{
    return piece.print(debug);
}


///
/// \brief RookPiece::addIfValid    If a position is a valid move, it will add to the vector
/// \param newMoves                 The QVector of moves to add to.
/// \param x                        The x position to move to.
/// \param y                        The y position to move to.
/// \param curPos                   The current position of the Rook.
/// \param board                    The current chess board.
/// \return                         True if further moves can be made through this tile,
///                                 false if something blocks the way.
///
bool RookPiece::addIfValid(QVector<ChessMove>& newMoves, int x, int y, const ChessPosition& curPos, const QMap<ChessPosition, ChessPiece*>& board) const
{
    // Check if the position is on the board
    if(!ChessPosition::isValidPosition(x, y))
        return false;

    // Case: If position is unoccupied, the Rook may move there.
    ChessPosition newPos = ChessPosition((horizontal)x, (vertical)y);
    if(!board.contains(newPos))
    {
        newMoves.append(ChessMove(curPos, newPos, false));
        return true;
    }

    // Case: If position is occupied, Rook may only capture opposing pieces
    else
    {
        if(board[newPos]->isWhite() != isWhite())
            newMoves.append(ChessMove(curPos, newPos, true, newPos));

        return false;
    }
}
