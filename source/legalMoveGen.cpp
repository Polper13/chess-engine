#include "legalMoveGen.h"
#include "attack.h"

std::vector<Move> generateLegalMoves(const std::vector<Move>& pseudoLegalMoves, const Board& board)
{
    std::vector<Move> legalMoves;

    for (const Move& move : pseudoLegalMoves)
    {
        Board copy = board;
        makeMove(copy, move);

        // perform the pseudo move on a copy of the board
        int kingSquare = (board.whiteToMove) ? copy.whiteKingSquare : copy.blackKingSquare;
        if (isSquareAttacked(copy, kingSquare, !board.whiteToMove))
            continue; // abort because ended up in check

        if (move.isCastle && !canCastle(board, move)) continue;

        legalMoves.push_back(move);
    }
    return legalMoves;
}

static bool canCastle(const Board& board, const Move& move)
{
    int direction = (move.to - move.from > 0) ? 1 : -1;
    int testPosition = move.from;

    while (testPosition != move.to)
    {
        Board copy = board;
        Piece king = board.squares[move.from];
        copy.squares[move.from] = EMPTY;
        copy.squares[testPosition] = king;

        if (isSquareAttacked(copy, testPosition, !board.whiteToMove)) return false;
        testPosition += direction;
    }
    return true;
}