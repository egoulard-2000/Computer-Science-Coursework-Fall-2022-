/*
// File name: levelloader.cpp
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
//      LevelLoader deals with loading levels into the game as well as dealing with loading pieces and moves
*/

#include "levelloader.h"
#include <QMessageBox>


///
/// \brief LevelLoader::LevelLoader     Constructor for LevelLoader
///
LevelLoader::LevelLoader() :
    selectedPiecePosition(ChessPosition(ChessPosition::h0, ChessPosition::v0))
{
    pieceSelected = false;
    loseGame = false;

    // initialize QTimer for CPU moves
    CPUTimer = new QTimer(this);
    CPUTimer->setSingleShot(true);
    CPUTimer->setInterval(1000);
    CPUTimer->callOnTimeout([this](){moveNextCpuPiece();});
}


///
/// \brief LevelLoader::loadLevel      Loads in the proper level information
/// \param levelToLoad                 The level to load
///
void LevelLoader::loadLevel(Level levelToLoad)
{
    level = levelToLoad;
    currentPieces.clear();
    userCorrectLevelMoves = level.getCorrectMovesList();
    cpuLevelMoves = level.getCpuMovesList();
    currentPieces = level.getInitialPiecesList();
    loseGame = false;
    playerCanMove = true;
}


///
/// \brief LevelLoader::getLevel
/// \return
///
Level LevelLoader::getLevel() const
{
    return level;
}


///
/// \brief LevelLoader::getInitialPieces
/// \return
/// \brief LevelLoader::getInitialPieces    Gets a list of pieces and their positions for the start of the level
/// \return                                 A map of chess positions and the piece at that position
///
QMap<ChessPosition, ChessPiece*> const LevelLoader::getInitialPieces()
{
    return level.getInitialPiecesList();
}


///
/// \brief LevelLoader::getCurrentPieces    Returns all current pieces on the board and their positions
/// \return                                 A map of current chess positions and the piece at that position
///
QMap<ChessPosition, ChessPiece*> const LevelLoader::getCurrentPieces()
{
    return currentPieces;
}


///
/// \brief LevelLoader::highlightOrMove     Figures if the input is for showing highlights or moving a piece
/// \param position                         Where the selected piece is at
/// \return                                 Possible moves for the player.
///
QVector<ChessPosition> LevelLoader::highlightOrMove(const ChessPosition position)
{
   ChessPiece* possiblePiece = currentPieces.value(position);

   // Selecting a new piece
   if (possiblePiece != nullptr && possiblePiece->isWhite())
   {
       selectedPiece = possiblePiece;
       selectedPiecePosition = position;

       // Highlighting all moves
       possiblePiecePositions.clear();
       possiblePiecePositions = getHighlightedPositions(position);
       return possiblePiecePositions;
   }
   else
   {
       // Either move piece or select empty position
       if (pieceSelected)
       {
           return movePiece(position);
       }
       else
       {
           return emptyList;
       }
   }
}


///
/// \brief LevelLoader::getHighlightedPositions     Gets a list of all possible moves a piece can move to
/// \param position                                 The position of where the selected piece is at
/// \return                                         All possible moves a selected piece can move to
///
QVector<ChessPosition> LevelLoader::getHighlightedPositions(const ChessPosition position)
{
    // Get all possible moves for that piece
    QVector<ChessMove> pieceMoves = selectedPiece->possibleMoves(position, currentPieces);
    pieceSelected = true;

    // Take the new positions that the piece can move to
    for (ChessMove possibleMove : pieceMoves)
    {
        possiblePiecePositions.append(possibleMove.getNewPosition());
    }

    return possiblePiecePositions;
}


