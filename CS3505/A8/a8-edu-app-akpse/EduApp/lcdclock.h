/*
// File name: lcdclock.h
// Author:    Stefan, Allen, Soli
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
//      lcdclock.h defines the LCDClock class, which inherits from QLCDNumber.
//      This is a timer that counts up from 0.
*/

#ifndef LCDCLOCK_H
#define LCDCLOCK_H

#include <QLCDNumber>
#include <QTimer>
#include <QTime>

class LCDClock : public QLCDNumber
{
    Q_OBJECT

public:
    ///
    /// \brief LCDClock::LCDClock   Initializes the stored & displayed time, and starts the timer.
    /// \param parent               Default argument of QT widget.
    ///
    LCDClock(QWidget* parent = nullptr);

    ///
    /// \brief LCDClock::getTime    Returns the currently elapsed time.
    /// \return                     A QTime of how much time has elapsed.
    ///
    QTime getTime();

    ///
    /// \brief isRunning            Returns true if timer is running.
    /// \return                     True if running, false otherwise
    ///
    inline bool isRunning() {return updateTimer.isActive();}

public slots:

    ///
    /// \brief LCDClock::startTimer     Starts the timer.
    ///
    void startTimer();

    ///
    /// \brief LCDClock::stopTimer      Stops the timer.
    ///
    void stopTimer();

    ///
    /// \brief LCDClock::resetTimer     Resets the timer.
    ///
    void resetTimer();

private slots:

    ///
    /// \brief LCDClock::addOneSecond   Add one second to the elapsed time.
    ///
    void addOneSecond();

private:
    QTimer updateTimer; // What interval to update the display at.
    QTime elapsedTime;  // Currently elapsed time.

    ///
    /// \brief LCDClock::refreshDisplayedTime   Refresh the time being displayed to the user.
    ///
    void refreshDisplayedTime();
};

#endif // LCDCLOCK_H
