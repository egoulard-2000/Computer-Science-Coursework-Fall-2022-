/*
// File name: queenpiece.cpp
// Author:    Allen
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
//      QueenPiece implements the ChessPiece class as a Queen.
            See ChessPiece.cpp for details.
*/

#include "queenpiece.h"

using horizontal = ChessPosition::horizontal;
using vertical = ChessPosition::vertical;


///
/// \brief QueenPiece::QueenPiece   This constructor simply over-rides
///                                 that of the ChessPiece class.
/// \param white                    True if piece is white, false if black.
/// \sa                             ChessPiece::ChessPiece()
///
QueenPiece::QueenPiece(bool white) : ChessPiece(white)
{

}


///
/// \brief QueenPiece::possibleMoves    This is a reimplementation of
///                                     ChessPiece::possibleMoves().
///                                     It is used to return all the possible
///                                     ChessMoves that QueenPiece may do.
/// \sa                                 ChessPiece::possibleMoves()
///
QVector<ChessMove> QueenPiece::possibleMoves(const ChessPosition& curPos, const QMap<ChessPosition, ChessPiece*>& board) const
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

    // Add all moves going upper right
    posX = curPos.hPos + 1;
    posY = curPos.vPos + 1;
    while(addIfValid(newMoves, posX, posY, curPos, board))
    {
        posX += 1;
        posY += 1;
    }

    // Add all moves going right
    posX = curPos.hPos + 1;
    posY = curPos.vPos;
    while(addIfValid(newMoves, posX, posY, curPos, board))
    {
        posX += 1;
    }

    // Add all moves going down right
    posX = curPos.hPos + 1;
    posY = curPos.vPos - 1;
    while(addIfValid(newMoves, posX, posY, curPos, board))
    {
        posX += 1;
        posY -= 1;
    }

    // Add all moves going down
    posX = curPos.hPos;
    posY = curPos.vPos - 1;
    while(addIfValid(newMoves, posX, posY, curPos, board))
    {
        posY -= 1;
    }

    // Add all moves going down left
    posX = curPos.hPos - 1;
    posY = curPos.vPos - 1;
    while(addIfValid(newMoves, posX, posY, curPos, board))
    {
        posX -= 1;
        posY -= 1;
    }

    // Add all moves going left
    posX = curPos.hPos - 1;
    posY = curPos.vPos;
    while(addIfValid(newMoves, posX, posY, curPos, board))
    {
        posX -= 1;
    }

    // Add all moves going up left
    posX = curPos.hPos - 1;
    posY = curPos.vPos + 1;
    while(addIfValid(newMoves, posX, posY, curPos, board))
    {
        posX -= 1;
        posY += 1;
    }

    return newMoves;
}


///
/// \brief print    This is a reimplementation of ChessPiece::print().
///                 It is used to print info about this Queen into qDebug().
/// \sa             ChessPiece::print()
///
QDebug QueenPiece::print(QDebug debug) const
{
    QDebugStateSaver saver(debug);

    debug.nospace() << "Queen";

    return debug;
}


///
/// \brief operator <<  This is a reimplementation of ChessPiece::operator<<().
///                     It is used to print info about this Queen into qDebug().
/// \sa                 ChessPiece::operator<<()
///
QDebug operator<<(QDebug debug, const QueenPiece& piece)
{
    return piece.print(debug);
}


///
/// \brief QueenPiece::addIfValid   If a position is a valid move, it will add to the vector
/// \param newMoves                 The QVector of moves to add to.
/// \param x                        The x position to move to.
/// \param y                        The y position to move to.
/// \param curPos                   The current position of the Queen.
/// \param board                    The current chess board.
/// \return                         True if further moves can be made through this tile,
///                                 false if something blocks the way.
///
bool QueenPiece::addIfValid(QVector<ChessMove>& newMoves, int x, int y, const ChessPosition& curPos, const QMap<ChessPosition, ChessPiece*>& board) const
{
    // Check if the position is on the board
    if(!ChessPosition::isValidPosition(x, y))
        return false;

    // Case: If position is unoccupied, the Queen may move there.
    ChessPosition newPos = ChessPosition((horizontal)x, (vertical)y);
    if(!board.contains(newPos))
    {
        newMoves.append(ChessMove(curPos, newPos, false));
        return true;
    }

    // Case: If position is occupied, Queen may only capture opposing pieces
    else
    {
        if(board[newPos]->isWhite() != isWhite())
            newMoves.append(ChessMove(curPos, newPos, true, newPos));

        return false;
    }
}
