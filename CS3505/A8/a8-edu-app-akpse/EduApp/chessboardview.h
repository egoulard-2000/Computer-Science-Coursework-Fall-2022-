/*
// File name: chessboardview.h
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
//      chessboardview.h is the header file for chessboardview.cpp. This is
//      inherits from QGraphicsView, and is used to display the current state
//      of the board, as well as to handle user inputs.
*/

#ifndef CHESSBOARDVIEW_H
#define CHESSBOARDVIEW_H

#include "bishoppiece.h"
#include "chessboard.h"
#include "chessposition.h"
#include "kingpiece.h"
#include "knightpiece.h"
#include "pawnpiece.h"
#include "queenpiece.h"
#include "rookpiece.h"
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QMouseEvent>

class ChessBoardView : public QGraphicsView
{
    Q_OBJECT;

public:
    using QGraphicsView::QGraphicsView;

    ///
    /// \brief Sets the board's image to input image
    /// \param Image to set board to
    ///
    explicit ChessBoardView(QWidget* widget = nullptr);

signals:
    void getBoardPosition(ChessPosition point);

public slots:
    ///
    /// \brief ChessBoardView::updatePieces     A slot to update the pieces displayed
    ///                                         on the board. This will also
    ///                                         hide any currently highlighted
    ///                                         "possible moves".
    /// \param newPieces                        The new pieces to display.
    ///
    void updatePieces(QMap<ChessPosition, ChessPiece*> board);

    ///
    /// \brief ChessBoardView::updateHighlightedMoves   A slot to update the currently
    ///                                                 highlighted squares, usually
    ///                                                 corresponding to where a
    ///                                                 ChessPiece may move.
    /// \param newMoves                                 The new ChessPosition's
    ///                                                 to highlight.
    ///
    void updateHighlightedMoves(QVector<ChessPosition> moves);

private:
    QImage currentChessBoardImage = QImage(":images/chessboard_olive.jpg");
    QImage movePosImage = QImage(":/images/blHighlight.png");

    QMap<ChessPosition, ChessPiece*> currentPieces;

    QVector<ChessPosition> currentMoves;

    ///
    /// \brief  Handle when the mouse has began interacting with the board.
    ///         If the mouse clicks on a valid part of the board,
    ///         getBoardPosition() will emit which ChessPosition was clicked.
    /// \param the mouse event to handle
    ///
    void mousePressEvent(QMouseEvent* event) override;

    ///
    /// \brief Sends an update when the widget is resized on the main canvas
    /// \param QResizeEvent pointer to send
    ///
    void resizeEvent(QResizeEvent*) override;

    ///
    /// \brief Sends an update when the widget is shown on the main canvas
    /// \param QShowEvent pointer to send
    ///
    void showEvent(QShowEvent*) override;

    ///
    /// \brief ChessBoardView::redrawBoard  Redraw what's being displayed.
    ///
    void redrawBoard(QMap<ChessPosition, ChessPiece*> pieces, QVector<ChessPosition> moves);

    ///
    /// \brief findPixmapForPiece   A helper method that returns what Pixmap
    ///                             to display for a given ChessPiece child.
    /// \param piece                The ChessPiece to find the Pixmap for.
    /// \return                     The Pixmap for the ChessPiece.
    ///
    QPixmap findPixmapForPiece(ChessPiece* piece);
};

#endif // CHESSBOARDVIEW_H
