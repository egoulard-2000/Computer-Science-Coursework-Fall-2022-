/*
// File name: level.cpp
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
//      This file contains the information of a single level.
*/

#include "level.h"


///
/// \brief Level::Level     Default constructor
///
Level::Level()
{

}


///
/// \brief Level::setLevelNumber    Sets the ID for a level
/// \param levelNum                 The ID for the level
///
void Level::setLevelNumber(int levelNum)
{
    levelNumber = levelNum;
}


///
/// \brief Level::getLevelNumber    Gets the level ID
/// \return                         Returns the level ID int
///
int Level::getLevelNumber() const
{
    return levelNumber;
}


///
/// \brief Level::setLevelName      Set the name of the level
/// \param levelName                Name of the level
///
void Level::setLevelName(QString levelName)
{
    this->levelName = levelName;
}


///
/// \brief Level::getLevelName      Get the name of the level
/// \return                         Returns the name of the level
///
QString Level::getLevelName() const
{
    return levelName;
}


///
/// \brief Level::setLevelDifficulty    Declares the level's difficulty
/// \param difficulty                   Level's difficulty
///
void Level::setLevelDifficulty(QString difficulty)
{
    levelDifficulty = difficulty;
}


///
/// \brief Level::getLevelDifficulty    Gets the difficulty of the level
/// \return                             Returns the level difficulty
///
QString Level::getLevelDifficulty() const
{
    return levelDifficulty;
}


///
/// \brief Level::setInitialPieces      Set starting position and pieces of the level
/// \param startingPieces               Positions and their respective pieces
///
void Level::setInitialPieces(QMap<ChessPosition, ChessPiece*> startingPieces)
{   
    QMap<ChessPosition, ChessPiece*>::iterator iterator;
    for (iterator = startingPieces.begin(); iterator != startingPieces.end(); ++iterator)
    {
        initialPieces.insert(iterator.key(), iterator.value());
    }
}


///
/// \brief Level::getInitialPiecesList      Gets all the initial pieces and their positions
/// \return                                 Returns a list of positions with pieces
///
QMap<ChessPosition, ChessPiece*> Level::getInitialPiecesList() const
{
    return initialPieces;
}


///
/// \brief Level::setCorrectMoves       Declare a list of correct moves for the user
/// \param correctMovesList             Correct moves the user can make in order
///
void Level::setCorrectMoves(QVector<ChessMove> correctMovesList)
{
    for (auto move : correctMovesList)
    {
        correctMoves.append(move);
    }
}


///
/// \brief Level::getCorrectMovesList       Gets the list of correct moves for the user
/// \return                                 All correct moves a user can make in the level
///
QVector<ChessMove> Level::getCorrectMovesList() const
{
    return correctMoves;
}


///
/// \brief Level::setCpuMoves   Sets the moves the CPU will be making throughout the level
/// \param cpuMovesList         CPU moves in order for the level
///
void Level::setCpuMoves(QVector<ChessMove> cpuMovesList)
{
    for (auto move : cpuMovesList)
    {
        cpuMoves.append(move);
    }
}


///
/// \brief Level::getCpuMovesList   Gets the list of all CPU moves in order
/// \return                         List of CPU moves in the level
///
QVector<ChessMove> Level::getCpuMovesList() const
{
    return cpuMoves;
}