///
/// \brief LevelLoader::movePiece   Moves the selected piece
/// \param selectedPosition         Where the selected piece is at
/// \return                         Updated positions of all pieces on the board
///
QVector<ChessPosition> LevelLoader::movePiece(const ChessPosition selectedPosition)
{  
    if(checkForEndState())
    {
        return emptyList;
    }

    pieceSelected = false;

    // Edge Case: The selected position isn't a possible position to move to
    if(!possiblePiecePositions.contains(selectedPosition))
    {
        return emptyList;
    }

    ChessMove currentMove = userCorrectLevelMoves.first();

    // Make sure it's a CORRECT MOVE and right piece. If not, game over pop-up
    if (selectedPosition == currentMove.getNewPosition() &&
        selectedPiecePosition == currentMove.getOldPosition())
    {
        // Iterate to next user move for next turn
        userCorrectLevelMoves.removeFirst();
        playerCanMove = false;
    }
    else
    {
        // Wrong move pop-up window in View
        loseGame = true;
        return emptyList;
    }

    // Remove the selected piece from current board
    currentPieces.remove(selectedPiecePosition);
    // If capturing, also remove that piece
    if (currentMove.hasCaptured())
    {
        currentPieces.remove(currentMove.whoWasCaptured());
    }

    // Add the position of the new piece
    currentPieces.insert(currentMove.getNewPosition(), selectedPiece);

    // QTimer singleshot and then update CPU Move
    emit updateDisplay();

    CPUTimer->start();

    return emptyList;
}


///
/// \brief LevelLoader::moveNextCpuPiece    Move the next CPU piece
///
void LevelLoader::moveNextCpuPiece()
{
    // End of game so no moves
    if (checkForEndState())
    {
        return;
    }

    // Get the next CPU move
    ChessMove currentMove = cpuLevelMoves.first();
    cpuLevelMoves.removeFirst();

    if (currentMove.hasCaptured())
    {
        //currentPieces.insert(currentMove.getNewPosition(), currentPieces.value(currentMove.getOldPosition()));
        currentPieces.remove(currentMove.whoWasCaptured());

    }

    // Add piece(s) at new positions
    currentPieces.insert(currentMove.getNewPosition(), currentPieces.value(currentMove.getOldPosition()));

    // Remove piece(s) at old positions
    currentPieces.remove(currentMove.getOldPosition());

    // Update the board
    playerCanMove = true;
    emit updateDisplay();
}


///
/// \brief LevelLoader::canPlayerMove   Checks if the player is allowed to move
/// \return                             True for able to interact
///
bool LevelLoader::canPlayerMove()
{
   return playerCanMove;
}


///
/// \brief getLevelTextInfo     Gets the information of the level in text
/// \return                     Returns a vector consisting of the following information in order: Level ID, Name, and Difficulty
///
QVector<QString> LevelLoader::getLevelTextInfo()
{
    QVector<QString> allInfo;

    allInfo.append(unicodeToLevelId[level.getLevelNumber()]);
    allInfo.append(level.getLevelName());
    allInfo.append(level.getLevelDifficulty());

    return allInfo;
}


///
/// \brief LevelLoader::checkForEndState    Check if it's reached the end of the game
/// \return                                 True if end of game
///
bool LevelLoader::checkForEndState()
{
    return userCorrectLevelMoves.isEmpty() || loseGame;
}


///
/// \brief LevelLoader::didUserLose     Check if player made an improper move
/// \return                             True if improper move
///
bool LevelLoader::didUserLose()
{
    return loseGame;
}


///
/// \brief LevelLoader::setLossBool     Declares whether the user has lost yet
/// \param reset                        The value for whether the game is over or not
///
void LevelLoader::setLossBool(bool reset)
{
    loseGame = reset;
}


///
/// \brief LevelLoader::forceStopCPU    Method to forcibly stop any CPU moves from occuring.
///
void LevelLoader::forceStopCPU()
{
    CPUTimer->stop();
}


///
/// \brief LevelLoader::getHintPosition Optionally returns the ChessPosition of the piece
///                                     that is needed to move next for the puzzle.
/// \return                             An optional template, which either contains the
///                                     correct chessPosition, or is empty
///
std::optional<ChessPosition> LevelLoader::getHintPosition()
{
    if(checkForEndState())
        return {};
    return userCorrectLevelMoves.first().getOldPosition();
}
