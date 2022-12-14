/*
// File name: tests.cpp
// Author:    Allen, Stefan
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
//      tests.cpp specifies various unit tests for this program
            using the Google Test framework.
*/

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

#include "bishoppiece.h"
#include "kingpiece.h"
#include "knightpiece.h"
#include "pawnpiece.h"
#include "queenpiece.h"
#include "rookpiece.h"
#include "chessboard.h"
#include "qapplication.h"

using namespace testing;

///
/// \brief bishopTest   Test whether a Bishop may be initialized in a ChessBoard,
///                     and contain the expected ChessMove's.
///
TEST(chessPieceTests, bishopTest)
{
    int bruh = 0;
    QGuiApplication test(bruh, nullptr);
    // THIS IS NECESSARY TO USE THE BISHOP PIECE
    // This is because the bishop stores a QPixMap, and this can not be initialized
    // unless a QGuiApplication is initialized
    // So... please someone fix this somehow.

    ChessBoard board;
    ChessPosition bishopPos = ChessPosition(horizontal::h2, vertical::v2);
    board.addPiece(bishopPos, new BishopPiece(true));
    const auto moves = board.getMoves(ChessPosition(horizontal::h2, vertical::v2));

    EXPECT_TRUE(moves.count() == 11);

    ChessMove expected = ChessMove(bishopPos, ChessPosition(horizontal::h7, vertical::v7), false);
    EXPECT_TRUE(moves.contains(expected));

    expected = ChessMove(bishopPos, ChessPosition(horizontal::h5, vertical::v7), false);
    EXPECT_FALSE(moves.contains(expected));
}


///
/// \brief captureTest  Test whether the ChessBoard class and ChessMove
///                     class can work together to allow capturing pieces.
///
TEST(chessBoardTests, captureTest)
{
    int intVar = 0;
    QGuiApplication test(intVar, nullptr);

    ChessBoard board;

    // Add a white bishop at (3, 1)
    ChessPosition bishopPos = ChessPosition(horizontal::h3, vertical::v1);
    board.addPiece(bishopPos, new BishopPiece(true));

    // Add a black rook at (5, 3)
    ChessPosition rookPos = ChessPosition(horizontal::h5, vertical::v3);
    board.addPiece(rookPos, new RookPiece(false));

    // Confirm bishop moves are correct
    EXPECT_TRUE(board.getAllPieces().count() == 2);
    EXPECT_TRUE(board.getMoves(bishopPos).count() == 7);

    ChessMove expected = ChessMove(bishopPos, ChessPosition(horizontal::h4, vertical::v2), false);
    EXPECT_TRUE(board.getMoves(bishopPos).contains(expected));

    expected = ChessMove(bishopPos, rookPos, true, rookPos);
    EXPECT_TRUE(board.getMoves(bishopPos).contains(expected));

    ChessMove notExpected = ChessMove(bishopPos, ChessPosition(horizontal::h6, vertical::v3), false);
    EXPECT_FALSE(board.getMoves(bishopPos).contains(notExpected));
}


///
/// \brief movingPieces     Test whether ChessBoard is capable of moving
///                         moving pieces to a new position.
///
TEST(chessBoardTests, movingPieces)
{
    int intVar = 0;
    QGuiApplication test(intVar, nullptr);

    ChessBoard board;

    // Add a white knight at (1, 2)
    ChessPosition knightPos = ChessPosition(horizontal::h1, vertical::v2);
    board.addPiece(knightPos, new KnightPiece(true));

    // Confirm knight has correct moves
    QVector<ChessMove> moves = board.getMoves(knightPos);
    EXPECT_TRUE(moves.count() == 6);
    ChessMove expectedMove = ChessMove(knightPos, ChessPosition(horizontal::h3, vertical::v3), false);
    EXPECT_TRUE(moves.contains(expectedMove));
    expectedMove = ChessMove(knightPos, ChessPosition(horizontal::h0, vertical::v0), false);
    EXPECT_TRUE(moves.contains(expectedMove));

    // Move the knight
    board.movePiece(ChessMove(knightPos, ChessPosition(horizontal::h0, vertical::v0), false));
    knightPos = ChessPosition(horizontal::h0, vertical::v0);

    // Confirm knight has correct moves
    moves = board.getMoves(knightPos);
    EXPECT_TRUE(moves.count() == 2);
    expectedMove = ChessMove(knightPos, ChessPosition(horizontal::h1, vertical::v2), false);
    EXPECT_TRUE(moves.contains(expectedMove));
}


