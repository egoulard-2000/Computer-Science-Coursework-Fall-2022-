/*
// File name: knightpiece.cpp
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
//      KnightPiece implements the ChessPiece class as a Knight.
            See ChessPiece.cpp for details.
*/

#include "knightpiece.h"

using horizontal = ChessPosition::horizontal;
using vertical = ChessPosition::vertical;


///
/// \brief KnightPiece::KnightPiece     This constructor simply over-rides
///                                     that of the ChessPiece class.
/// \param white                        True if piece is white, false if black.
/// \sa                                 ChessPiece::ChessPiece()
///
KnightPiece::KnightPiece(bool white) : ChessPiece(white)
{

}


///
/// \brief KnightPiece::possibleMoves   This is a reimplementation of
///                                     ChessPiece::possibleMoves().
///                                     It is used to return all the possible
///                                     ChessMoves that KnightPiece may do.
/// \sa                                 ChessPiece::possibleMoves()
///
QVector<ChessMove> KnightPiece::possibleMoves(const ChessPosition& curPos, const QMap<ChessPosition, ChessPiece*>& board) const
{
    // Initialize variables
    QVector<ChessMove> newMoves;

    // Find all potential positions that is an L shape away from the Knight.
    // Arrays stored as (x, y)
    QVector<std::array<int, 2>> LPositions;
    LPositions.append({curPos.hPos + 1, curPos.vPos + 2});
    LPositions.append({curPos.hPos + 2, curPos.vPos + 1});
    LPositions.append({curPos.hPos + 2, curPos.vPos - 1});
    LPositions.append({curPos.hPos + 1, curPos.vPos - 2});
    LPositions.append({curPos.hPos - 1, curPos.vPos - 2});
    LPositions.append({curPos.hPos - 2, curPos.vPos - 1});
    LPositions.append({curPos.hPos - 2, curPos.vPos + 1});
    LPositions.append({curPos.hPos - 1, curPos.vPos + 2});

    // Check the validity of all possible positions, and add if valid
    for(std::array<int, 2> pos : LPositions)
    {
        // Check if position is on the board
        if(!ChessPosition::isValidPosition(pos[0], pos[1]))
            continue;

        // Unoccupied positions may be moved to
        ChessPosition validPos = ChessPosition((horizontal)pos[0], (vertical)pos[1]);
        if(!board.contains(validPos))
            newMoves.append(ChessMove(curPos, validPos, false));
        // Occupied positions may only be moved to if an enemy piece is there
        else if(board[validPos]->isWhite() != isWhite())
            newMoves.append(ChessMove(curPos, validPos, true, validPos));
    }

    return newMoves;
}


///
/// \brief print    This is a reimplementation of ChessPiece::print().
///                 It is used to print info about this Knight into qDebug().
/// \sa             ChessPiece::print()
///
QDebug KnightPiece::print(QDebug debug) const
{
    QDebugStateSaver saver(debug);

    debug.nospace() << "Knight";

    return debug;
}


///
/// \brief operator <<  This is a reimplementation of ChessPiece::operator<<().
///                     It is used to print info about this Knight into qDebug().
/// \sa                 ChessPiece::operator<<()
///
QDebug operator<<(QDebug debug, const KnightPiece& piece)
{
    return piece.print(debug);
}
