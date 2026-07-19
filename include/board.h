#pragma once

enum Piece
{
    EMPTY = 0,
    W_PAWN, W_KNIGHT, W_BISHOP, W_ROOK, W_QUEEN, W_KING,
    B_PAWN, B_KNIGHT, B_BISHOP, B_ROOK, B_QUEEN, B_KING
};

struct Board
{
    enum Piece squares[64];
    bool whiteToMove;
    bool castleWK, castleWQ, castleBK, castleBQ;
    int enPassantSquare;

    void init();
    void print() const;
};

char pieceToChar(int piece);

