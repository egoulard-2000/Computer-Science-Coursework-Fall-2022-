/*
// File name: chessmove.h
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
//      chessmove.h is the header file for chessmove.cpp. Please see said file for details.
*/

#ifndef CHESSMOVE_H
#define CHESSMOVE_H

#include <QDebug>
#include "chessposition.h"

using horizontal = ChessPosition::horizontal;
using vertical = ChessPosition::vertical;


class ChessMove
{
public:
    ChessMove(ChessPosition oldPos, ChessPosition newPos,
              bool capture, ChessPosition capturedPos = ChessPosition((horizontal)0, (vertical)0));

    ChessPosition getOldPosition() const;
    ChessPosition getNewPosition() const;

    bool hasCaptured() const;
    ChessPosition whoWasCaptured() const;

    bool operator==(const ChessMove& other) const;

private:
    ChessPosition oldPosition; // The old position that the piece occupied
    ChessPosition newPosition; // The new position that the piece will occupy

    bool captureOccured; // Whether this move will cause a capture to occur
    ChessPosition capturedPosition; // If a capture occurs, specifies its position. Otherwise, undefined.
};

QDebug operator<<(QDebug debug, const ChessMove& pos);

#endif // CHESSMOVE_H
