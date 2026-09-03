#include "piece.h"

bool isWhitePiece(Piece piece)
{
    return piece > 0 && piece <= 6;
}

bool isEnemyPiece(Piece piece, bool isWhiteFriendly)
{
    if (piece == EMPTY) return false;
    return isWhiteFriendly != isWhitePiece(piece);
}

bool isFriendlyPiece(Piece piece, bool isWhiteFriendly)
{
    if (piece == EMPTY) return false;
    return isWhiteFriendly == isWhitePiece(piece);
}

bool isPawn(Piece piece)
{
    return piece == W_PAWN || piece == B_PAWN;
}

bool isKnight(Piece piece)
{
    return piece == W_KNIGHT || piece == B_KNIGHT;
}

char pieceToChar(int piece) 
{
    static const char chars[] = { '.', 'P','N','B','R','Q','K', 'p','n','b','r','q','k' };
    return chars[piece];
}