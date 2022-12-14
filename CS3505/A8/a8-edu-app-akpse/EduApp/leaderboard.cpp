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
//      This is the source file for the Leaderboard class.
//          It is in charge of adding and showing player statistics
//          to refer to after playing.
//
//      It is also responsible for sorting the best times in a leaderboard QMap
//          such that inserted times are sorted from Best to Worst in a 'ranking'
//          format, regardless of how the entry was initially inserted.
*/

#include "leaderboard.h"

Leaderboard::Leaderboard()
{
    // Initialize the Leaderboard with basic stats
    const QList<QTime> times = { QTime::fromString("00:01:15", "hh:mm:ss"),
                           QTime::fromString("00:01:00", "hh:mm:ss"),
                           QTime::fromString("00:00:45", "hh:mm:ss"),
                           QTime::fromString("00:00:15", "hh:mm:ss"),
                           QTime::fromString("00:00:30", "hh:mm:ss")
                         };

    const QList<QString> names = { "Emile",
                             "Michael",
                             "Stefan",
                             "Soli",
                             "Allen"
                           };

    for (int i = 0; i < MAX_ENTRIES; i++)
    {
        addNewRecord(times.at(i), names.at(i));
    }
}


///
/// \brief Leaderboard::addNewRecord    Add a new ranking to the leaderboard
/// \param playerTime                   QTime displaying the player's time
/// \param playerName                   QString displaying the player's name
///
void Leaderboard::addNewRecord(const QTime& playerTime, const QString& playerName)
{
    // Insert first mapping
    if (allRecords.isEmpty())
    {
        allRecords.insert(playerTime, playerName);
        return;
    }

    // Cannot insert beyond 5 entries
    if (allRecords.size() < MAX_ENTRIES)
    {
        allRecords.insert(playerTime, playerName);
    }
    else
    {
        // Search the times and see if the user's record time beats any of the best times on the leaderboard
        for (const QTime& entry : allRecords.keys())
        {
            // Only add record for same names if their time has improved
            const bool isPlayerInLeaderboard = allRecords.values().contains(playerName);
            const bool hasPlayerTimeImproved = playerTime <= allRecords.key(playerName);
            if (isPlayerInLeaderboard && !hasPlayerTimeImproved)
                return;

            if (playerTime <= entry)
            {
                allRecords.remove(entry);
                allRecords.insert(playerTime, playerName);
                return;
            }
        }
    }

    allRecords.values().sort();
}


///
/// \brief Leaderboard::getTopTime       The #1 time on the leaderboard (as a string).
/// \return QString                      The top time on the leaderboard
///                                      (converted from QTime).
///
QString Leaderboard::getTopTime() const
{
    return allRecords.firstKey().toString();
}


///
/// \brief Leaderboard::getTopName       The name associated with the #1 time.
/// \return QString                      The top name on the leaderboard
///
QString Leaderboard::getTopName() const
{
    return allRecords.first();
}


///
/// \brief Leaderboard::getAllRecords       Retrieve all leaderboard stats
/// \return QMap<QTime, QString>            The Leaderboard Stats
///
QMap<QTime, QString> Leaderboard::getAllRecords() const
{
    return allRecords;
}
