//
// Created by Ginton Durlacher on 24/05/2020.
//

#include "Board.hpp"

namespace WarGame
{
    bool Board::has_soldiers(uint pn) const
    {
        return false;


    }

    Soldier*& Board::operator[](std::pair<int,int> location)
    {
        return this->board[location.first][location.second];

    }

    Soldier* Board::operator[](std::pair<int,int> location) const
    {
        return this->board[location.first][location.second];

    }

    void Board::move(uint player_number, std::pair<int,int> source, MoveDIR direction)
    {
        return;
    }






}






