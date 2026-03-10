#include<iostream>
#include "board.hpp"

Board::Board()
{
    initialize();
}

void Board::initialize()
{
    for(auto &row : board)
    {
        for(auto &cell : row)
        {
            cell = {PieceType::None, Color::None};
        }
    }
}

char getPieceSymbol(const Piece& piece)
{
    if(piece.type == PieceType::Pawn)
        return piece.color == Color::White ? 'P' : 'p';

    if(piece.type == PieceType::Rook)
        return piece.color == Color::White ? 'R' : 'r';

    if(piece.type == PieceType::Knight)
        return piece.color == Color::White ? 'N' : 'n';

    if(piece.type == PieceType::Bishop)
        return piece.color == Color::White ? 'B' : 'b';

    if(piece.type == PieceType::Queen)
        return piece.color == Color::White ? 'Q' : 'q';

    if(piece.type == PieceType::King)
        return piece.color == Color::White ? 'K' : 'k';

    return '.';
}

void Board::print() const
{
    for(int row = 0; row < 8; row++)
    {
        std::cout << 8 - row << " ";

        for(int col = 0; col < 8; col++)
        {
            std::cout << getPieceSymbol(board[row][col]) << " ";
        }

        std::cout << std::endl;
    }

    std::cout << "  a b c d e f g h" << std::endl;
}