/*
// File name: userhistory.h
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
//      This is the header file for the userhistory class.
//                  Please see UserHistory.cpp for details.
*/


#ifndef USERHISTORY_H
#define USERHISTORY_H

#include "animation.h"
#include <QObject>


///
/// \brief The UserHistory class stores a history of the different states
///             that the current Sprite has undergone (i.e frame images & their order).
///             This can be used to traverse "back in time" if the user wants to
///             correct any errors.
///
class UserHistory
{
  public:
    ///
    /// \brief UserHistory::UserHistory     Default constructor of QObject
    /// \param newAnimation                 The current animation that the user starts with.
    ///
    UserHistory(const Animation& currentAnimation);

    ///
    /// \brief UserHistory::saveFramesToHistory     Saves a new Animation into the stored history,
    ///                                             and deletes any redo saves if applicable.
    /// \param newAnimation                         New Animation to store.
    ///
    void saveAnimationToHistory(const Animation& newAnimation);

    ///
    /// \brief UserHistory::undoAction  Returns the previous saved state of the Sprite being edited.
    /// \return                         Animation containing the previous saved Sprite info.
    ///
    Animation undoAction();

    ///
    /// \brief UserHistory::redoAction  Returns the future saved state of the Sprite being edited.
    ///                                 ("future" as in "before undo was pressed")
    /// \return                         Animation containing the future saved Sprite info.
    ///
    Animation redoAction();

    ///
    /// \brief UserHistory::canUndo     Returns whether the undo action can be performed or not.
    /// \return                         True if undo can be performed (saved history exists), false otherwise.
    ///
    bool canUndo();

    ///
    /// \brief UserHistory::canRedo     Returns whether the redo action can be performed or not.
    /// \return                         True of redo can be performed (saved states exist), false otherwise.
    ///
    bool canRedo();

  private:
    static const int historyMaxSaveCount = 10;

    Animation curAnimation;
    QList<Animation> undoHistory;
    QList<Animation> redoHistory;
};

#endif // USERHISTORY_H
