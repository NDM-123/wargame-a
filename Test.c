

#include "DemoGame.hpp"
#include "Board.hpp"

#include <cassert>

namespace WarGame {
/////////////////////////////////err  no place to move

		DemoGame::DemoGame(): board (3, 3) {
			// Add soldiers for player 1:
			assert(!board.has_soldiers(1));
			board[{0,1}] = new Sniper(1);
			board[{0,2}] = new SniperCommander(1);
			assert(board.has_soldiers(1));

			// Add soldiers for player 2:
			assert(!board.has_soldiers(2));
			board[{2,1}] = new Sniper(2);
			board[{2,2}] = new SniperCommander(2);
			assert(board.has_soldiers(2));


		}

		uint DemoGame::play() {
			board.move(1, {0,1}, Board::MoveDIR::Down);    
			if (!board.has_soldiers(2)) return 1;

			board.move(2, {2,1}, Board::MoveDIR::Up);    .
			if (!board.has_soldiers(1)) return 2;

	
		}

///////////////////////////////////////////err no source

	DemoGame::DemoGame(): board (3, 3) {
			// Add soldiers for player 1:
			assert(!board.has_soldiers(1));
			board[{0,1}] = new Sniper(1);
			board[{0,2}] = new SniperCommander(1);
			assert(board.has_soldiers(1));

			// Add soldiers for player 2:
			assert(!board.has_soldiers(2));
			board[{2,1}] = new Sniper(2);
			board[{2,2}] = new SniperCommander(2);
			assert(board.has_soldiers(2));


		}

		uint DemoGame::play() {
			board.move(1, {0,0}, Board::MoveDIR::Down);      

	
		}

////////////////////////err not yours


	DemoGame::DemoGame(): board (3, 3) {
			// Add soldiers for player 1:
			assert(!board.has_soldiers(1));
			board[{0,1}] = new Sniper(1);
			board[{0,2}] = new SniperCommander(1);
			assert(board.has_soldiers(1));

			// Add soldiers for player 2:
			assert(!board.has_soldiers(2));
			board[{2,1}] = new Sniper(2);
			board[{2,2}] = new SniperCommander(2);
			assert(board.has_soldiers(2));


		}

		uint DemoGame::play() {
			board.move(1, {2,1}, Board::MoveDIR::Up);    

	
		}
////////////chack only foot


		DemoGame::DemoGame(): board (3, 3) {
			// Add soldiers for player 1:
			assert(!board.has_soldiers(1));
			board[{0,0}] = new FootSoldier(1);
			board[{0,1}] = new FootCommander(1);
			board[{0,2}] = new FootSoldier(1);
			assert(board.has_soldiers(1));

			// Add soldiers for player 2:
			assert(!board.has_soldiers(2));
			board[{2,0}] = new FootSoldier(2);
			board[{2,1}] = new FootCommander(2);
			board[{2,2}] = new FootSoldier(2);
			assert(board.has_soldiers(2));


		}

		uint DemoGame::play() {
			board.move(1, {0,0}, Board::MoveDIR::Down);      
			if (!board.has_soldiers(2)) return 1;

			board.move(2, {2,1}, Board::MoveDIR::Up);    
			if (!board.has_soldiers(1)) return 2;

			assert(board[1,0]->health==90);
			assert(board[2,0]->health==90);
			assert(board[0,1]->health==130);
			return 0;
		}

////////////chack only sniper

	DemoGame::DemoGame(): board (3, 3) {
			// Add soldiers for player 1:
			assert(!board.has_soldiers(1));
			board[{0,1}] = new Sniper(1);
			board[{0,2}] = new SniperCommander(1);
			assert(board.has_soldiers(1));

			// Add soldiers for player 2:
			assert(!board.has_soldiers(2));
			board[{2,1}] = new Sniper(2);
			board[{2,2}] = new SniperCommander(2);
			assert(board.has_soldiers(2));


		}

		uint DemoGame::play() {
			board.move(1, {0,1}, Board::MoveDIR::Down);      
			if (!board.has_soldiers(2)) return 1;

			board.move(2, {2,1}, Board::MoveDIR::Left);    
			if (!board.has_soldiers(1)) return 2;

	board.move(1, {0,2}, Board::MoveDIR::Down);      .
			if (!board.has_soldiers(2)) return 1;

board.move(2, {2,2}, Board::MoveDIR::Left);    
			if (!board.has_soldiers(1)) return 2;
board.move(1, {1,2}, Board::MoveDIR::Down);      
			if (!board.has_soldiers(2)) return 1;
		}


////////////chack paramedic


		DemoGame::DemoGame(): board (3, 3) {
			// Add soldiers for player 1:
			assert(!board.has_soldiers(1));
			board[{0,0}] = new FootSoldier(1);
			board[{0,1}] = new FootCommander(1);
			board[{0,2}] = new Paramedic(1);
			assert(board.has_soldiers(1));

			// Add soldiers for player 2:
			assert(!board.has_soldiers(2));
			board[{2,0}] = new FootSoldier(2);
			board[{2,1}] = new FootCommander(2);
			board[{2,2}] = new Paramedic(2);
			assert(board.has_soldiers(2));


		}

		uint DemoGame::play() {
			board.move(1, {0,0}, Board::MoveDIR::Down);      
			if (!board.has_soldiers(2)) return 1;

			board.move(2, {2,1}, Board::MoveDIR::Up);    
			if (!board.has_soldiers(1)) return 2;

			board.move(1, {1,0}, Board::MoveDIR::Up);      
			if (!board.has_soldiers(2)) return 1;

			board.move(2, {2,2}, Board::MoveDIR::Left);    
			if (!board.has_soldiers(1)) return 2;

			assert(board[2,0]->health==100);
			
			return 0;
		}


////////////check paramcommender
		DemoGame::DemoGame(): board (3, 3) {
			// Add soldiers for player 1:
			assert(!board.has_soldiers(1));
			board[{0,0}] = new FootSoldier(1);
			board[{0,1}] = new ParamedicCommander(1);
			board[{0,2}] = new Paramedic(1);
			assert(board.has_soldiers(1));

			// Add soldiers for player 2:
			assert(!board.has_soldiers(2));
			board[{2,0}] = new FootSoldier(2);
			board[{2,1}] = new FootCommander(2);
			board[{2,2}] = new Paramedic(2);
			assert(board.has_soldiers(2));


		}

		uint DemoGame::play() {
			board.move(1, {0,0}, Board::MoveDIR::Down);      
			if (!board.has_soldiers(2)) return 1;

			board.move(2, {2,1}, Board::MoveDIR::Up);    
			if (!board.has_soldiers(1)) return 2;

			board.move(1, {1,0}, Board::MoveDIR::Up);      
			if (!board.has_soldiers(2)) return 1;

			board.move(2, {1,1}, Board::MoveDIR::Right);    
			if (!board.has_soldiers(1)) return 2;

			board.move(1, {0,1}, Board::MoveDIR::Down);      
			if (!board.has_soldiers(2)) return 1;

			board.move(1, {2,0}, Board::MoveDIR::Up);      
			if (!board.has_soldiers(2)) return 1;
			assert(board[0,2]->health==80);
			assert(board[0,0]->health==30);
			board.move(1, {1,1}, Board::MoveDIR::Up);      
			if (!board.has_soldiers(2)) return 1;

			assert(board[0,0]->health==100);
			assert(board[0,2]->health==100);
			return 0;
		}








}
