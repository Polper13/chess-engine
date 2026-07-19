#include <iostream>

#include "moveGen.h"

void Move::print()
{
    char fromRank = '1' + from / 8;
    char fromFile = 'a' + from % 8;
    char toRank = '1' + to / 8;
    char toFile = 'a' + to % 8;

    char promotionChar = pieceToChar(promotion);
    char castleChar = (isCastle) ? 'y' : 'n';
    char enPassChar = (isEnPassant) ? 'y' : 'n';

    std::cout << fromFile << fromRank << toFile << toRank << " ( promotion: " << promotionChar << " castle: " << castleChar << " enpassant: " << enPassChar << " )" << std::endl;
}

void generatePawnMoves(Board& board, int square, std::vector<Move>& moves)
{
    bool isWhite = board.squares[square] == W_PAWN;
    int from = square;
    int to;

    int rank = square / 8 + 1;
    int file = square % 8 + 1;
    bool isStarting = (isWhite && rank == 2) || (!isWhite && rank == 7);

    // forward
    to = (isWhite) ? square + 8 : square - 8;
    if (board.squares[to] == EMPTY) // if empty in front of him
    {

        if ((isWhite && rank == 7) || (!isWhite && rank == 2)) // if at the edge of the board
        {
            moves.push_back({from, to, (isWhite) ? W_QUEEN : B_QUEEN});
            moves.push_back({from, to, (isWhite) ? W_ROOK : B_ROOK});
            moves.push_back({from, to, (isWhite) ? W_BISHOP : B_BISHOP});
            moves.push_back({from, to, (isWhite) ? W_KNIGHT : B_KNIGHT});
        }
        else // just regular move forward
        {
            moves.push_back({from, to});
        }

        if (isStarting && board.squares[isWhite ? to + 8 : to - 8] == EMPTY) // double forward move
        {
            moves.push_back({from, (isWhite) ? to + 8 : to - 8});
        }
    }

    // left
    to = (isWhite) ? square + 7 : square - 9;
    if (file != 1)
    {
        if (board.squares[to] != EMPTY && isEnemyPiece(board.squares[to], isWhite))
        {
            if ((isWhite && rank == 7) || (!isWhite && rank == 2)) // if at the edge of the board
            {
                moves.push_back({from, to, (isWhite) ? W_QUEEN : B_QUEEN});
                moves.push_back({from, to, (isWhite) ? W_ROOK : B_ROOK});
                moves.push_back({from, to, (isWhite) ? W_BISHOP : B_BISHOP});
                moves.push_back({from, to, (isWhite) ? W_KNIGHT : B_KNIGHT});   
            }
            else
            {
                moves.push_back({from, to});
            }
        }
        else if (to == board.enPassantSquare)
        {
            moves.push_back({from, to, EMPTY, false, true});
        }
    }

    // right
    to = (isWhite) ? square + 9 : square - 7;
    if (file != 8)
    {
        if (board.squares[to] != EMPTY && isEnemyPiece(board.squares[to], isWhite))
        {
            if ((isWhite && rank == 7) || (!isWhite && rank == 2)) // if at the edge of the board
            {
                moves.push_back({from, to, (isWhite) ? W_QUEEN : B_QUEEN});
                moves.push_back({from, to, (isWhite) ? W_ROOK : B_ROOK});
                moves.push_back({from, to, (isWhite) ? W_BISHOP : B_BISHOP});
                moves.push_back({from, to, (isWhite) ? W_KNIGHT : B_KNIGHT});   
            }
            else
            {
                moves.push_back({from, to});
            }
        }
        else if (to == board.enPassantSquare)
        {
            moves.push_back({from, to, EMPTY, false, true});
        }
    }
}

void generateKnightMoves(Board& board, int square, std::vector<Move>& moves)
{
    static const std::vector<int> knightOffsets = { 17, 15, 10, 6, -6, -10, -15, -17 };

    bool isWhite = board.squares[square] == W_KNIGHT;
    int file = square % 8;

    for (int offset : knightOffsets)
    {
        int to = square + offset;
        if (to < 0 || to >= 64) continue;

        int toFile = to % 8;
        if (abs(file - toFile) > 2) continue;

        if (board.squares[to] == EMPTY || isEnemyPiece(board.squares[to], isWhite))
        {
            moves.push_back({ square, to });
        }
    }
}

void generateKingMoves(Board& board, int square, std::vector<Move>& moves)
{
    static const std::vector<int> kingOffsets = { -8, 8, -1, 1, -9, 9, -7, 7 };

    bool isWhite = board.squares[square] == W_KING;
    int file = square % 8;

    for (int offset : kingOffsets)
    {
        int to = square + offset;
        if (to < 0 || to >= 64) continue;

        int toFile = to % 8;
        if (abs(file - toFile) > 1) continue;

        if (board.squares[to] == EMPTY || isEnemyPiece(board.squares[to], isWhite))
        {
            moves.push_back({ square, to });
        }
    }
}

void generateQueenMoves(Board& board, int square, std::vector<Move>& moves)
{
    static const std::vector<int> queenOffsets = { -8, 8, -1, 1, -9, 9, -7, 7 };
    generateSlidingMoves(board, square, moves, queenOffsets);
}

void generateRookMoves(Board& board, int square, std::vector<Move>& moves)
{
    static const std::vector<int> rookOffsets = { -8, 8, -1, 1 };
    generateSlidingMoves(board, square, moves, rookOffsets);
}

void generateBishopMoves(Board& board, int square, std::vector<Move>& moves)
{
    static const std::vector<int> bishopOffsets = { -9, 9, -7, 7 };
    generateSlidingMoves(board, square, moves, bishopOffsets);
}

void generateSlidingMoves(Board& board, int square, std::vector<Move>& moves, const std::vector<int>& offsets)
{
    bool isWhite = isWhitePiece(board.squares[square]);
    int file = square % 8;
    int rank = square / 8;

    for (int offset : offsets)
    {
        int i = 1;
        while (true)
        {
            int to = square + offset * i;
            if (to < 0 || to >= 64) break;

            int toFile = to % 8;
            int fileDelta = abs(file - toFile);
            if (fileDelta != i && fileDelta != 0) break;

            int toRank = to / 8;
            int rankDelta = abs(rank - toRank);
            if (rankDelta != i && rankDelta != 0) break;

            if (isFriendlyPiece(board.squares[to], isWhite)) break;

            moves.push_back({ square, to });

            if (board.squares[to] != EMPTY) break;
            i++;
        }
    }
}