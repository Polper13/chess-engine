#pragma once

#include <vector>

#include "makeMove.h"

std::vector<Move> generateLegalMoves(const std::vector<Move>& pseudoLegalMoves, const Board& board);
static bool canCastle(const Board& board, const Move& move);