///
/// \brief positionAndMoveEquality  Test whether the ChessPosition and ChessMove
///                                 classes have a working operator==().
///
TEST(chessBoardTests, positionAndMoveEquality)
{
    ChessPosition pos1 = ChessPosition(horizontal::h0, vertical::v0);
    ChessPosition pos2 = ChessPosition(horizontal::h0, vertical::v0);
    ChessPosition pos3 = ChessPosition(horizontal::h0, vertical::v1);
    ChessPosition pos4 = ChessPosition(horizontal::h1, vertical::v0);

    EXPECT_TRUE(pos1 == pos2);
    EXPECT_FALSE(pos1 == pos3);
    EXPECT_FALSE(pos1 == pos4);

    ChessMove move1 = ChessMove(pos1, pos3, false);
    ChessMove move2 = ChessMove(pos1, pos3, false);
    ChessMove move3 = ChessMove(pos1, pos4, false);
    ChessMove move4 = ChessMove(pos1, pos3, true, pos4);
    ChessMove move5 = ChessMove(pos1, pos3, true, pos4);
    ChessMove move6 = ChessMove(pos1, pos4, true, pos3);

    EXPECT_TRUE(move1 == move2);
    EXPECT_FALSE(move1 == move3);
    EXPECT_FALSE(move1 == move4);
    EXPECT_FALSE(move1 == move6);
    EXPECT_TRUE(move4 == move5);
    EXPECT_FALSE(move4 == move6);
}


///
/// \brief positionAndMoveEquality2     Test whether the ChessPosition and ChessMove
///                                     classes have a working operator==().
///
TEST(chessBoardTests, positionAndMoveEquality2)
{
    ChessPosition pos1 = ChessPosition(horizontal::h2, vertical::v2);
    ChessPosition pos2 = ChessPosition(horizontal::h2, vertical::v5);
    ChessPosition pos3 = ChessPosition(horizontal::h5, vertical::v2);
    ChessPosition pos4 = ChessPosition(horizontal::h5, vertical::v5);

    EXPECT_FALSE(pos1 == pos2);
    EXPECT_FALSE(pos1 == pos3);
    EXPECT_FALSE(pos1 == pos4);

    EXPECT_FALSE(pos2 == pos3);
    EXPECT_FALSE(pos2 == pos4);

    EXPECT_FALSE(pos3 == pos4);
}


///
/// \brief addMultiplePieces    Test whether ChessBoard is capable of storing
///                             multiple pieces.
///
TEST(chessBoardTests, addMultiplePieces)
{
    int intVar = 0;
    QGuiApplication test(intVar, nullptr);

    ChessBoard board = ChessBoard();

    ChessPosition rookPos(ChessPosition::h5, ChessPosition::v5);
    board.addPiece(rookPos, new RookPiece(true));

    ChessPosition bishopPos(ChessPosition::h2, ChessPosition::v2);
    board.addPiece(bishopPos, new BishopPiece(true));

    EXPECT_TRUE(board.getAllPieces().count() == 2);
}


///
/// \brief addMultiplePieces2   Test whether ChessBoard is capable of storing
///                             multiple pieces.
///
TEST(chessBoardTests, addMultiplePieces2)
{
    int intVar = 0;
    QGuiApplication test(intVar, nullptr);

    // Initialize the ChessPieces
    QMap<ChessPosition, ChessPiece*> currentPieces;

    currentPieces[ChessPosition(ChessPosition::h2, ChessPosition::v2)] = new BishopPiece(true);
    EXPECT_TRUE(currentPieces.count() == 1);

    currentPieces[ChessPosition(ChessPosition::h2, ChessPosition::v5)] = new BishopPiece(true);
    EXPECT_TRUE(currentPieces.count() == 2);

    currentPieces[ChessPosition(ChessPosition::h5, ChessPosition::v2)] = new BishopPiece(true);
    EXPECT_TRUE(currentPieces.count() == 3);

    currentPieces[ChessPosition(ChessPosition::h5, ChessPosition::v5)] = new BishopPiece(false);
    EXPECT_TRUE(currentPieces.count() == 4);

    // Initialize a new QMap from scratch
    QMap<ChessPosition, ChessPiece*> pieces2 {
        {ChessPosition(ChessPosition::h2, ChessPosition::v2), new BishopPiece(true)},
        {ChessPosition(ChessPosition::h2, ChessPosition::v5), new BishopPiece(true)},
        {ChessPosition(ChessPosition::h5, ChessPosition::v2), new BishopPiece(true)},
        {ChessPosition(ChessPosition::h5, ChessPosition::v5), new BishopPiece(false)}
    };
    EXPECT_TRUE(pieces2.count() == 4);

    // Confirm that ChessBoard returns the correct count as well
    EXPECT_TRUE(ChessBoard(currentPieces).getAllPieces().count() == 4);
    EXPECT_TRUE(ChessBoard(pieces2).getAllPieces().count() == 4);
}


