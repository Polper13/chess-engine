#pragma once

#include <vector>
#include <span>

#include "board.h"

struct Move
{
    int from;
    int to;
    enum Piece promotion = EMPTY;
    bool isCastle = false;
    bool isEnPassant = false;

    void print();
    void printUCI();
};

std::vector<Move> generatePseudoLegalMoves(const Board& board);

void generatePawnMoves(const Board& board, int square, std::vector<Move>& moves);
void generateKnightMoves(const Board& board, int square, std::vector<Move>& moves);
void generateKingMoves(const Board& board, int square, std::vector<Move>& moves);
void generateQueenMoves(const Board& board, int square, std::vector<Move>& moves);
void generateRookMoves(const Board& board, int square, std::vector<Move>& moves);
void generateBishopMoves(const Board& board, int square, std::vector<Move>& moves);

void generateSlidingMoves(const Board& board, int square, std::vector<Move>& moves, std::span<const int> offsets);