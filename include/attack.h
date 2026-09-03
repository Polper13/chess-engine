#pragma once

#include "board.h"

bool isSquareAttacked(const Board& board, int square, bool byWhite);

static bool isAttackedByPawn(const Board& board, int square, bool byWhite);
static bool isAttackedByKnight(const Board& board, int square, bool byWhite);
static bool isAttackedByKing(const Board& board, int square, bool byWhite);

static bool isAttackedByBishop(const Board& board, int square, bool byWhite);
static bool isAttackedByRook(const Board& board, int square, bool byWhite);
static bool isAttackedByQueen(const Board& board, int square, bool byWhite);

static bool isAttackedByLeaperPiece(const Board& board, int square, Piece attackerPiece, std::span<const int> offsets, int maxFileDelta);
static bool isAttackedBySlidingPiece(const Board& board, int square, Piece attackerPiece, std::span<const int> offsets);