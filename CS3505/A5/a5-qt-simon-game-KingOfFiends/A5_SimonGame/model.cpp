#include "model.h"
#include "qdebug.h"
#include <iostream>

/*
CS 3505 - A5 - QT SimonGame
10/28/2022

Emile Goulard - u1244855
Michael Sullivan - u0794378

*/
Model::Model(QObject *parent)
    : QObject{parent}
{
    moveCounter = 1;
    playerIndex = 0;
    gameTime = 1000;
    computerIndex = 0;
    playerProgress = 0;
    isPlayerTurn = false;

    currentScore = 0;
    highScore = 0;
}

void Model::startGame()
{
    playerMoves.clear();
    playerMoves.resize(0);
    playerIndex = 0;
    playerProgress = 0;

    computerMoves.clear();
    computerMoves.resize(0);
    computerIndex = 0;

    moveCounter = 1;
    currentScore = 0;
    gameTime = 1000;
    gameMoves();

    emit showStartButton(false);
    emit showLoseScreen(false);
    emit showSimonButtons(true);
    emit showProgressBar(true);
    emit showHighScore(true);
    emit showInstructions(true);
}

void Model::endMoves()
{
    isPlayerTurn = true;
    printVector();
}

void Model::gameMoves()
{
    if (!isPlayerTurn)
    {
        // Computer Makes moves depending on current round
        while (computerIndex < moveCounter)
        {
            int randomColor = rand() % 2;

            string color;
            if (randomColor == 0)
            {
                color = "Red";
                computerMoves.push_back(color);
            }
            else
            {
                color = "Blue";
                computerMoves.push_back(color);
            }

            computerIndex++;
            emit progressChanged(0);
        }

        // Clamping to 100 to avoid negative time values
        if (gameTime > 100){
            gameTime -= 100;
        }
        else{
            gameTime = 50;
        }

        emit increaseGameSpeed(gameTime);
        emit click(computerMoves);

        // Delay player turn after computer
        QTimer::singleShot(1000, this, &Model::endMoves);
    }
}

void Model::redButtonClicked()
{
    if (isPlayerTurn)
    {
        playerMoves.push_back("Red");
        isPlayerCorrect(playerIndex);
    }
}

void Model::blueButtonClicked()
{
    if (isPlayerTurn)
    {
        playerMoves.push_back("Blue");
        isPlayerCorrect(playerIndex);
    }
}

void Model::isPlayerCorrect(int index)
{
    playerProgress = ((double)playerMoves.size() / (double)computerMoves.size()) * 100;
    emit progressChanged(playerProgress);
    if (playerMoves[index] != computerMoves[index]) // is player currently pressing correct button?
    {
        // end game and show lose screen
        emit showLoseScreen(true);
        emit showStartButton(true);
        emit showSimonButtons(false);
        emit showProgressBar(false);
        emit showInstructions(false);
        isPlayerTurn = false;
    }
    else if (index == (int)computerMoves.size() - 1) // is player at the end of the current round?
    {
        // continue to next round
        moveCounter++;

        // Update high score if possible
        currentScore++;
        QString highScoreText;
        if (currentScore > highScore)
        {
            highScore = currentScore;
            highScoreText = QString::number(highScore); // Convert to a number to be displayed on UI
            emit updateHighScore(highScoreText);
        }

        playerMoves.clear();
        playerMoves.resize(0);
        playerIndex = 0;
        isPlayerTurn = false;

        QTimer::singleShot(gameTime, this, &Model::gameMoves);
    }
    else
    {
        playerIndex++; // Otherwise, keep playing
    }
}

// This is here to test elements in a vector after 15 elements are in
void Model::printVector()
{
    for (auto element : computerMoves)
    {
        std::cout << element << ", ";
    }
    std::cout << std::endl;
}
