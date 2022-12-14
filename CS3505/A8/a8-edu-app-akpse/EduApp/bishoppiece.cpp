/*
// File name: bishoppiece.cpp
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
//      BishopPiece implements the ChessPiece class as a Bishop.
            See ChessPiece.cpp for details.
*/

#include "bishoppiece.h"

using horizontal = ChessPosition::horizontal;
using vertical = ChessPosition::vertical;


///
/// \brief BishopPiece::BishopPiece     This constructor simply over-rides
///                                     that of the ChessPiece class.
/// \param white                        True if piece is white, false if black.
/// \sa                                 ChessPiece::ChessPiece()
///
BishopPiece::BishopPiece(bool white) : ChessPiece(white)
{

}


///
/// \brief BishopPiece::possibleMoves   This is a reimplementation of
///                                     ChessPiece::possibleMoves().
///                                     It is used to return all the possible
///                                     ChessMoves that BishopPiece may do.
/// \sa                                 ChessPiece::possibleMoves()
///
QVector<ChessMove> BishopPiece::possibleMoves(const ChessPosition& curPos, const QMap<ChessPosition, ChessPiece*>& board) const
{
    // Initialize variables
    QVector<ChessMove> newMoves;
    int posX;
    int posY;

    // Add all upperleft moves
    posX = curPos.hPos - 1;
    posY = curPos.vPos + 1;
    while(addIfValid(newMoves, posX, posY, curPos, board))
    {
        posX -= 1;
        posY += 1;
    }

    // Add all upper right moves
    posX = curPos.hPos + 1;
    posY = curPos.vPos + 1;
    while(addIfValid(newMoves, posX, posY, curPos, board))
    {
        posX += 1;
        posY += 1;
    }

    // Add all bottom left moves
    posX = curPos.hPos - 1;
    posY = curPos.vPos - 1;
    while(addIfValid(newMoves, posX, posY, curPos, board))
    {
        posX -= 1;
        posY -= 1;
    }

    // Add all bottom right moves
    posX = curPos.hPos + 1;
    posY = curPos.vPos - 1;
    while(addIfValid(newMoves, posX, posY, curPos, board))
    {
        posX += 1;
        posY -= 1;
    }

    return newMoves;
}


///
/// \brief print    This is a reimplementation of ChessPiece::print().
///                 It is used to print info about this Bishop into qDebug().
/// \sa             ChessPiece::print()
///
QDebug BishopPiece::print(QDebug debug) const
{
    QDebugStateSaver saver(debug);

    debug.nospace() << "Bishop";

    return debug;
}


///
/// \brief operator <<  This is a reimplementation of ChessPiece::operator<<().
///                     It is used to print info about this Bishop into qDebug().
/// \sa                 ChessPiece::operator<<()
///
QDebug operator<<(QDebug debug, const BishopPiece& piece)
{
    return piece.print(debug);
}


///
/// \brief BishopPiece::addIfValid  If a position is a valid move, it will add to the vector
/// \param newMoves                 The QVector of moves to add to.
/// \param x                        The x position to move to.
/// \param y                        The y position to move to.
/// \param curPos                   The current position of the Bishop.
/// \param board                    The current chess board.
/// \return                         True if further moves can be made through this tile,
///                                 false if something blocks the way.
///
bool BishopPiece::addIfValid(QVector<ChessMove>& newMoves, int x, int y, const ChessPosition& curPos, const QMap<ChessPosition, ChessPiece*>& board) const
{
    // Check if the position is on the board
    if(!ChessPosition::isValidPosition(x, y))
        return false;

    // Case: If position is unoccupied, the Bishop may move there.
    ChessPosition newPos = ChessPosition((horizontal)x, (vertical)y);
    if(!board.contains(newPos))
    {
        newMoves.append(ChessMove(curPos, newPos, false));
        return true;
    }

    // Case: If position is occupied, Bishop may only capture opposing pieces
    else
    {
        if(board[newPos]->isWhite() != isWhite())
            newMoves.append(ChessMove(curPos, newPos, true, newPos));

        return false;
    }
}
