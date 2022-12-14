/*
// File name: lcdclock.cpp
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
//      LCDClock is a widget that handles keeping track of an elapsed time, as well as
//          displaying it to the user.
*/

#include "lcdclock.h"


///
/// \brief LCDClock::LCDClock   Initializes the stored & displayed time, and starts the timer.
/// \param parent               Default argument of QT widget.
///
LCDClock::LCDClock(QWidget* parent)
    : QLCDNumber(parent)
{
    // Initialize the timers
    updateTimer.setInterval(1000);
    elapsedTime = QTime(0, 0);

    // Update the display to 0, doing it directly in the constructor will NOT work
    QTimer::singleShot(0.05f, this, [this]() -> void {display("00:00");} );

    // At regular intervals, allow the displayed timer to get updated
    connect(&updateTimer,
            &QTimer::timeout,
            this,
            &LCDClock::addOneSecond);
}


///
/// \brief LCDClock::getTime    Returns the currently elapsed time.
/// \return                     A QTime of how much time has elapsed.
///
QTime LCDClock::getTime()
{
    return elapsedTime;
}


///
/// \brief LCDClock::startTimer     Starts the timer.
///
void LCDClock::startTimer()
{
    updateTimer.start();
}


///
/// \brief LCDClock::stopTimer      Stops the timer.
///
void LCDClock::stopTimer()
{
    updateTimer.stop();
}


///
/// \brief LCDClock::resetTimer     Resets the timer.
///
void LCDClock::resetTimer()
{
    elapsedTime = QTime(0, 0);
    refreshDisplayedTime();
}


///
/// \brief LCDClock::addOneSecond   Add one second to the elapsed time.
///
void LCDClock::addOneSecond()
{
    // Add a second to the time
    elapsedTime = elapsedTime.addSecs(1);

    // Update the displayed time
    refreshDisplayedTime();
}


///
/// \brief LCDClock::refreshDisplayedTime   Refresh the time being displayed to the user.
///
void LCDClock::refreshDisplayedTime() {
    QString timeString = elapsedTime.toString("mm:ss");
    display(timeString);
}
