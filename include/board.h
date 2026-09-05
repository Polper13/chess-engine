#pragma once

#include "piece.h"

struct Board
{
    enum Piece squares[64];
    bool whiteToMove;
    bool castleWK, castleWQ, castleBK, castleBQ;
    int enPassantSquare;
    int whiteKingSquare, blackKingSquare;

    void init();
    void print() const;
};