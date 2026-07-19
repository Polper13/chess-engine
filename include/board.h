#pragma once

#include "piece.h"

struct Board
{
    enum Piece squares[64];
    bool whiteToMove;
    bool castleWK, castleWQ, castleBK, castleBQ;
    int enPassantSquare;

    void init();
    void print() const;
};