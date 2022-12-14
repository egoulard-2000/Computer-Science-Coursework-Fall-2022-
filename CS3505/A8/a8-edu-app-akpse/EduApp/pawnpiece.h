/*
// File name: pawnpiece.h
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
//      pawnpiece.h is the header file for pawnpiece.cpp. Please see said file for details.
*/

#ifndef PAWNPIECE_H
#define PAWNPIECE_H

#include "chesspiece.h"

class PawnPiece : public ChessPiece
{
public:
    ///
    /// \brief PawnPiece::PawnPiece     This constructor simply over-rides
    ///                                 that of the ChessPiece class.
    /// \param white                    True if piece is white, false if black.
    /// \sa                             ChessPiece::ChessPiece()
    ///
    PawnPiece(bool white);

    ///
    /// \brief PawnPiece::possibleMoves     This is a reimplementation of
    ///                                     ChessPiece::possibleMoves().
    ///                                     It is used to return all the possible
    ///                                     ChessMoves that PawnPiece may do.
    /// \sa                                 ChessPiece::possibleMoves()
    ///
    virtual QVector<ChessMove> possibleMoves(const ChessPosition& currentPosition, const QMap<ChessPosition, ChessPiece*>& board) const override;

    ///
    /// \brief print    This is a reimplementation of ChessPiece::print().
    ///                 It is used to print info about this Pawn into qDebug().
    /// \sa             ChessPiece::print()
    ///
    virtual QDebug print(QDebug debug) const override;
};

///
/// \brief operator <<  This is a reimplementation of ChessPiece::operator<<().
///                     It is used to print info about this Pawn into qDebug().
/// \sa                 ChessPiece::operator<<()
///
QDebug operator<<(QDebug debug, const PawnPiece& piece);

#endif // PAWNPIECE_H
