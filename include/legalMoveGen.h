#pragma once

#include <vector>

#include "makeMove.h"

std::vector<Move> generateMoves(const Board& board);
std::vector<Move> generateLegalMoves(const std::vector<Move>& pseudoLegalMoves, const Board& board);

static bool canCastle(const Board& board, const Move& move);