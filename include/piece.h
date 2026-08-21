#pragma once

enum Piece
{
    EMPTY = 0,
    W_PAWN, W_KNIGHT, W_BISHOP, W_ROOK, W_QUEEN, W_KING,
    B_PAWN, B_KNIGHT, B_BISHOP, B_ROOK, B_QUEEN, B_KING
};

static constexpr int[8] KNIGHT_OFFSETS = { 17, 15, 10, 6, -6, -10, -15, -17 };
static constexpr int[8] KING_OFFSETS = { -8, 8, -1, 1, -9, 9, -7, 7 };
static constexpr int[8] QUEEN_OFFSETS = { -8, 8, -1, 1, -9, 9, -7, 7 };
static constexpr int[4] ROOK_OFFSETS = { -8, 8, -1, 1 };
static constexpr int[4] BISHOP_OFFSETS = { -9, 9, -7, 7 };

bool isWhitePiece(Piece piece);
bool isEnemyPiece(Piece piece, bool isWhiteFriendly);
bool isFriendlyPiece(Piece piece, bool isWhiteFriendly);

bool isPawn(Piece piece);

char pieceToChar(int piece);