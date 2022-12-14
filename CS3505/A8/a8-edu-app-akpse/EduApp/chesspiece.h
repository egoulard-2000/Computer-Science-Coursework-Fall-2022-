/*
// File name: chesspiece.h
// Author:    Allen
// Assignment:Educational Program
// Group:     AKPSE
// Date:      12/8/2022
// Course:    CS 3505, University of Utah, School of Computing
// Copyright: CS 3505 and AKPSE - This work may not be copied for use in Academic Coursework.
//
// Our group, AKPSE, certifies that we wrote this code from scratch and did not copy it in part or whole from
// another source.
//
// File Contents
//
//      chesspiece.h is the header file for chesspiece.cpp. Please see said file for details.
*/

#ifndef CHESSPIECE_H
#define CHESSPIECE_H

#include <QObject>
#include "chessposition.h"
#include "chessmove.h"

class ChessPiece
{
public:

    ChessPiece(bool white);
    virtual ~ChessPiece();


    ///
    /// \brief possibleMoves    Returns all possible spaces this piece can move to.
    ///                         NOTE: The logic may be assumed to only apply
    ///                         for white/player pieces.
    /// \param currentPosition  The current position of the Chess Piece.
    /// \param board            A QMap representing chess pieces on a board.
    ///
    /// \return                 A QVector of all possible ChessPositions.
    ///
    virtual QVector<ChessMove> possibleMoves(const ChessPosition& currentPosition, const QMap<ChessPosition, ChessPiece*>& board) const = 0;


    ///
    /// \brief print    Prints the info in this ChessPiece into a QDebug.
    /// \param debug    The debug to insert into.
    ///
    virtual QDebug print(QDebug debug) const;

    ///
    /// \brief isWhite  Returns whether this ChessPiece is white or black.
    /// \return         True if white. False if black.
    ///
    bool isWhite() const;



private:
    // Determines Piece Color
    bool white;

};

///
/// \brief operator<<  Overloads the '<<' operator for  qDebug.
/// \param debug
/// \param piece       The ChessPiece to debug information from.
/// \return QDebug     The Debug Object to refer to when overloading.
///
QDebug operator<<(QDebug debug, const ChessPiece& piece);

#endif // CHESSPIECE_H
