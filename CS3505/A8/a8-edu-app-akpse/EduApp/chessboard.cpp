/*
// File name: chessboard.h
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
//      ChessBoard is a class that represents a Chess Board, and all its pieces.
        Though the pieces can be moved around and their potential moves viewed,
        the board does not enforce any rules.

        Note: All ChessPiece pointers given to this object will be safely
            garbage collected by this class.
*/

#include "chessboard.h"

///
/// \brief ChessBoard::ChessBoard   Constructs a Chess board
/// \param initialBoard             The initial pieces to lay on the board.
///
ChessBoard::ChessBoard(QMap<ChessPosition, ChessPiece*> initialBoard)
    : pieces(initialBoard)
{

}


///
/// \brief ChessBoard::~ChessBoard  Destructor for the chess board.
///
ChessBoard::~ChessBoard()
{
    qDeleteAll(pieces);
}


///
/// \brief ChessBoard::addPiece     Adds a ChessPiece to the board.
/// \param pos                      The position to add the piece to.
/// \param newPiece                 The new piece to add.
///
void ChessBoard::addPiece(ChessPosition pos, ChessPiece* newPiece)
{
    pieces[pos] = newPiece;
}


///
/// \brief ChessBoard::movePiece    Move a chess piece.
/// \param move                     The ChessMove to complete.
///
void ChessBoard::movePiece(ChessMove move)
{
    // Delete any captured pieces
    if(move.hasCaptured())
        pieces.remove(move.whoWasCaptured());

    // Move the piece to its new location
    pieces[move.getNewPosition()] = pieces[move.getOldPosition()];
    pieces.remove(move.getOldPosition());
}


///
/// \brief ChessBoard::hasPiece     Returns whether a piece exists at a position.
/// \param pos                      The position to check.
/// \return                         True if a piece exists. False otherwise.
///
bool ChessBoard::hasPiece(const ChessPosition& pos) const
{
    return pieces.contains(pos);
}


ChessPiece* ChessBoard::getPiece(const ChessPosition& pos) const
{
    return pieces[pos];
}


///
/// \brief ChessBoard::getMoves     Gets all possible moves for a piece.
/// \param pos                      The position that the piece is located at.
/// \return                         All possible moves that the piece can perform.
/// \exception                      Throws an invalid_argument exception if no
///                                     pieces exist at the position.
///
QVector<ChessMove> ChessBoard::getMoves(ChessPosition pos) const
{
    // Error checking if piece exists
    if(!pieces.contains(pos))
        throw std::invalid_argument("No pieces exist at the specified position.");

    return pieces[pos]->possibleMoves(pos, pieces);
}


///
/// \brief ChessBoard::getAllPieces     Returns all the pieces on the board.
/// \return                             All the pieces on the board.
///
QMap<ChessPosition, ChessPiece*> ChessBoard::getAllPieces() const
{
    return pieces;
}


///
/// \brief operator <<  Allows "qDebug() << ChessBoard" to work.
/// \param debug        The QDebug object to insert into.
/// \param board        The ChessMove to print.
/// \return             The QDebug that was inserted into.
///
QDebug operator<<(QDebug debug, const ChessBoard& board)
{
    QDebugStateSaver saver(debug);

    // Edge Case: Board is empty.
    QMap<ChessPosition, ChessPiece*> pieces = board.getAllPieces();
    if(pieces.count() == 0)
    {
        debug << "Empty ChessBoard";
        return debug;
    }

    // Print the first piece on the board
    auto itr = pieces.constBegin();
    ChessPosition pos = itr.key();
    ChessPiece* piece = itr.value();
    debug << *piece << pos;
    ++itr;

    // Print the rest of the pieces on the board
    for(; itr != pieces.constEnd(); ++itr)
    {
        ChessPosition pos = itr.key();
        ChessPiece* piece = itr.value();

        debug << "|" << *piece << pos;
    }

    return debug;
}

