#pragma once
/**
 * This is a game that demonstrates how to use the Board class.
 * You can modify it and build your own games.
 * 
 * @author Oz Levi 
 * @author Erel Segal-Halevi
 * @since  2020-05
 */
#include <iostream>
#include "Board.hpp"
using namespace std;
namespace WarGame {
	class DemoGame {
	 private:
		Board board;
	 public:

 		/**
		 * The constructor initilizes the board and places the soldiers.
		 */
		DemoGame();
		
		/**
		 * This function runs a sample play of the game and returns the winner (1 or 2, or 0 in case of tie).
		 */
		uint play() {
			std::cout<< "player 1 turn: moving soldier "<<endl;
			board.move(1, {0,1}, Board::MoveDIR::Up);      // FootSoldier of player 1 moves forward and attacks.
			if (!board.has_soldiers(2)) return 1;

			std::cout<< "player 2 turn: moving soldier "<<endl;
			board.move(2, {7,1}, Board::MoveDIR::Down);    // FootSoldier of player 2 moves forward and attacks.
			if (!board.has_soldiers(1)) return 2;

			std::cout<< "player 1 turn: moving commander"<<endl;
			board.move(1, {0,3}, Board::MoveDIR::Up);      // FootCommander of player 1 moves forward, and all soldiers of player 1 attack.
			if (!board.has_soldiers(2)) return 1;

			std::cout<< "player 2 turn: moving commander "<<endl;
			board.move(2, {7,3}, Board::MoveDIR::Left);    // FootCommander of player 2 moves left, and all soldiers of player 2 attack.
			if (!board.has_soldiers(1)) return 2;

			/// Write more moves here..

			// If no player won, return "tie":
			return 0;
		}
~DemoGame() {
			
		 }
	};
}
