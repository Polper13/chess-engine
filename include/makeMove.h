#pragma once

#include "moveGen.h"

void makeMove(Board& board, const Move& move);

static void handleEnPassant(Board& board, const Move& move);
static void handleCastle(Board& board, const Move& move);
static void handleKingTracking(Board& board, const Move& move);
static void handleCastlingRights(Board& board, const Move& move);

static int calculateEnPassantSquare(const Move& move, Piece piece);