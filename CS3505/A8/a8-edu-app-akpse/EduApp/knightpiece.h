/*
// File name: knightpiece.h
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
//      knightpiece.h is the header file for knightpiece.cpp. Please see said file for details.
*/

#ifndef KNIGHTPIECE_H
#define KNIGHTPIECE_H

#include "chesspiece.h"

class KnightPiece : public ChessPiece
{
public:
    ///
    /// \brief KnightPiece::KnightPiece     This constructor simply over-rides
    ///                                     that of the ChessPiece class.
    /// \param white                        True if piece is white, false if black.
    /// \sa                                 ChessPiece::ChessPiece()
    ///
    KnightPiece(bool white);

    ///
    /// \brief KnightPiece::possibleMoves   This is a reimplementation of
    ///                                     ChessPiece::possibleMoves().
    ///                                     It is used to return all the possible
    ///                                     ChessMoves that KnightPiece may do.
    /// \sa                                 ChessPiece::possibleMoves()
    ///
    virtual QVector<ChessMove> possibleMoves(const ChessPosition& currentPosition, const QMap<ChessPosition, ChessPiece*>& board) const override;

    ///
    /// \brief print    This is a reimplementation of ChessPiece::print().
    ///                 It is used to print info about this Knight into qDebug().
    /// \sa             ChessPiece::print()
    ///
    virtual QDebug print(QDebug debug) const override;

};

///
/// \brief operator <<  This is a reimplementation of ChessPiece::operator<<().
///                     It is used to print info about this Knight into qDebug().
/// \sa                 ChessPiece::operator<<()
///
QDebug operator<<(QDebug debug, const KnightPiece& piece);

#endif // KNIGHTPIECE_H
