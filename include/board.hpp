#pragma once

#include <array>
#include "piece.hpp"

class Board
{
public:
    Board();

    void initialize();
    void print() const;

private:
    std::array<std::array<Piece,8>,8> board;
};