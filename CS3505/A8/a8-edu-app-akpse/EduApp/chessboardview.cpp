/*
// File name: chessboardview.cpp
// Author:    Allen, Soli, Stefan
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
//      This file implements the ChessBoardView class. This is used to display the current state
//      of the board, as well as to handle user inputs.
*/

#include "chessboardview.h"
#include <QDebug>

///
/// \brief Sets the board's image to input image
/// \param Image to set board to
///
ChessBoardView::ChessBoardView(QWidget *widget) : QGraphicsView(widget)
{
    setAcceptDrops(true);
}


///
/// \brief  Handle when the mouse has began interacting with the board.
///         If the mouse clicks on a valid part of the board,
///         getBoardPosition() will emit which ChessPosition was clicked.
/// \param the mouse event to handle
///
void ChessBoardView::mousePressEvent(QMouseEvent* event)
{
    // Declare constants
    const int height = currentChessBoardImage.height();
    const int width = currentChessBoardImage.width();

    // Calculate the pixel the mouse is currenty hovering over
    const QPointF posFloat = mapToScene(event->pos());
    const QPoint pos(posFloat.x() * 8 / width, posFloat.y() * 8 / height);

    // If mouse position is outside of chess board, don't emit anything
    if(pos.x() < 0 || pos.x() >= 8 || pos.y() < 0 || pos.y() >= 8)
        return;

    // Convert the mouse position to a valid ChessPosition
    ChessPosition chessPos = ChessPosition((ChessPosition::horizontal)pos.x(), (ChessPosition::vertical)(7 - pos.y()));

    // Emit the ChessPosition that the mouse has clicked.
    emit getBoardPosition(chessPos);
}


///
/// \brief Sends an update when the widget is resized on the main canvas
/// \param QResizeEvent pointer to send
///
void ChessBoardView::resizeEvent(QResizeEvent*)
{
    redrawBoard(currentPieces, currentMoves);
}


///
/// \brief Sends an update when the widget is shown on the main canvas
/// \param QShowEvent pointer to send
///
void ChessBoardView::showEvent(QShowEvent*)
{
    redrawBoard(currentPieces, currentMoves);
}


///
/// \brief ChessBoardView::updatePieces     A slot to update the pieces displayed
///                                         on the board. This will also
///                                         hide any currently highlighted
///                                         "possible moves".
/// \param newPieces                        The new pieces to display.
///
void ChessBoardView::updatePieces(QMap<ChessPosition, ChessPiece*> newPieces)
{
    currentPieces = newPieces;

    redrawBoard(currentPieces, currentMoves);
}


///
/// \brief ChessBoardView::updateHighlightedMoves   A slot to update the currently
///                                                 highlighted squares, usually
///                                                 corresponding to where a
///                                                 ChessPiece may move.
/// \param newMoves                                 The new ChessPosition's
///                                                 to highlight.
///
void ChessBoardView::updateHighlightedMoves(QVector<ChessPosition> newMoves)
{
    currentMoves = newMoves;

    redrawBoard(currentPieces, currentMoves);
}


///
/// \brief ChessBoardView::redrawBoard  Redraw what's being displayed.
///
void ChessBoardView::redrawBoard(QMap<ChessPosition, ChessPiece*> pieces, QVector<ChessPosition> moves)
{
    // Declare constants
    const int tileWidth = currentChessBoardImage.width() / 8;

    // Set up the scene & chess-board to draw on
    auto scene = new QGraphicsScene(this);
    scene->setSceneRect(currentChessBoardImage.rect());
    scene->addPixmap(QPixmap::fromImage(currentChessBoardImage));

    // Draw all the pieces
    for(auto itr = pieces.begin(); itr != pieces.end(); ++itr)
    {
        // Extract data about piece
        ChessPosition curPos = itr.key();
        ChessPiece* curPiece = itr.value();

        // Find image to display
        QPixmap pieceImage = findPixmapForPiece(curPiece);
        pieceImage = pieceImage.scaled(currentChessBoardImage.height() / 8, currentChessBoardImage.width() / 8);
        QGraphicsPixmapItem* pieceItem = new QGraphicsPixmapItem(pieceImage);

        // Find position to display image (convert to top-left being the origin)
        int xPos = (int)curPos.hPos;
        int yPos = 7 - (int)curPos.vPos;
        pieceItem->setPos(xPos * tileWidth, yPos * tileWidth);

        // Add image to scene
        scene->addItem(pieceItem);
    }

    // Draw all potential moves
    QListIterator moveItr(moves);
    while(moveItr.hasNext())
    {
        // Extract data about move
        ChessPosition curPos = moveItr.next();

        // The image to display
        QPixmap movePixmap = QPixmap::fromImage(movePosImage);
        movePixmap = movePixmap.scaled(currentChessBoardImage.height() / 8, currentChessBoardImage.width() / 8);
        QGraphicsPixmapItem* moveItem = new QGraphicsPixmapItem(movePixmap);

        // Find position to display image (convert to top-left being the origin)
        int xPos = (int)curPos.hPos;
        int yPos = 7 - (int)curPos.vPos;
        moveItem->setPos(xPos * tileWidth, yPos * tileWidth);

        // Add image to scene
        scene->addItem(moveItem);
    }

    // Display the scene
    setScene(scene);
    fitInView(scene->sceneRect(), Qt::AspectRatioMode::KeepAspectRatio);
}


///
/// \brief findPixmapForPiece   A helper method that returns what Pixmap
///                             to display for a given ChessPiece child.
/// \param piece                The ChessPiece to find the Pixmap for.
/// \return                     The Pixmap for the ChessPiece.
///
QPixmap ChessBoardView::findPixmapForPiece(ChessPiece* piece)
{
    if(dynamic_cast<BishopPiece*>(piece) != NULL)
    {
        if(piece->isWhite())
            return QPixmap(":images/wBishop.png");
        else
            return QPixmap(":images/bBishop.png");
    }

    else if(dynamic_cast<KingPiece*>(piece) != NULL)
    {
        if(piece->isWhite())
            return QPixmap(":images/wKing.png");
        else
            return QPixmap(":images/bKing.png");
    }

    else if(dynamic_cast<KnightPiece*>(piece) != NULL)
    {
        if(piece->isWhite())
            return QPixmap(":images/wKnight.png");
        else
            return QPixmap(":images/bKnight.png");
    }

    else if(dynamic_cast<PawnPiece*>(piece) != NULL)
    {
        if(piece->isWhite())
            return QPixmap(":images/wPawn.png");
        else
            return QPixmap(":images/bPawn.png");
    }

    else if(dynamic_cast<QueenPiece*>(piece) != NULL)
    {
        if(piece->isWhite())
            return QPixmap(":images/wQueen.png");
        else
            return QPixmap(":images/bQueen.png");
    }

    else if(dynamic_cast<RookPiece*>(piece) != NULL)
    {
        if(piece->isWhite())
            return QPixmap(":images/wRook.png");
        else
            return QPixmap(":images/bRook.png");
    }

    else
    {
        throw std::invalid_argument("Unknown ChessPiece type.");
    }
}
