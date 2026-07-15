#include <iostream>

#include "board.h"

void Board::init()
{
    // clear everything
    for (int i = 0; i < 64; i++) squares[i] = EMPTY;

    // white pieces (rank 1)
    squares[0] = W_ROOK; squares[1] = W_KNIGHT; squares[2] = W_BISHOP; squares[3] = W_QUEEN;
    squares[4] = W_KING; squares[5] = W_BISHOP; squares[6] = W_KNIGHT; squares[7] = W_ROOK;

    // white pawns (rank 2)
    for (int i = 8; i < 16; i++) squares[i] = W_PAWN;

    // black pawns (rank 7)
    for (int i = 48; i < 56; i++) squares[i] = B_PAWN;

    // black pieces (rank 8)
    squares[56] = B_ROOK;  squares[57] = B_KNIGHT; squares[58] = B_BISHOP; squares[59] = B_QUEEN;
    squares[60] = B_KING;  squares[61] = B_BISHOP; squares[62] = B_KNIGHT; squares[63] = B_ROOK;

    whiteToMove = true;
    castleWK = castleWQ = castleBK = castleBQ = true;
    enPassantSquare = -1;
}

void Board::print() const
{
    for (int rank = 7; rank >= 0; rank--)
    {
        for (int file = 0; file < 8; file++)
        {
            std::cout << pieceToChar(squares[rank * 8 + file]) << " ";
        }
        std::cout << "\n";
    }
}

char pieceToChar(int piece) 
{
    static const char chars[] = { '.', 'P','N','B','R','Q','K', 'p','n','b','r','q','k' };
    return chars[piece];
}