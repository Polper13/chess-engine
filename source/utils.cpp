#include "utils.h"

#include <iostream>

int perft(const Board& board, int depth)
{
    if (depth == 0) return 1;

    std::vector<Move> pseudo = generatePseudoLegalMoves(board);
    std::vector<Move> moves = generateLegalMoves(pseudo, board);
    int total = 0;

    for (Move move : moves)
    {
        auto copy = board;
        makeMove(copy, move);
        total += perft(copy, depth - 1);
    }
    return total;
}

void perftDivide(const Board& board, int depth)
{
    std::vector<Move> pseudo = generatePseudoLegalMoves(board);
    std::vector<Move> moves = generateLegalMoves(pseudo, board);
    int total = 0;

    for (Move move : moves)
    {
        Board copy = board;
        makeMove(copy, move);
        int count = perft(copy, depth - 1);
        total += count;

        move.printUCI();
        std::cout << ": " << count << std::endl;
    }

    std::cout << "\nNodes searched: " << total << std::endl;
}