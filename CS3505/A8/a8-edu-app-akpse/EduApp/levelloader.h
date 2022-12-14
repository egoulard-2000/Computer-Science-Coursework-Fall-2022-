/*
// File name: levelloader.h
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
//      levelloader.h is the header file for levelloader.cpp. Please see said file for details.
*/

#ifndef LEVELLOADER_H
#define LEVELLOADER_H

#include "QtCore/qdatetime.h"
#include "chessboard.h"
#include "level.h"
#include <QTimer>
#include <QTime>

class LevelLoader : public QObject
{
    Q_OBJECT
public:
    LevelLoader();

    void loadLevelPieces();

    // Loads a selected level
    void loadLevel(Level levelToLoad);
    Level getLevel() const;

    QMap<ChessPosition, ChessPiece*> const getInitialPieces();
    QVector<ChessPosition> highlightOrMove(const ChessPosition position);
    QMap<ChessPosition, ChessPiece*> const getCurrentPieces();

    QVector<QString> getLevelTextInfo();

    // End of the game
    bool checkForEndState();
    bool didUserLose();
    void setLossBool(bool reset);

    bool canPlayerMove();

    void forceStopCPU();

    std::optional<ChessPosition> getHintPosition();

signals:
    void updateDisplay();

public slots:
    void moveNextCpuPiece();

private:
    ChessBoard chessBoard;
    Level level;
    QVector<ChessMove> userCorrectLevelMoves;
    QVector<ChessMove> cpuLevelMoves;
    QTimer *turnTimer;

    // Check if a piece is currently selected
    bool pieceSelected;
    ChessPiece* selectedPiece;
    ChessPosition selectedPiecePosition;

    const QVector<ChessPosition> emptyList;
    QVector<ChessPosition> possiblePiecePositions;

    QMap<ChessPosition, ChessPiece*> currentPieces;

    QVector<ChessPosition> getHighlightedPositions(const ChessPosition position);
    QVector<ChessPosition> movePiece(const ChessPosition selectedPosition);

    const QMap<int, QString> unicodeToLevelId = {
        {1864, "E1"},
        {1888, "E2"},
        {2078, "E3"},
        {1986, "E4"},
        {2071, "M1"},
        {2095, "M2"},
        {2285, "M3"},
        {2193, "M4"},
        {1845, "H1"},
        {1869, "H2"},
        {2059, "H3"},
        {1967, "H4"}
    };
    bool loseGame;
    bool playerCanMove = true;

    // CPU timer
    QTimer* CPUTimer;
};

#endif // LEVELLOADER_H
