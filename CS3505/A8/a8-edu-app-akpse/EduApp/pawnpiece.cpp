/*
// File name: pawnpiece.cpp
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
//      PawnPiece implements the ChessPiece class as a Pawn.
            See ChessPiece.cpp for details.
*/

#include "pawnpiece.h"

using horizontal = ChessPosition::horizontal;
using vertical = ChessPosition::vertical;


///
/// \brief PawnPiece::PawnPiece     This constructor simply over-rides
///                                 that of the ChessPiece class.
/// \param white                    True if piece is white, false if black.
/// \sa                             ChessPiece::ChessPiece()
///
PawnPiece::PawnPiece(bool white) : ChessPiece(white)
{

}

///
/// \brief PawnPiece::possibleMoves     This is a reimplementation of
///                                     ChessPiece::possibleMoves().
///                                     It is used to return all the possible
///                                     ChessMoves that PawnPiece may do.
/// \sa                                 ChessPiece::possibleMoves()
///
QVector<ChessMove> PawnPiece::possibleMoves(const ChessPosition& curPos, const QMap<ChessPosition, ChessPiece*>& board) const
{
    // Initialize variables
    QVector<ChessMove> newMoves;
    int posX;
    int posY;

    // Allow the pawn to move 1 space up, if it isn't already occupied
    posX = (int)curPos.hPos;
    posY = (int)curPos.vPos + 1;
    if(ChessPosition::isValidPosition(posX, posY))
    {
        ChessPosition newPos = ChessPosition((horizontal)posX, (vertical)posY);
        if(!board.contains(newPos))
            newMoves.append(ChessMove(curPos, newPos, false));
    }

    // Allow the pawn to move 2 spaces up, if it is its first turn (and no pieces block its way)
    if(curPos.vPos == vertical::v1)
    {
        ChessPosition newPos = ChessPosition(curPos.hPos, vertical::v3);
        ChessPosition inbetweenPos = ChessPosition(curPos.hPos, vertical::v2);
        if(!board.contains(inbetweenPos) && !board.contains(newPos))
            newMoves.append(ChessMove(curPos, newPos, false));
    }

    // Allow pawn to capture any enemy pieces at its upper left
    posX = (int)curPos.hPos - 1;
    posY = (int)curPos.vPos + 1;
    if(ChessPosition::isValidPosition(posX, posY))
    {
        ChessPosition newPos = ChessPosition((horizontal)posX, (vertical)posY);
        if(board.contains(newPos) && !board[newPos]->isWhite()) // If enemy exists at newPos
            newMoves.append(ChessMove(curPos, newPos, true, newPos));
    }

    // Allow pawn to capture any enemy pieces at its upper right
    posX = (int)curPos.hPos + 1;
    posY = (int)curPos.vPos + 1;
    if(ChessPosition::isValidPosition(posX, posY))
    {
        ChessPosition newPos = ChessPosition((horizontal)posX, (vertical)posY);
        if(board.contains(newPos) && !board[newPos]->isWhite()) // If enemy exists at newPos
            newMoves.append(ChessMove(curPos, newPos, true, newPos));
    }

    return newMoves;
}


///
/// \brief print    This is a reimplementation of ChessPiece::print().
///                 It is used to print info about this Pawn into qDebug().
/// \sa             ChessPiece::print()
///
QDebug PawnPiece::print(QDebug debug) const
{
    QDebugStateSaver saver(debug);

    debug.nospace() << "Pawn";

    return debug;
}


///
/// \brief operator <<  This is a reimplementation of ChessPiece::operator<<().
///                     It is used to print info about this Pawn into qDebug().
/// \sa                 ChessPiece::operator<<()
///
QDebug operator<<(QDebug debug, const PawnPiece& piece)
{
    return piece.print(debug);
}

