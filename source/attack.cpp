#include <stdlib.h>

#include "attack.h"

bool isSquareAttacked(const Board& board, int square, bool byWhite)
{
    return isAttackedByPawn(board, square, byWhite)
        || isAttackedByKnight(board, square, byWhite)
        || isAttackedByKing(board, square, byWhite)
        || isAttackedByBishop(board, square, byWhite)
        || isAttackedByRook(board, square, byWhite)
        || isAttackedByQueen(board, square, byWhite);
}

static bool isAttackedByPawn(const Board& board, int square, bool byWhite)
{
    int file = square % 8;
    int rank = square / 8;

    int attackerRank = (byWhite) ? rank - 1 : rank + 1;
    if (attackerRank < 0 || attackerRank > 7) return false;

    Piece attackerPiece = (byWhite) ? W_PAWN : B_PAWN;

    for (int offset : { -1, 1 })
    {
        int attackerFile = file + offset;
        if (attackerFile < 0 || attackerFile > 7) continue;

        int attackerSquare = attackerRank * 8 + attackerFile;
        if (board.squares[attackerSquare] == attackerPiece) return true;
    }

    return false;
}

static bool isAttackedByKnight(const Board& board, int square, bool byWhite)
{
    Piece attackerPiece = (byWhite) ? W_KNIGHT : B_KNIGHT;
    return isAttackedByLeaperPiece(board, square, attackerPiece, KNIGHT_OFFSETS, 2);
}

static bool isAttackedByKing(const Board& board, int square, bool byWhite)
{
    Piece attackerPiece = (byWhite) ? W_KING : B_KING;
    return isAttackedByLeaperPiece(board, square, attackerPiece, KING_OFFSETS, 1);
}

static bool isAttackedByBishop(const Board& board, int square, bool byWhite)
{
    Piece piece = (byWhite) ? W_BISHOP : B_BISHOP;
    return isAttackedBySlidingPiece(board, square, piece, BISHOP_OFFSETS);
}

static bool isAttackedByRook(const Board& board, int square, bool byWhite)
{
    Piece piece = (byWhite) ? W_ROOK : B_ROOK;
    return isAttackedBySlidingPiece(board, square, piece, ROOK_OFFSETS);
}

static bool isAttackedByQueen(const Board& board, int square, bool byWhite)
{
    Piece piece = (byWhite) ? W_QUEEN : B_QUEEN;
    return isAttackedBySlidingPiece(board, square, piece, QUEEN_OFFSETS);
}

static bool isAttackedByLeaperPiece(const Board& board, int square, Piece attackerPiece, std::span<const int> offsets, int maxFileDelta)
{
    int file = square % 8;

    for (int offset : offsets)
    {
        int attackerSquare = square + offset;
        if (attackerSquare < 0 || attackerSquare >= 64) continue;

        int attackerFile = attackerSquare % 8;
        if (abs(file - attackerFile) > maxFileDelta) continue;

        if (board.squares[attackerSquare] == attackerPiece) return true;
    }

    return false;
}

static bool isAttackedBySlidingPiece(const Board& board, int square, Piece attackerPiece, std::span<const int> offsets)
{
    int file = square % 8;

    for (int offset : offsets)
    {
        for (int i = 1; ; i++)
        {
            int attackerSquare = square + offset * i;
            if (attackerSquare < 0 || attackerSquare >= 64) break;

            int attackerFile = attackerSquare % 8;
            int fileDelta = abs(file - attackerFile);
            if (fileDelta != i && fileDelta != 0) break;

            if (board.squares[attackerSquare] == attackerPiece) return true;

            if (board.squares[attackerSquare] != EMPTY) break;
        }
    }

    return false;
}