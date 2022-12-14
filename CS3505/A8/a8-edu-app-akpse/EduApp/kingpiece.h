/*
// File name: kingpiece.h
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
//      kingpiece.h is the header file for kingpiece.cpp. Please see said file for details.
*/

#ifndef KINGPIECE_H
#define KINGPIECE_H

#include <QMap>
#include "chessmove.h"
#include "chesspiece.h"


class KingPiece : public ChessPiece
{
public:
    ///
    /// \brief KingPiece::KingPiece     This constructor simply over-rides
    ///                                 that of the ChessPiece class.
    /// \param white                    True if piece is white, false if black.
    /// \sa                             ChessPiece::ChessPiece()
    ///
    KingPiece(bool white);

    ///
    /// \brief KingPiece::possibleMoves     This is a reimplementation of
    ///                                     ChessPiece::possibleMoves().
    ///                                     It is used to return all the possible
    ///                                     ChessMoves that KingPiece may do.
    /// \sa                                 ChessPiece::possibleMoves()
    ///
    virtual QVector<ChessMove> possibleMoves(const ChessPosition& currentPosition, const QMap<ChessPosition, ChessPiece*>& board) const override;

    ///
    /// \brief print    This is a reimplementation of ChessPiece::print().
    ///                 It is used to print info about this King into qDebug().
    /// \sa             ChessPiece::print()
    ///
    virtual QDebug print(QDebug debug) const override;

private:
    ///
    /// \brief KingPiece::addIfValid    If a position is a valid move, it will add to the vector.
    /// \param newMoves                 The QVector of moves to add to.
    /// \param x                        The x position to move to.
    /// \param y                        The y position to move to.
    /// \param curPos                   The current position of the King
    /// \param board                    The current chess board.
    ///
    void addIfValid(QVector<ChessMove>& newMoves, int x, int y, const ChessPosition& curPos, const QMap<ChessPosition, ChessPiece*>&) const;

};

///
/// \brief operator <<  This is a reimplementation of ChessPiece::operator<<().
///                     It is used to print info about this King into qDebug().
/// \sa                 ChessPiece::operator<<()
///
QDebug operator<<(QDebug debug, const KingPiece& piece);

#endif // KINGPIECE_H
