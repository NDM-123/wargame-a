/**
 * This is a game that demonstrates how to use the Board class.
 * You can modify it and build your own games.
 * 
 * @author Oz Levi 
 * @author Erel Segal-Halevi
 * @since  2020-05
 */

#include "DemoGame.hpp"
#include "FootSoldier.hpp"
#include "FootCommander.hpp"
#include <iostream>
#include "Board.hpp"
#include <cassert>

namespace WarGame {

		DemoGame::DemoGame(): board (8, 8) {
			// Add soldiers for player 1:
			assert(!board.has_soldiers(1));
			board[{0,1}] = new FootSoldier(1);
			board[{0,3}] = new FootCommander(1);
			board[{0,5}] = new FootSoldier(1);
			//assert(board.has_soldiers(1));

			// Add soldiers for player 2:
			assert(!board.has_soldiers(2));
			board[{7,1}] = new FootSoldier(2);
			board[{7,3}] = new FootCommander(2);
			board[{7,5}] = new FootSoldier(2);
			//assert(board.has_soldiers(2));
			std::cout<< "1, 2 has soldiers"<<endl;
			// In your game, you can put more soldier types, such as the sniper and the paramedic types.
		}


}
