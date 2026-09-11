#pragma once

#include "legalMoveGen.h"

int perft(const Board& board, int depth);
void perftDivide(const Board& board, int depth);