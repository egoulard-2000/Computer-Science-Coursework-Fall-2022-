/*
// File name: leaderboard.cpp
// Author:    Emile
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
//      This is the header file for the Leaderboard class. Refer to the leaderboard.cpp file for more information
//
*/

#ifndef LEADERBOARD_H
#define LEADERBOARD_H

#include <QTime>
#include <QMap>
#include <QString>

class Leaderboard
{
public:
    Leaderboard();

    ///
    /// \brief addNewRecord     Add a new ranking to the leaderboard.
    /// \param playerTime       QTime displaying the player's time.
    /// \param playerName       QString displaying the player's name.
    ///
    void addNewRecord(const QTime& playerTime, const QString& playerName);

    ///
    /// \brief getTopTime       The #1 time on the leaderboard (as a string).
    /// \return                 QString the top time on the leaderboard
    ///                         (converted from QTime).
    ///
    QString getTopTime() const;

    ///
    /// \brief getTopName       The name associated with the #1 time.
    /// \return                 QString the top name on the leaderboard.
    ///
    QString getTopName() const;

    ///
    /// \brief getAllRecords            Retrieve all leaderboard stats.
    /// \return                         QMap<QTime, QString> The Leaderboard Stats.
    ///
    QMap<QTime, QString> getAllRecords() const;

private:
    // Cannot have more than 5 entries on leaderboard
    const int MAX_ENTRIES = 5;

    // The leaderboard statistics
    QMap<QTime, QString> allRecords;

};

#endif // LEADERBOARD_H
