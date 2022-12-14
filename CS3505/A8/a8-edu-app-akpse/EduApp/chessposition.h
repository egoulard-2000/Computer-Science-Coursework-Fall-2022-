/*
// File name: chessposition.h
// Author:    Allen
// Assignment:Educational Program
// Group:     AKPSE
// Date:      12/8/2022
// Course:    CS 3505, University of Utah, School of Computing
// Copyright: CS 3505 and AKPSE - This work may not be copied for use in Academic Coursework.
//
// Our group, AKPSE, certifies that we wrote this code from scratch and did not copy it in part or whole from
// another source.
//
// File Contents
//
//      chessposition.h is the header file for chessposition.cpp. Please see said file for details.
//
*/

#ifndef CHESSPOSITION_H
#define CHESSPOSITION_H

#include <string>
#include <QDebug>

class ChessPosition
{

public:
    enum horizontal {h0, h1, h2, h3, h4, h5, h6, h7}; // Starts from bottom left, white side
    enum vertical {v0, v1, v2, v3, v4, v5, v6, v7}; // Starts from bottom left, white side


    ///
    /// \brief ChessPosition::ChessPosition     Initializes the position.
    /// \param h                                Horizontal/X position.
    /// \param v                                Vertical/Y position.
    ///
    ChessPosition(horizontal h, vertical v);


    // The Max/Min positions on the chessboard
    static const int MAX_H = 7;
    static const int MAX_V = 7;
    static const int MIN_H = 0;
    static const int MIN_V = 0;


    ///
    /// \brief operator==   Comparison operator for whether
    ///                     the positions are equal.
    /// \param other        The other position to compare to.
    /// \return             True if positions are equal, false otherwise.
    ///
    bool operator==(const ChessPosition& other) const;


    ///
    /// \brief operator!=   Non-comparison operator for whether
    ///                     the positions are equal.
    /// \param other        The other position to compare to.
    /// \return             True if positions are unequal, false otherwise.
    ///
    bool operator!=(const ChessPosition& other) const;


    ///
    /// \brief operator<    Operator overload for <.
    /// \param other        The other position to compare to.
    /// \return             this < other.
    ///
    bool operator<(const ChessPosition& other) const;


    ///
    /// \brief isValidPosition   Returns whether or not an (int, int)
    ///                          position is a valid chess position.
    /// \param h                 The horizontal/X coordinate.
    /// \param v                 The vertical/Y coordinate.
    /// \return                  True if position is valid. False otherwise.
    ///
    static bool isValidPosition(int h, int v);

    horizontal hPos;
    vertical vPos;

};


///
/// \brief operator<<   Allows "qDebug() << ChessPosition" to work.
/// \param debug        The QDebug object to insert into.
/// \param pos          The ChessPosition to print.
/// \return
///
QDebug operator<<(QDebug debug, const ChessPosition& pos);

#endif // CHESSPOSITION_H
