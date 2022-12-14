/*
// File name: levelsdatabase.h
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
//      levelsdatabase.h is the header file for levelsdatabase.cpp. Please see said file for details.
*/

#ifndef LEVELSDATABASE_H
#define LEVELSDATABASE_H

#include "level.h"

class LevelsDatabase
{
public:
    LevelsDatabase();
    ~LevelsDatabase();

    Level getLevel(int levelId);

    int getTotalLevelCount() const;
    QVector<Level> getLevels() const;

private:
    QMap<int, Level> allLevels;

    Level oneEasy;
    Level twoEasy;
    Level threeEasy;
    Level fourEasy;
    Level oneMedium;
    Level twoMedium;
    Level threeMedium;
    Level fourMedium;
    Level oneHard;
    Level twoHard;
    Level threeHard;
    Level fourHard;

    QMap<ChessPosition, ChessPiece*> initialPiecesOneEasy;
    QMap<ChessPosition, ChessPiece*> initialPiecesTwoEasy;
    QMap<ChessPosition, ChessPiece*> initialPiecesThreeEasy;
    QMap<ChessPosition, ChessPiece*> initialPiecesFourEasy;
    QMap<ChessPosition, ChessPiece*> initialPiecesOneMedium;
    QMap<ChessPosition, ChessPiece*> initialPiecesTwoMedium;
    QMap<ChessPosition, ChessPiece*> initialPiecesThreeMedium;
    QMap<ChessPosition, ChessPiece*> initialPiecesFourMedium;
    QMap<ChessPosition, ChessPiece*> initialPiecesOneHard;
    QMap<ChessPosition, ChessPiece*> initialPiecesTwoHard;
    QMap<ChessPosition, ChessPiece*> initialPiecesThreeHard;
    QMap<ChessPosition, ChessPiece*> initialPiecesFourHard;

    QVector<ChessMove> correctMovesOneEasy;
    QVector<ChessMove> correctMovesTwoEasy;
    QVector<ChessMove> correctMovesThreeEasy;
    QVector<ChessMove> correctMovesFourEasy;
    QVector<ChessMove> correctMovesOneMedium;
    QVector<ChessMove> correctMovesTwoMedium;
    QVector<ChessMove> correctMovesThreeMedium;
    QVector<ChessMove> correctMovesFourMedium;
    QVector<ChessMove> correctMovesOneHard;
    QVector<ChessMove> correctMovesTwoHard;
    QVector<ChessMove> correctMovesThreeHard;
    QVector<ChessMove> correctMovesFourHard;

    QVector<ChessMove> cpuMovesOneEasy;
    QVector<ChessMove> cpuMovesTwoEasy;
    QVector<ChessMove> cpuMovesThreeEasy;
    QVector<ChessMove> cpuMovesFourEasy;
    QVector<ChessMove> cpuMovesOneMedium;
    QVector<ChessMove> cpuMovesTwoMedium;
    QVector<ChessMove> cpuMovesThreeMedium;
    QVector<ChessMove> cpuMovesFourMedium;
    QVector<ChessMove> cpuMovesOneHard;
    QVector<ChessMove> cpuMovesTwoHard;
    QVector<ChessMove> cpuMovesThreeHard;
    QVector<ChessMove> cpuMovesFourHard;

};

#endif // LEVELSDATABASE_H
