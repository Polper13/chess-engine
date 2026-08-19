#pragma once

#include "moveGen.h"

void makeMove(Board& board, const Move& move);

static void handleEnPassant(Board& board, const Move& move);
static void handleCastle(Board& board, const Move& move);

static bool calculateEnPassantSquare(const Move& move, Piece piece);