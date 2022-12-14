/*
// File name: model.cpp
// Author:    Soli, Emile
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
//      This is the model class that holds the information.
*/

#include "model.h"

Model::Model()
{
    connect(&levelLoader,
            &LevelLoader::updateDisplay,
            this,
            &Model::updateDisplayFromLevel);
}

void Model::loadLevel(QString levelName)
{
    int levelId = 0;
    for (int i = 0; i < levelName.length(); i++)
    {
        levelId += levelName[i].unicode();
    }

    levelLoader.loadLevel(levelsDatabase.getLevel(levelId));

    emit updatePieces(levelLoader.getInitialPieces());

    // Resets any visual highlights
    QVector<ChessPosition> emptyMoves;
    emit updateHighlightedMoves(emptyMoves);

    // Updates level info in the GUI
    emit updateLevelTextGui(levelLoader.getLevelTextInfo());
    emit updateDisplayedTurn(levelLoader.canPlayerMove());
    currentLevelName = levelName;
}


///
/// \brief Model::getBoardPosition
/// \param position
///  Gets the position of the board that the player moved a piece on
///  so that it can be determined if the game is won or an incorrect move was made.
void Model::getBoardPosition(ChessPosition position)
{
    if (!levelLoader.canPlayerMove())
    {
        return;
    }

    emit updateHighlightedMoves(levelLoader.highlightOrMove(position));


    if (levelLoader.checkForEndState())
    {
        QString winOrLose;
        if (levelLoader.didUserLose())
        {
            winOrLose = "lose";
            levelLoader.setLossBool(false);
        }
        else
        {
            winOrLose = "win";
        }
        emit endOfGame(winOrLose);
    }
}

///
/// \brief Model::updateDisplayFromLevel
///  Simple method that updates the board as the game is played.
void Model::updateDisplayFromLevel()
{
    emit updateDisplayedTurn(levelLoader.canPlayerMove());
    emit updatePieces(levelLoader.getCurrentPieces());
}

///
/// \brief Model::loadLeaderboard
///  A method that loads in the leaderboard holding onto all statistics about player's games.
void Model::loadLeaderboard()
{
    // Grab the names and records associated with each level
    for (const Level& level : levelsDatabase.getLevels())
    {
        const auto levelName = level.getLevelName();
        const auto levelRecords = level.leaderboard->getAllRecords();
        emit updateLeaderboard(levelName, levelRecords);
    }
}


///
/// \brief Model::processHint
///  Processes hint signal from view, sends the position of the next piece that must be moved
void Model::processHint()
{
    const auto hintPos = levelLoader.getHintPosition();

    // Hintpos might not exist if the puzzle is already solved or the user has lost,
    // so does not update in those cases
    if(hintPos)
        emit updateHighlightedMoves({hintPos.value()});
}


///
/// \brief Model::processRetry
///  Processes retry signal from view, resets the board to the initial position
void Model::processRetry()
{
    // Need to stop CPU moves from occuring, as otherwise reset could still allow
    // CPU to move after the reset finishes.
    levelLoader.forceStopCPU();
    loadLevel(currentLevelName);
}


///
/// \brief processLeaderboard   Receives a time from the view, and uses it to set the leaderboard
/// \param time                 Time to insert into leaderboard
///
void Model::processLeaderboard(const QTime& time)
{
    Level levelPlayed = levelLoader.getLevel();
    const QString name = "Player";
    emit updateLeaderboardEntry(levelPlayed, time, name);
}
