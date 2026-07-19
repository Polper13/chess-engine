#pragma once

#include <vector>

#include "board.h"

struct Move
{
    int from;
    int to;
    enum Piece promotion = EMPTY;
    bool isCastle = false;
    bool isEnPassant = false;

    void print();
};

std::vector<Move> generatePseudoLegalMoves(Board& board);
std::vector<Move> generateLegalMoves(Board& board);

void generatePawnMoves(Board& board, int square, std::vector<Move>& moves);
void generateKnightMoves(Board& board, int square, std::vector<Move>& moves);

bool isEnemyPiece(Piece piece, bool isWhiteFriendly);