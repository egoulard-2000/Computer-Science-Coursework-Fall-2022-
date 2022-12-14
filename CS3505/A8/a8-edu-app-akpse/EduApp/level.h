/*
// File name: level.h
// Author:    Soli
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
//      level.h is the header file for level.cpp. Please see said file for details.
*/

#ifndef LEVEL_H
#define LEVEL_H

#include "chessposition.h"
#include "chesspiece.h"
#include "chessmove.h"
#include "leaderboard.h"
#include <QString>

class Level
{
public:
    Level();

    Leaderboard* leaderboard = new Leaderboard();

    // Getters and setters are better to ensure accidental sets don't occur

//    void setDisplayName(const QString& levelName);
//    QString getDisplayName() const;

    void setLevelNumber(int levelNum);
    int getLevelNumber() const;

    void setLevelName(QString levelName);
    QString getLevelName() const;

    void setLevelDifficulty(QString difficulty);
    QString getLevelDifficulty() const;

    void setInitialPieces(QMap<ChessPosition, ChessPiece*> initialPieces);
    QMap<ChessPosition, ChessPiece*> getInitialPiecesList() const;

    void setCorrectMoves(QVector<ChessMove> correctMoves);
    QVector<ChessMove> getCorrectMovesList() const;

    void setCpuMoves(QVector<ChessMove> cpuMoves);
    QVector<ChessMove> getCpuMovesList() const;

    QVector<QString> getNextCorrectMove() const;
    QVector<QString> getNextCpuMove() const;

private:
    int levelNumber;
    QString levelName;
    QString levelDifficulty;

    // The element returned is the piece at that location
    QMap<ChessPosition, ChessPiece*> initialPieces;

    // Has an ordered list of each piece to the right position
    QVector<ChessMove> correctMoves;

    // Has an ordered list of the CPU piece moved to its position
    QVector<ChessMove> cpuMoves;
};

#endif // LEVEL_H