///
/// \brief pawnMove     Tests whether the PawnPiece can move to the expected tiles.
///
TEST(chessPieceTests, pawnMove)
{
    // Initialize the chess board
   ChessBoard board = ChessBoard();
   ChessPosition pawnPos1 = ChessPosition(ChessPosition::h0, ChessPosition::v1);
   board.addPiece(pawnPos1, new PawnPiece(true));
   ChessPosition pawnPos2 = ChessPosition(ChessPosition::h1, ChessPosition::v2);
   board.addPiece(pawnPos2, new PawnPiece(true));

   // Confirm that pieces move correctly
   EXPECT_TRUE(board.getMoves(pawnPos1).count() == 2);
   EXPECT_TRUE(board.getMoves(pawnPos2).count() == 1);

   ChessMove expectedMove = ChessMove(
               pawnPos1,
               ChessPosition(ChessPosition::h0, ChessPosition::v2),
               false);
   EXPECT_TRUE(board.getMoves(pawnPos1).contains(expectedMove));
   expectedMove = ChessMove(
               pawnPos1,
               ChessPosition(ChessPosition::h0, ChessPosition::v3),
               false);
   EXPECT_TRUE(board.getMoves(pawnPos1).contains(expectedMove));
   expectedMove = ChessMove(
               pawnPos2,
               ChessPosition(ChessPosition::h1, ChessPosition::v3),
               false);
   EXPECT_TRUE(board.getMoves(pawnPos2).contains(expectedMove));
}


///
/// \brief pawnCapture  Test whether the PawnPiece can capture other pieces
///                     as expected.
///
TEST(chessPieceTests, pawnCapture)
{
    // Initialize the chess board
   ChessBoard board = ChessBoard();
   ChessPosition pawnPos = ChessPosition(ChessPosition::h2, ChessPosition::v2);
   board.addPiece(pawnPos, new PawnPiece(true));
   ChessPosition enemyPos = ChessPosition(ChessPosition::h1, ChessPosition::v3);
   board.addPiece(enemyPos, new BishopPiece(false));
   ChessPosition allyPos = ChessPosition(ChessPosition::h3, ChessPosition::v3);
   board.addPiece(allyPos, new KingPiece(true));

   // Confirm that pieces move correctly
   EXPECT_TRUE(board.getMoves(pawnPos).count() == 2);

   ChessMove expectedMove = ChessMove(
               pawnPos,
               enemyPos,
               true,
               enemyPos);
   EXPECT_TRUE(board.getMoves(pawnPos).contains(expectedMove));
   expectedMove = ChessMove(
               pawnPos,
               ChessPosition(ChessPosition::h2, ChessPosition::v3),
               false);
   EXPECT_TRUE(board.getMoves(pawnPos).contains(expectedMove));
}


///
/// \brief kingMove     Test whether the KingPiece can move to the expected tiles.
///
TEST(chessPieceTests, kingMove)
{
    // Initialize the ChessBoard
    ChessBoard board;
    ChessPosition kingPos = ChessPosition(ChessPosition::h3, ChessPosition::v0);
    board.addPiece(kingPos, new KingPiece(true));

    // Confirm that proper moves exist
    EXPECT_TRUE(board.getMoves(kingPos).count() == 5);
    ChessMove expected = ChessMove(kingPos, ChessPosition(ChessPosition::h2, ChessPosition::v0), false);
    EXPECT_TRUE(board.getMoves(kingPos).contains(expected));
    expected = ChessMove(kingPos, ChessPosition(ChessPosition::h4, ChessPosition::v1), false);
    EXPECT_TRUE(board.getMoves(kingPos).contains(expected));
    expected = ChessMove(kingPos, kingPos, false);
    EXPECT_FALSE(board.getMoves(kingPos).contains(expected));
}


///
/// \brief kingCapture  Test whether the KingPiece can capture other pieces
///                     as expected.
///
TEST(chessPieceTests, kingCapture)
{
    // Initialize the ChessBoard
    ChessBoard board;
    ChessPosition kingPos = ChessPosition(ChessPosition::h3, ChessPosition::v3);
    board.addPiece(kingPos, new KingPiece(true));
    ChessPosition allyPos = ChessPosition(ChessPosition::h4, ChessPosition::v3);
    board.addPiece(allyPos, new QueenPiece(true));
    ChessPosition enemyKingPos = ChessPosition(ChessPosition::h2, ChessPosition::v2);
    board.addPiece(enemyKingPos, new KingPiece(false));
    ChessPosition enemyKnightPos = ChessPosition(ChessPosition::h2, ChessPosition::v3);
    board.addPiece(enemyKnightPos, new KnightPiece(false));
    ChessPosition enemyBishopPos = ChessPosition(ChessPosition::h4, ChessPosition::v4);
    board.addPiece(enemyBishopPos, new BishopPiece(false));

    // Confirm that proper moves exist
    QVector<ChessMove> kingMoves = board.getMoves(kingPos);
    EXPECT_TRUE(kingMoves.count() == 7);

    ChessMove expected = ChessMove(kingPos, enemyKingPos, true, enemyKingPos);
    EXPECT_TRUE(kingMoves.contains(expected));
    expected = ChessMove(kingPos, enemyKnightPos, true, enemyKnightPos);
    EXPECT_TRUE(kingMoves.contains(expected));
    expected = ChessMove(kingPos, enemyBishopPos, true, enemyBishopPos);
    EXPECT_TRUE(kingMoves.contains(expected));
    expected = ChessMove(kingPos, allyPos, true, allyPos);
    EXPECT_FALSE(kingMoves.contains(expected));
}
