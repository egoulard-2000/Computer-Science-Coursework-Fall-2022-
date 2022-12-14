/*
// File name: filehandling.cpp
// Author:    Allen
// Assignment:Sprite Editor
// Group:     AKPSE
// Date:      11/15/2022
// Course:    CS 3505, University of Utah, School of Computing
// Copyright: CS 3505 and AKPSE - This work may not be copied for use in Academic Coursework.
//
// Our group, AKPSE, certifies that we wrote this code from scratch and did not copy it in part or whole from
// another source.
//
// File Contents
//
//      This is the source file that implements the userhistory class. This class
//        stores a history of Animation states, and provides an API for developers to redo/undo to any saved states.
*/

#include "userhistory.h"


///
/// \brief UserHistory::UserHistory     Default constructor of QObject
/// \param newAnimation                 The current animation that the user starts with.
///
UserHistory::UserHistory(const Animation& newAnimation) : curAnimation(newAnimation)
{
}


///
/// \brief UserHistory::saveFramesToHistory     Saves a new Animation into the stored history,
///                                             and deletes any redo saves if applicable.
/// \param newAnimation                         New Animation to store.
///
void UserHistory::saveAnimationToHistory(const Animation& newAnimation)
{
    // A new series of actions is being performed, delete the redo saves
    redoHistory.clear();

    // Store the old Animation in the history (trim the history if it gets too big)
    undoHistory.append(curAnimation);
    if (undoHistory.count() > historyMaxSaveCount)
        undoHistory.removeFirst();

    // Store the new Animation
    curAnimation = newAnimation;
}


///
/// \brief UserHistory::undoAction  Returns the previous saved state of the Sprite being edited.
/// \return                         Animation containing the previous saved Sprite info.
///
Animation UserHistory::undoAction()
{
    // Guard Clause: If undo isn't possible, simply return the current animation
    if (!canUndo())
        return curAnimation;

    // Save the current animation
    redoHistory.append(curAnimation);

    // Extract the previous saved Sprite
    curAnimation = undoHistory.last();
    undoHistory.removeLast();

    // Return the previously saved Sprite
    return curAnimation;
}


///
/// \brief UserHistory::redoAction  Returns the future saved state of the Sprite being edited.
///                                 ("future" as in "before undo was pressed")
/// \return                         Animation containing the future saved Sprite info.
///
Animation UserHistory::redoAction()
{
    // Guard Clause: If redo isn't possible, simply return the current animation
    if (!canRedo())
        return curAnimation;

    // Save the current animation
    undoHistory.append(curAnimation);

    // Extract the previous saved Sprite
    curAnimation = redoHistory.last();
    redoHistory.removeLast();

    // Return the previously saved Sprite
    return curAnimation;
}


///
/// \brief UserHistory::canUndo     Returns whether the undo action can be performed or not.
/// \return                         True if undo can be performed (saved history exists), false otherwise.
///
bool UserHistory::canUndo()
{
    return undoHistory.count() > 0;
}


///
/// \brief UserHistory::canRedo     Returns whether the redo action can be performed or not.
/// \return                         True of redo can be performed (saved states exist), false otherwise.
///
bool UserHistory::canRedo()
{
    return redoHistory.count() > 0;
}
