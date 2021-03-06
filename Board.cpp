

#include "Board.hpp"

namespace WarGame
{
    bool Board::has_soldiers(uint pn) const
    {
        for(int i= 0; i< board.size(); ++i){
			for(int j=0; j< board[i].size(); ++j) {
				Soldier* soldi = (*this)[{i, j}];
				if (soldi != NULL && soldi->getSoldierId() == pn)
					return true;
			}
		}
		return false;


    }

    Soldier*& Board::operator[](std::pair<int,int> location)
    {
        return board[location.first][location.second];

    }

    Soldier* Board::operator[](std::pair<int,int> location) const
    {
        return board[location.first][location.second];

    }

    void Board::move(uint pn, std::pair<int,int> source, MoveDIR direction)
    {
	     if(source.first<0 || source.first>=board.size()|| source.second<0 || source.second>=board[source.first].size()) {
        throw invalid_argument("Action is forbidden,out of Board");
    }
        	Soldier* soldi = (*this)[source];
		if(soldi==nullptr || soldi->getSoldierId() != pn)throw invalid_argument("invalid argument");
		pair<int, int> dest;
	
		switch (direction)
		{
		case Up:
			dest= make_pair(source.first+1, source.second);
			break;
		case Down:
			dest= make_pair(source.first-1, source.second);
			break;
		case Left:
			dest= make_pair(source.first, source.second-1);
			break;
		case Right:
			dest= make_pair(source.first, source.second+1);
			break;
		}
	if(dest.first<0 || dest.first>=board.size()|| dest.second<0 || dest.second>=board[dest.first].size()) 
			throw invalid_argument("Outside of the board");
	    if (soldi==nullptr||soldi->getSoldierId()!=pn||(*this)[dest]!=nullptr){
		    throw invalid_argument("cant do");}
		(*this)[source] = nullptr;	
		if((*this)[dest] != nullptr) throw runtime_error("stepping on other soldier!\n");
		
		(*this)[dest] = soldi;
		(*this)[source] = nullptr;
		soldi->attack(board, dest);
    }


}



