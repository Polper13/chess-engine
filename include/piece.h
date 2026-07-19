#pragma once

enum Piece
{
    EMPTY = 0,
    W_PAWN, W_KNIGHT, W_BISHOP, W_ROOK, W_QUEEN, W_KING,
    B_PAWN, B_KNIGHT, B_BISHOP, B_ROOK, B_QUEEN, B_KING
};

bool isWhitePiece(Piece piece);
bool isEnemyPiece(Piece piece, bool isWhiteFriendly);
bool isFriendlyPiece(Piece piece, bool isWhiteFriendly);

char pieceToChar(int piece);