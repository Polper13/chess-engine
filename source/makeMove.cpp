#include "makeMove.h"

void makeMove(Board& board, const Move& move)
{
    if (move.isCastle) handleCastle(board, move);
    if (move.isEnPassant) handleEnPassant(board, move);

    Piece piece = (move.promotion != EMPTY) ? move.promotion : board.squares[move.from];

    board.squares[move.to] = piece;
    board.squares[move.from] = EMPTY;

    board.enPassantSquare = calculateEnPassantSquare(move, piece);
    board.whiteToMove = !board.whiteToMove;
}

static void handleEnPassant(Board& board, const Move& move)
{
    int offset = (board.whiteToMove) ? -8 : 8;
    board.squares[move.to + offset] = EMPTY;
}

static void handleCastle(Board& board, const Move& move)
{
    Piece rook = (board.whiteToMove) ? W_ROOK : B_ROOK;

    int moveFile = move.to % 8;
    int moveRank = move.to / 8;

    int rookFile = (moveFile == 2) ? 0 : 7;
    int targetRookFile = (moveFile == 2) ? 3 : 5;

    // make the moves
    board.squares[moveRank * 8 + rookFile] = EMPTY;
    board.squares[moveRank * 8 + targetRookFile] = rook;

    // update castling rights
    if (board.whiteToMove)
        board.castleWK = board.castleWQ = false;
    else
        board.castleBK = board.castleBQ = false;
}

static int calculateEnPassantSquare(const Move& move, Piece piece)
{
    int fromRank = move.from / 8;
    int toRank = move.to / 8;

    // check if move qualifies for en passant
    if (abs(toRank - fromRank) == 2 && isPawn(piece))
    {
        int file = move.to % 8;
        int rank = (fromRank + toRank) / 2;

        return rank * 8 + file;
    }
    else return -1;
}