/*
// File name: queenpiece.h
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
//      queenpiece.h is the header file for queenpiece.cpp. Please see said file for details.
*/

#ifndef QUEENPIECE_H
#define QUEENPIECE_H

#include "chesspiece.h"

class QueenPiece : public ChessPiece
{
public:
    ///
    /// \brief QueenPiece::QueenPiece   This constructor simply over-rides
    ///                                 that of the ChessPiece class.
    /// \param white                    True if piece is white, false if black.
    /// \sa                             ChessPiece::ChessPiece()
    ///
    QueenPiece(bool white);

    ///
    /// \brief QueenPiece::possibleMoves    This is a reimplementation of
    ///                                     ChessPiece::possibleMoves().
    ///                                     It is used to return all the possible
    ///                                     ChessMoves that QueenPiece may do.
    /// \sa                                 ChessPiece::possibleMoves()
    ///
    virtual QVector<ChessMove> possibleMoves(const ChessPosition& currentPosition, const QMap<ChessPosition, ChessPiece*>& board) const override;

    ///
    /// \brief print    This is a reimplementation of ChessPiece::print().
    ///                 It is used to print info about this Queen into qDebug().
    /// \sa             ChessPiece::print()
    ///
    virtual QDebug print(QDebug debug) const override;

private:
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
    bool addIfValid(QVector<ChessMove>& newMoves, int x, int y, const ChessPosition& curPos, const QMap<ChessPosition, ChessPiece*>& board) const;
};

///
/// \brief operator <<  This is a reimplementation of ChessPiece::operator<<().
///                     It is used to print info about this Queen into qDebug().
/// \sa                 ChessPiece::operator<<()
///
QDebug operator<<(QDebug debug, const QueenPiece& piece);

#endif // QUEENPIECE_H
