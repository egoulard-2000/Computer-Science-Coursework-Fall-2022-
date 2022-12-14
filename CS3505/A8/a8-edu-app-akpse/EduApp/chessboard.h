/*
// File name: chessboard.h
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
//      chessboard.h is the header file for chessboard.cpp. Please see said file for details.
*/

#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include <QObject>
#include <QMap>
#include "chessmove.h"
#include "chesspiece.h"


class ChessBoard
{
public:
    ChessBoard(QMap<ChessPosition, ChessPiece*> initialBoard = QMap<ChessPosition, ChessPiece*>());

    ~ChessBoard();

    void addPiece(ChessPosition pos, ChessPiece* newPiece);
    void movePiece(ChessMove move);
    bool hasPiece(const ChessPosition& pos) const;
    ChessPiece* getPiece(const ChessPosition& pos) const;
    QVector<ChessMove> getMoves(ChessPosition pos) const;
    QMap<ChessPosition, ChessPiece*> getAllPieces() const;


private:
    QMap<ChessPosition, ChessPiece*> pieces;
};

QDebug operator<<(QDebug debug, const ChessBoard& board);

#endif // CHESSBOARD_H
