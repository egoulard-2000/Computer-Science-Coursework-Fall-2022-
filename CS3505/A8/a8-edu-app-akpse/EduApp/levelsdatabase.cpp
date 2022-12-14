/*
// File name: levelsdatabase.cpp
// Author:    Soli, Michael
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
//      This file contains all the information for each level.
*/

#include "levelsdatabase.h"
#include "bishoppiece.h"
#include "kingpiece.h"
#include "knightpiece.h"
#include "pawnpiece.h"
#include "queenpiece.h"
#include "rookpiece.h"

using horizontal = ChessPosition::horizontal;
using vertical = ChessPosition::vertical;

///
/// \brief LevelsDatabase::LevelsDatabase
///  This database stores all of the information about each level.
///  That information being: locations of pieces, which moves are the correct moves to make
///  and which moves the CPU will make in response to the player.
///
LevelsDatabase::LevelsDatabase()
{

    oneEasy.setLevelNumber(1864);
    oneEasy.setLevelName("Dual Bishop");
    oneEasy.setLevelDifficulty("Easy");
    // Black King
    initialPiecesOneEasy.insert(
                ChessPosition(ChessPosition::h0, ChessPosition::v7),
                new KingPiece(false));

    // White King
    initialPiecesOneEasy.insert(
                ChessPosition(ChessPosition::h1, ChessPosition::v5),
                new KingPiece(true));

    // White Bishop
    initialPiecesOneEasy.insert(
                ChessPosition(ChessPosition::h5, ChessPosition::v4),
                new BishopPiece(true));

    // White Bishop
    initialPiecesOneEasy.insert(
                ChessPosition(ChessPosition::h5, ChessPosition::v3),
                new BishopPiece(true));

    correctMovesOneEasy.append(
                ChessMove(ChessPosition(ChessPosition::h5, ChessPosition::v4),
                ChessPosition(ChessPosition::h4, ChessPosition::v3),
                false));

    oneEasy.setInitialPieces(initialPiecesOneEasy);
    oneEasy.setCorrectMoves(correctMovesOneEasy);
    oneEasy.setCpuMoves(cpuMovesOneEasy);

    twoEasy.setLevelNumber(1888);
    twoEasy.setLevelName("Arabian Mate");
    twoEasy.setLevelDifficulty("Easy");

    // White King
    initialPiecesTwoEasy.insert(
                ChessPosition(ChessPosition::h7, ChessPosition::v0),
                new KingPiece(true));

    // White Knight
    initialPiecesTwoEasy.insert(
                ChessPosition(ChessPosition::h5, ChessPosition::v5),
                new KnightPiece(true));

    // White Rook
    initialPiecesTwoEasy.insert(
                ChessPosition(ChessPosition::h5, ChessPosition::v6),
                new RookPiece(true));

    // Black King
    initialPiecesTwoEasy.insert(
                ChessPosition(ChessPosition::h7, ChessPosition::v7),
                new KingPiece(false));

    // Set player's correct moves

    // White Rook First Move
    correctMovesTwoEasy.append(
                ChessMove(ChessPosition(ChessPosition::h5, ChessPosition::v6),
                ChessPosition(ChessPosition::h7, ChessPosition::v6),
                false));

    twoEasy.setInitialPieces(initialPiecesTwoEasy);
    twoEasy.setCorrectMoves(correctMovesTwoEasy);

    threeEasy.setLevelNumber(2078);
    threeEasy.setLevelName("Morphy's Mate");
    threeEasy.setLevelDifficulty("Easy");

    // White Rook
    initialPiecesThreeEasy.insert(
                ChessPosition(ChessPosition::h6, ChessPosition::v0),
                new RookPiece(true));

    // White Bishop
    initialPiecesThreeEasy.insert(
                ChessPosition(ChessPosition::h7, ChessPosition::v3),
                new BishopPiece(true));

    // White King
    initialPiecesThreeEasy.insert(
                ChessPosition(ChessPosition::h7, ChessPosition::v0),
                new KingPiece(true));

    // Black King
    initialPiecesThreeEasy.insert(
                ChessPosition(ChessPosition::h7, ChessPosition::v7),
                new KingPiece(false));

    // Black Pawn
    initialPiecesThreeEasy.insert(
                ChessPosition(ChessPosition::h7, ChessPosition::v6),
                new PawnPiece(false));

    // Black Pawn
    initialPiecesThreeEasy.insert(
                ChessPosition(ChessPosition::h5, ChessPosition::v6),
                new PawnPiece(false));

    // Set player's correct moves
    // White Bishop First Move
    correctMovesThreeEasy.append(
                ChessMove(ChessPosition(ChessPosition::h7, ChessPosition::v3),
                ChessPosition(ChessPosition::h5, ChessPosition::v5),
                true));

    threeEasy.setInitialPieces(initialPiecesThreeEasy);
    threeEasy.setCorrectMoves(correctMovesThreeEasy);

    fourEasy.setLevelNumber(1986);
    fourEasy.setLevelName("Pillsbury Mate");
    fourEasy.setLevelDifficulty("Easy");

    // White King
    initialPiecesFourEasy.insert(
                ChessPosition(ChessPosition::h4, ChessPosition::v0),
                new KingPiece(true));

    // White Bishop
    initialPiecesFourEasy.insert(
                ChessPosition(ChessPosition::h1, ChessPosition::v1),
                new BishopPiece(true));


    // White Rook
    initialPiecesFourEasy.insert(
                ChessPosition(ChessPosition::h7, ChessPosition::v0),
                new RookPiece(true));

    // Black King
    initialPiecesFourEasy.insert(
                ChessPosition(ChessPosition::h6, ChessPosition::v7),
                new KingPiece(false));

    // Black Pawn
    initialPiecesFourEasy.insert(
                ChessPosition(ChessPosition::h5, ChessPosition::v6),
                new PawnPiece(false));

    // Black Pawn
    initialPiecesFourEasy.insert(
                ChessPosition(ChessPosition::h7, ChessPosition::v6),
                new PawnPiece(false));

    // Black Rook
    initialPiecesFourEasy.insert(
                ChessPosition(ChessPosition::h5, ChessPosition::v7),
                new PawnPiece(false));

    // Set player's correct moves
    // White Rook First Move
    correctMovesFourEasy.append(
                ChessMove(ChessPosition(ChessPosition::h7, ChessPosition::v0),
                ChessPosition(ChessPosition::h6, ChessPosition::v0),
                true));

    fourEasy.setInitialPieces(initialPiecesFourEasy);
    fourEasy.setCorrectMoves(correctMovesFourEasy);

    oneMedium.setLevelNumber(2071);
    oneMedium.setLevelName("Back - Rank Checkmate");
    oneMedium.setLevelDifficulty("Medium");

    // White King
    initialPiecesOneMedium.insert(
                ChessPosition(ChessPosition::h6, ChessPosition::v0),
                new KingPiece(true));

    // White Queen
    initialPiecesOneMedium.insert(
                ChessPosition(ChessPosition::h0, ChessPosition::v3),
                new QueenPiece(true));

    // White Rook
    initialPiecesOneMedium.insert(
                ChessPosition(ChessPosition::h4, ChessPosition::v0),
                new RookPiece(true));

    // White Pawn1
    initialPiecesOneMedium.insert(
                ChessPosition(ChessPosition::h5, ChessPosition::v1),
                new PawnPiece(true));

    // White Pawn2
    initialPiecesOneMedium.insert(
                ChessPosition(ChessPosition::h6, ChessPosition::v1),
                new PawnPiece(true));

    // White Pawn3
    initialPiecesOneMedium.insert(
                ChessPosition(ChessPosition::h7, ChessPosition::v1),
                new PawnPiece(true));

    // Black King
    initialPiecesOneMedium.insert(
                ChessPosition(ChessPosition::h6, ChessPosition::v7),
                new KingPiece(false));

    // Black Rook
    initialPiecesOneMedium.insert(
                ChessPosition(ChessPosition::h4, ChessPosition::v7),
                new RookPiece(false));

    // Black Rook2
    initialPiecesOneMedium.insert(
                ChessPosition(ChessPosition::h2, ChessPosition::v7),
                new RookPiece(false));

    // Black Pawn1
    initialPiecesOneMedium.insert(
                ChessPosition(ChessPosition::h5, ChessPosition::v6),
                new PawnPiece(false));

    // Black Pawn2
    initialPiecesOneMedium.insert(
                ChessPosition(ChessPosition::h6, ChessPosition::v6),
                new PawnPiece(false));

    // Black Pawn3
    initialPiecesOneMedium.insert(
                ChessPosition(ChessPosition::h7, ChessPosition::v6),
                new PawnPiece(false));

    // Set player's correct moves
    // White Queen First Move
    correctMovesOneMedium.append(
                ChessMove(ChessPosition(ChessPosition::h0, ChessPosition::v3),
                ChessPosition(ChessPosition::h4, ChessPosition::v7),
                true));

    // White Rook First Move
    correctMovesOneMedium.append(
                ChessMove(ChessPosition(ChessPosition::h4, ChessPosition::v0),
                ChessPosition(ChessPosition::h4, ChessPosition::v7),
                true));

    // Set CPU's correct moves

    // Black Rook First move
    cpuMovesOneMedium.append(
                ChessMove(ChessPosition(ChessPosition::h2, ChessPosition::v7),
                ChessPosition(ChessPosition::h4, ChessPosition::v7),
                true));


    oneMedium.setInitialPieces(initialPiecesOneMedium);
    oneMedium.setCorrectMoves(correctMovesOneMedium);
    oneMedium.setCpuMoves(cpuMovesOneMedium);

    twoMedium.setLevelNumber(2095);
    twoMedium.setLevelName("Anastasia's Checkmate");
    twoMedium.setLevelDifficulty("Medium");

    // White King
    initialPiecesTwoMedium.insert(
                ChessPosition(ChessPosition::h6, ChessPosition::v0),
                new KingPiece(true));

    // White Queen
    initialPiecesTwoMedium.insert(
                ChessPosition(ChessPosition::h4, ChessPosition::v3),
                new QueenPiece(true));

    // White Rook
    initialPiecesTwoMedium.insert(
                ChessPosition(ChessPosition::h2, ChessPosition::v4),
                new RookPiece(true));

    // White Pawn1
    initialPiecesTwoMedium.insert(
                ChessPosition(ChessPosition::h5, ChessPosition::v1),
                new PawnPiece(true));

    // White Pawn2
    initialPiecesTwoMedium.insert(
                ChessPosition(ChessPosition::h6, ChessPosition::v1),
                new PawnPiece(true));

    // White Pawn3
    initialPiecesTwoMedium.insert(
                ChessPosition(ChessPosition::h7, ChessPosition::v1),
                new PawnPiece(true));

    // White Knight
    initialPiecesTwoMedium.insert(
                ChessPosition(ChessPosition::h4, ChessPosition::v6),
                new KnightPiece(true));

    // Black King
    initialPiecesTwoMedium.insert(
                ChessPosition(ChessPosition::h7, ChessPosition::v7),
                new KingPiece(false));

    // Black Rook
    initialPiecesTwoMedium.insert(
                ChessPosition(ChessPosition::h5, ChessPosition::v7),
                new RookPiece(false));

    // Black Pawn1
    initialPiecesTwoMedium.insert(
                ChessPosition(ChessPosition::h5, ChessPosition::v6),
                new PawnPiece(false));

    // Black Pawn2
    initialPiecesTwoMedium.insert(
                ChessPosition(ChessPosition::h6, ChessPosition::v6),
                new PawnPiece(false));

    // Black Pawn3
    initialPiecesTwoMedium.insert(
                ChessPosition(ChessPosition::h7, ChessPosition::v6),
                new PawnPiece(false));

    // Black Bishop
    initialPiecesTwoMedium.insert(
                ChessPosition(ChessPosition::h1, ChessPosition::v6),
                new BishopPiece(false));

//    // Set player's correct moves

    // White Queen First Move
    correctMovesTwoMedium.append(
                ChessMove(ChessPosition(ChessPosition::h4, ChessPosition::v3),
                ChessPosition(ChessPosition::h7, ChessPosition::v6),
                true));

    // White Rook First Move
    correctMovesTwoMedium.append(
                ChessMove(ChessPosition(ChessPosition::h2, ChessPosition::v4),
                ChessPosition(ChessPosition::h7, ChessPosition::v4),
                true));

    // Black King First Move
    cpuMovesTwoMedium.append(
                ChessMove(ChessPosition(ChessPosition::h7, ChessPosition::v7),
                ChessPosition(ChessPosition::h7, ChessPosition::v6),
                true));

    twoMedium.setInitialPieces(initialPiecesTwoMedium);

    twoMedium.setCorrectMoves(correctMovesTwoMedium);
    twoMedium.setCpuMoves(cpuMovesTwoMedium);

    threeMedium.setLevelNumber(2285);
    threeMedium.setLevelName("Smothered Checkmate");
    threeMedium.setLevelDifficulty("Medium");


    // White King
    initialPiecesThreeMedium.insert(
                ChessPosition(ChessPosition::h6, ChessPosition::v0),
                new KingPiece(true));

    // White Queen
    initialPiecesThreeMedium.insert(
                ChessPosition(ChessPosition::h7, ChessPosition::v2),
                new QueenPiece(true));

    // White Pawn1
    initialPiecesThreeMedium.insert(
                ChessPosition(ChessPosition::h6, ChessPosition::v1),
                new PawnPiece(true));

    // White Pawn2
    initialPiecesThreeMedium.insert(
                ChessPosition(ChessPosition::h7, ChessPosition::v1),
                new PawnPiece(true));

    // White Knight
    initialPiecesThreeMedium.insert(
                ChessPosition(ChessPosition::h6, ChessPosition::v4),
                new KnightPiece(true));


    // Black King
    initialPiecesThreeMedium.insert(
                ChessPosition(ChessPosition::h7, ChessPosition::v7),
                new KingPiece(false));

    // Black Rook
    initialPiecesThreeMedium.insert(
                ChessPosition(ChessPosition::h6, ChessPosition::v7),
                new RookPiece(false));

    // Black Pawn1
    initialPiecesThreeMedium.insert(
                ChessPosition(ChessPosition::h6, ChessPosition::v6),
                new PawnPiece(false));

    // Black Pawn2
    initialPiecesThreeMedium.insert(
                ChessPosition(ChessPosition::h7, ChessPosition::v6),
                new PawnPiece(false));

    // Black Queen
    initialPiecesThreeMedium.insert(
                ChessPosition(ChessPosition::h6, ChessPosition::v5),
                new QueenPiece(false));

    // Set player's correct moves
    // White Queen First Move
    correctMovesThreeMedium.append(
                ChessMove(ChessPosition(ChessPosition::h7, ChessPosition::v2),
                ChessPosition(ChessPosition::h7, ChessPosition::v6),
                true));
    // White Knight First Move
    correctMovesThreeMedium.append(
                ChessMove(ChessPosition(ChessPosition::h6, ChessPosition::v4),
                ChessPosition(ChessPosition::h5, ChessPosition::v6),
                false));

    // Black Queen First move
    cpuMovesThreeMedium.append(
                ChessMove(ChessPosition(ChessPosition::h6, ChessPosition::v5),
                ChessPosition(ChessPosition::h7, ChessPosition::v6),
                true));

    threeMedium.setInitialPieces(initialPiecesThreeMedium);
    threeMedium.setCorrectMoves(correctMovesThreeMedium);
    threeMedium.setCpuMoves(cpuMovesThreeMedium);

    fourMedium.setLevelNumber(2193);
    fourMedium.setLevelName("Vukovic Checkmate");
    fourMedium.setLevelDifficulty("Medium");

    // White King
    initialPiecesFourMedium.insert(
                ChessPosition(ChessPosition::h5, ChessPosition::v4),
                new KingPiece(true));

    // White Knight
    initialPiecesFourMedium.insert(
                ChessPosition(ChessPosition::h4, ChessPosition::v3),
                new KnightPiece(true));

    // White Rook
    initialPiecesFourMedium.insert(
                ChessPosition(ChessPosition::h6, ChessPosition::v3),
                new RookPiece(true));

    // White Pawn
    initialPiecesFourMedium.insert(
                ChessPosition(ChessPosition::h7, ChessPosition::v2),
                new PawnPiece(true));

    // Black King
    initialPiecesFourMedium.insert(
                ChessPosition(ChessPosition::h7, ChessPosition::v4),
                new KingPiece(false));

    // Black Rook
    initialPiecesFourMedium.insert(
                ChessPosition(ChessPosition::h2, ChessPosition::v7),
                new RookPiece(false));

    // Set player's correct moves
    // White Knight First Move
    correctMovesFourMedium.append(
                ChessMove(ChessPosition(ChessPosition::h4, ChessPosition::v3),
                ChessPosition(ChessPosition::h5, ChessPosition::v5),
                true));

    // White Rook First Move
    correctMovesFourMedium.append(
                ChessMove(ChessPosition(ChessPosition::h6, ChessPosition::v3),
                ChessPosition(ChessPosition::h6, ChessPosition::v5),
                false));

    // Black King First move
    cpuMovesFourMedium.append(
                ChessMove(ChessPosition(ChessPosition::h7, ChessPosition::v4),
                ChessPosition(ChessPosition::h7, ChessPosition::v5),
                false));

    fourMedium.setInitialPieces(initialPiecesFourMedium);
    fourMedium.setCorrectMoves(correctMovesFourMedium);
    fourMedium.setCpuMoves(cpuMovesFourMedium);

    oneHard.setLevelNumber(1845);
    oneHard.setLevelName("Hard Dual Bishop Checkmate");
    oneHard.setLevelDifficulty("Hard");

    // White Bishop1
    initialPiecesOneHard.insert(
                ChessPosition(ChessPosition::h6, ChessPosition::v3),
                new BishopPiece(true));

    // White Bishop2
    initialPiecesOneHard.insert(
                ChessPosition(ChessPosition::h4, ChessPosition::v4),
                new BishopPiece(true));

    // White King
    initialPiecesOneHard.insert(
                ChessPosition(ChessPosition::h1, ChessPosition::v5),
                new KingPiece(true));

    // Black King
    initialPiecesOneHard.insert(
                ChessPosition(ChessPosition::h1, ChessPosition::v7),
                new KingPiece(false));

    // Black Knight
    initialPiecesOneHard.insert(
                ChessPosition(ChessPosition::h2, ChessPosition::v6),
                new KnightPiece(false));

    // Black Bishop
    initialPiecesOneHard.insert(
                ChessPosition(ChessPosition::h3, ChessPosition::v7),
                new BishopPiece(false));

    // Set player's correct moves
    // White Bishop1 First Move
    correctMovesOneHard.append(
                ChessMove(ChessPosition(ChessPosition::h6, ChessPosition::v3),
                ChessPosition(ChessPosition::h3, ChessPosition::v6),
                true));

    // White Bishop1 Second Move
    correctMovesOneHard.append(
                ChessMove(ChessPosition(ChessPosition::h3, ChessPosition::v6),
                ChessPosition(ChessPosition::h2, ChessPosition::v5),
                false));

    // White Bishop1 Third Move
    correctMovesOneHard.append(
                ChessMove(ChessPosition(ChessPosition::h2, ChessPosition::v5),
                ChessPosition(ChessPosition::h1, ChessPosition::v6),
                false));

    // White Bishop2 First Move
    correctMovesOneHard.append(
                ChessMove(ChessPosition(ChessPosition::h4, ChessPosition::v4),
                ChessPosition(ChessPosition::h2, ChessPosition::v6),
                true));

    // Set CPU's correct moves

    // Black King First move
    cpuMovesOneHard.append(
                ChessMove(ChessPosition(ChessPosition::h1, ChessPosition::v7),
                ChessPosition(ChessPosition::h0, ChessPosition::v7),
                false));

    // Black King Second move
    cpuMovesOneHard.append(
                ChessMove(ChessPosition(ChessPosition::h0, ChessPosition::v7),
                ChessPosition(ChessPosition::h1, ChessPosition::v7),
                false));

    // Black Bishop First move
    cpuMovesOneHard.append(
                ChessMove(ChessPosition(ChessPosition::h3, ChessPosition::v7),
                ChessPosition(ChessPosition::h7, ChessPosition::v3),
                false));

    oneHard.setInitialPieces(initialPiecesOneHard);
    oneHard.setCorrectMoves(correctMovesOneHard);
    oneHard.setCpuMoves(cpuMovesOneHard);

    twoHard.setLevelNumber(1869);
    twoHard.setLevelName("Hook Checkmate");
    twoHard.setLevelDifficulty("Hard");


    // White King
    initialPiecesTwoHard.insert(
                ChessPosition(ChessPosition::h6, ChessPosition::v0),
                new KingPiece(true));

    // White Pawn1
    initialPiecesTwoHard.insert(
                ChessPosition(ChessPosition::h4, ChessPosition::v1),
                new PawnPiece(true));

    // White Pawn2
    initialPiecesTwoHard.insert(
                ChessPosition(ChessPosition::h5, ChessPosition::v1),
                new PawnPiece(true));

    // White Pawn3
    initialPiecesTwoHard.insert(
                ChessPosition(ChessPosition::h6, ChessPosition::v2),
                new PawnPiece(true));

    // White Pawn4
    initialPiecesTwoHard.insert(
                ChessPosition(ChessPosition::h0, ChessPosition::v5),
                new PawnPiece(true));

    // White Knight1
    initialPiecesTwoHard.insert(
                ChessPosition(ChessPosition::h7, ChessPosition::v3),
                new KnightPiece(true));

    // White Knight2
    initialPiecesTwoHard.insert(
                ChessPosition(ChessPosition::h5, ChessPosition::v4),
                new KnightPiece(true));

    // White Rook1
    initialPiecesTwoHard.insert(
                ChessPosition(ChessPosition::h2, ChessPosition::v6),
                new RookPiece(true));

    // White Rook2
    initialPiecesTwoHard.insert(
                ChessPosition(ChessPosition::h4, ChessPosition::v6),
                new RookPiece(true));

    // Black King
    initialPiecesTwoHard.insert(
                ChessPosition(ChessPosition::h6, ChessPosition::v4),
                new KingPiece(false));

    // Black Pawn1
    initialPiecesTwoHard.insert(
                ChessPosition(ChessPosition::h6, ChessPosition::v3),
                new PawnPiece(false));

    // Black Pawn2
    initialPiecesTwoHard.insert(
                ChessPosition(ChessPosition::h7, ChessPosition::v4),
                new PawnPiece(false));

    // Black Pawn3
    initialPiecesTwoHard.insert(
                ChessPosition(ChessPosition::h2, ChessPosition::v4),
                new PawnPiece(false));

    // Black Bishop1
    initialPiecesTwoHard.insert(
                ChessPosition(ChessPosition::h2, ChessPosition::v3),
                new BishopPiece(false));

    // Black Bishop1
    initialPiecesTwoHard.insert(
                ChessPosition(ChessPosition::h7, ChessPosition::v7),
                new BishopPiece(false));

    // Black Rook1
    initialPiecesTwoHard.insert(
                ChessPosition(ChessPosition::h5, ChessPosition::v5),
                new RookPiece(false));

    // Black Rook2
    initialPiecesTwoHard.insert(
                ChessPosition(ChessPosition::h5, ChessPosition::v7),
                new RookPiece(false));

//    // Set player's correct moves

    // White Rook1 First Move
    correctMovesTwoHard.append(
                ChessMove(ChessPosition(ChessPosition::h4, ChessPosition::v6),
                ChessPosition(ChessPosition::h6, ChessPosition::v6),
                false));

    // White Rook2 First Move
    correctMovesTwoHard.append(
                ChessMove(ChessPosition(ChessPosition::h2, ChessPosition::v6),
                ChessPosition(ChessPosition::h6, ChessPosition::v6),
                true));

    // White Rook2 Second Move
    correctMovesTwoHard.append(
                ChessMove(ChessPosition(ChessPosition::h6, ChessPosition::v6),
                ChessPosition(ChessPosition::h6,ChessPosition::v5),
                true));

    // Black Bishop First Move
    cpuMovesTwoHard.append(
                ChessMove(ChessPosition(ChessPosition::h7, ChessPosition::v7),
                ChessPosition(ChessPosition::h6, ChessPosition::v6),
                true));
    // Black Rook1 First Move
    cpuMovesTwoHard.append(
                ChessMove(ChessPosition(ChessPosition::h5, ChessPosition::v5),
                ChessPosition(ChessPosition::h6, ChessPosition::v5),
                false));

    twoHard.setInitialPieces(initialPiecesTwoHard);

    twoHard.setCorrectMoves(correctMovesTwoHard);
    twoHard.setCpuMoves(cpuMovesTwoHard);

    threeHard.setLevelNumber(2059);
    threeHard.setLevelName("Opera Checkmate");
    threeHard.setLevelDifficulty("Hard");


    // White King
    initialPiecesThreeHard.insert(
                ChessPosition(ChessPosition::h1, ChessPosition::v0),
                new KingPiece(true));

    // White Rook1
    initialPiecesThreeHard.insert(
                ChessPosition(ChessPosition::h2, ChessPosition::v0),
                new RookPiece(true));

    // White Knight
    initialPiecesThreeHard.insert(
                ChessPosition(ChessPosition::h6, ChessPosition::v0),
                new KnightPiece(true));

    // White Rook2
    initialPiecesThreeHard.insert(
                ChessPosition(ChessPosition::h7, ChessPosition::v0),
                new RookPiece(true));

    // White Bishop
    initialPiecesThreeHard.insert(
                ChessPosition(ChessPosition::h2, ChessPosition::v3),
                new BishopPiece(true));

    // White Queen
    initialPiecesThreeHard.insert(
                ChessPosition(ChessPosition::h5, ChessPosition::v4),
                new QueenPiece(true));

    // White Pawn1
    initialPiecesThreeHard.insert(
                ChessPosition(ChessPosition::h0, ChessPosition::v1),
                new PawnPiece(true));

    // White Pawn2
    initialPiecesThreeHard.insert(
                ChessPosition(ChessPosition::h1, ChessPosition::v1),
                new PawnPiece(true));

    // White Pawn3
    initialPiecesThreeHard.insert(
                ChessPosition(ChessPosition::h3, ChessPosition::v3),
                new PawnPiece(true));

    // White Pawn4
    initialPiecesThreeHard.insert(
                ChessPosition(ChessPosition::h5, ChessPosition::v2),
                new PawnPiece(true));

    // White Pawn4
    initialPiecesThreeHard.insert(
                ChessPosition(ChessPosition::h7, ChessPosition::v1),
                new PawnPiece(true));

    // Black King
    initialPiecesThreeHard.insert(
                ChessPosition(ChessPosition::h3, ChessPosition::v7),
                new KingPiece(false));

    // Black Queen
    initialPiecesThreeHard.insert(
                ChessPosition(ChessPosition::h6, ChessPosition::v5),
                new QueenPiece(false));

    // Black Rook1
    initialPiecesThreeHard.insert(
                ChessPosition(ChessPosition::h0, ChessPosition::v7),
                new RookPiece(false));

    // Black Rook2
    initialPiecesThreeHard.insert(
                ChessPosition(ChessPosition::h7, ChessPosition::v7),
                new RookPiece(false));

    // Black Knight
    initialPiecesThreeHard.insert(
                ChessPosition(ChessPosition::h1, ChessPosition::v7),
                new KnightPiece(false));

    // Black Bishop
    initialPiecesThreeHard.insert(
                ChessPosition(ChessPosition::h4, ChessPosition::v6),
                new BishopPiece(false));

    // Black Pawn1
    initialPiecesThreeHard.insert(
                ChessPosition(ChessPosition::h0, ChessPosition::v6),
                new PawnPiece(false));

    // Black Pawn2
    initialPiecesThreeHard.insert(
                ChessPosition(ChessPosition::h1, ChessPosition::v6),
                new PawnPiece(false));

    // Black Pawn3
    initialPiecesThreeHard.insert(
                ChessPosition(ChessPosition::h5, ChessPosition::v6),
                new PawnPiece(false));

    // Black Pawn4
    initialPiecesThreeHard.insert(
                ChessPosition(ChessPosition::h6, ChessPosition::v6),
                new PawnPiece(false));

    // Black Pawn5
    initialPiecesThreeHard.insert(
                ChessPosition(ChessPosition::h7, ChessPosition::v6),
                new PawnPiece(false));


    // Set player's correct moves
    // White Queen First Move
    correctMovesThreeHard.append(
                ChessMove(ChessPosition(ChessPosition::h5, ChessPosition::v4),
                ChessPosition(ChessPosition::h2, ChessPosition::v7),
                true));

    // White Bishop First Move
    correctMovesThreeHard.append(
                ChessMove(ChessPosition(ChessPosition::h2, ChessPosition::v3),
                ChessPosition(ChessPosition::h4, ChessPosition::v5),
                false));

    // White Rook1 First Move
    correctMovesThreeHard.append(
                ChessMove(ChessPosition(ChessPosition::h2, ChessPosition::v0),
                ChessPosition(ChessPosition::h2, ChessPosition::v7),
                false));

    // Black King First move
    cpuMovesThreeHard.append(
                ChessMove(ChessPosition(ChessPosition::h3, ChessPosition::v7),
                ChessPosition(ChessPosition::h2, ChessPosition::v7),
                true));

    // Black King Second move
    cpuMovesThreeHard.append(
                ChessMove(ChessPosition(ChessPosition::h2, ChessPosition::v7),
                ChessPosition(ChessPosition::h3, ChessPosition::v7),
                false));

    threeHard.setInitialPieces(initialPiecesThreeHard);
    threeHard.setCorrectMoves(correctMovesThreeHard);
    threeHard.setCpuMoves(cpuMovesThreeHard);

    fourHard.setLevelNumber(1967);
    fourHard.setLevelName("Boden's Checkmate");
    fourHard.setLevelDifficulty("Hard");

    // White King
    initialPiecesFourHard.insert(
                ChessPosition(ChessPosition::h2, ChessPosition::v0),
                new KingPiece(true));

    // White Queen
    initialPiecesFourHard.insert(
                ChessPosition(ChessPosition::h5, ChessPosition::v2),
                new QueenPiece(true));

    // White Bishop1
    initialPiecesFourHard.insert(
                ChessPosition(ChessPosition::h3, ChessPosition::v2),
                new BishopPiece(true));

    // White Bishop2
    initialPiecesFourHard.insert(
                ChessPosition(ChessPosition::h5, ChessPosition::v3),
                new BishopPiece(true));

    // White Rook1
    initialPiecesFourHard.insert(
                ChessPosition(ChessPosition::h1, ChessPosition::v0),
                new RookPiece(true));

    // White Rook2
    initialPiecesFourHard.insert(
                ChessPosition(ChessPosition::h7, ChessPosition::v0),
                new RookPiece(true));

    // White Knight1
    initialPiecesFourHard.insert(
                ChessPosition(ChessPosition::h2, ChessPosition::v2),
                new KnightPiece(true));

    // White Knight2
    initialPiecesFourHard.insert(
                ChessPosition(ChessPosition::h4, ChessPosition::v1),
                new KnightPiece(true));

    // White Pawn1
    initialPiecesFourHard.insert(
                ChessPosition(ChessPosition::h0, ChessPosition::v1),
                new PawnPiece(true));

    // White Pawn2
    initialPiecesFourHard.insert(
                ChessPosition(ChessPosition::h2, ChessPosition::v1),
                new PawnPiece(true));

    // White Pawn3
    initialPiecesFourHard.insert(
                ChessPosition(ChessPosition::h6, ChessPosition::v1),
                new PawnPiece(true));

    // White Pawn4
    initialPiecesFourHard.insert(
                ChessPosition(ChessPosition::h7, ChessPosition::v2),
                new PawnPiece(true));

    // Black King
    initialPiecesFourHard.insert(
                ChessPosition(ChessPosition::h2, ChessPosition::v7),
                new KingPiece(false));

    // Black Queen
    initialPiecesFourHard.insert(
                ChessPosition(ChessPosition::h7, ChessPosition::v4),
                new QueenPiece(false));

    // Black Rook1
    initialPiecesFourHard.insert(
                ChessPosition(ChessPosition::h3, ChessPosition::v7),
                new RookPiece(false));

    // Black Rook2
    initialPiecesFourHard.insert(
                ChessPosition(ChessPosition::h7, ChessPosition::v7),
                new RookPiece(false));

    // Black Bishop1
    initialPiecesFourHard.insert(
                ChessPosition(ChessPosition::h5, ChessPosition::v7),
                new BishopPiece(false));

    // Black Bishop2
    initialPiecesFourHard.insert(
                ChessPosition(ChessPosition::h4, ChessPosition::v5),
                new BishopPiece(false));

    // Black Bishop2
    initialPiecesFourHard.insert(
                ChessPosition(ChessPosition::h4, ChessPosition::v5),
                new BishopPiece(false));

    // Black Knight1
    initialPiecesFourHard.insert(
                ChessPosition(ChessPosition::h3, ChessPosition::v6),
                new KnightPiece(false));

    // Black Knight2
    initialPiecesFourHard.insert(
                ChessPosition(ChessPosition::h1, ChessPosition::v7),
                new KnightPiece(false));

    // Black Pawn1
    initialPiecesFourHard.insert(
                ChessPosition(ChessPosition::h0, ChessPosition::v6),
                new PawnPiece(false));

    // Black Pawn2
    initialPiecesFourHard.insert(
                ChessPosition(ChessPosition::h2, ChessPosition::v5),
                new PawnPiece(false));

    // Black Pawn3
    initialPiecesFourHard.insert(
                ChessPosition(ChessPosition::h4, ChessPosition::v6),
                new PawnPiece(false));

    // Black Pawn4
    initialPiecesFourHard.insert(
                ChessPosition(ChessPosition::h5, ChessPosition::v6),
                new PawnPiece(false));

    // Black Pawn5
    initialPiecesFourHard.insert(
                ChessPosition(ChessPosition::h6, ChessPosition::v6),
                new PawnPiece(false));

    // Black Pawn6
    initialPiecesFourHard.insert(
                ChessPosition(ChessPosition::h7, ChessPosition::v6),
                new PawnPiece(false));


    // Set player's correct moves
    // White Queen First Move
    correctMovesFourHard.append(
                ChessMove(ChessPosition(ChessPosition::h5, ChessPosition::v2),
                ChessPosition(ChessPosition::h2, ChessPosition::v5),
                true));

    // White Bishop First Move
    correctMovesFourHard.append(
                ChessMove(ChessPosition(ChessPosition::h3, ChessPosition::v2),
                ChessPosition(ChessPosition::h0, ChessPosition::v5),
                false));

    // Black Knight First move
    cpuMovesFourHard.append(
                ChessMove(ChessPosition(ChessPosition::h1, ChessPosition::v7),
                ChessPosition(ChessPosition::h2, ChessPosition::v5),
                true));

    // Black King Second move
    cpuMovesFourHard.append(
                ChessMove(ChessPosition(ChessPosition::h4, ChessPosition::v5),
                ChessPosition(ChessPosition::h5, ChessPosition::v5),
                false));

    // Black King Third move
    cpuMovesFourHard.append(
                ChessMove(ChessPosition(ChessPosition::h5, ChessPosition::v5),
                ChessPosition(ChessPosition::h4, ChessPosition::v5),
                false));

    // Black King Fourth move
    cpuMovesFourHard.append(
                ChessMove(ChessPosition(ChessPosition::h4, ChessPosition::v5),
                ChessPosition(ChessPosition::h5, ChessPosition::v5),
                false));

    // Black King Fifth move
    cpuMovesFourHard.append(
                ChessMove(ChessPosition(ChessPosition::h5, ChessPosition::v5),
                ChessPosition(ChessPosition::h6, ChessPosition::v5),
                false));

    fourHard.setInitialPieces(initialPiecesFourHard);
    fourHard.setCorrectMoves(correctMovesFourHard);
    fourHard.setCpuMoves(cpuMovesFourHard);

    allLevels.insert(oneEasy.getLevelNumber(), oneEasy);
    allLevels.insert(twoEasy.getLevelNumber(), twoEasy);
    allLevels.insert(threeEasy.getLevelNumber(), threeEasy);
    allLevels.insert(fourEasy.getLevelNumber(), fourEasy);
    allLevels.insert(oneMedium.getLevelNumber(), oneMedium);
    allLevels.insert(twoMedium.getLevelNumber(), twoMedium);
    allLevels.insert(threeMedium.getLevelNumber(), threeMedium);
    allLevels.insert(fourMedium.getLevelNumber(), fourMedium);
    allLevels.insert(oneHard.getLevelNumber(), oneHard);
    allLevels.insert(twoHard.getLevelNumber(), twoHard);
    allLevels.insert(threeHard.getLevelNumber(), threeHard);
    allLevels.insert(fourHard.getLevelNumber(), fourHard);
}

///
/// \brief LevelsDatabase::~LevelsDatabase
///  Destructor
LevelsDatabase::~LevelsDatabase()
{

}

///
/// \brief LevelsDatabase::getLevel
/// \param levelId
/// \return The level associated with the levelId.
///
Level LevelsDatabase::getLevel(int levelId)
{
    return allLevels[levelId];
}

///
/// \brief LevelsDatabase::getTotalLevelCount
/// \return Returns the number of levels within the game.
///
int LevelsDatabase::getTotalLevelCount() const
{
    return allLevels.size();
}


///
/// \brief LevelsDatabase::getLevelNames Retrieve the level names and return them in a list.
///                                      This is mostly used for the leaderboard functionality
/// \return QVector<QString>
///
QVector<Level> LevelsDatabase::getLevels() const
{
    QVector<Level> levels;
    for (const Level& currentLevel : allLevels)
        levels.append(currentLevel);

    return levels;
}
