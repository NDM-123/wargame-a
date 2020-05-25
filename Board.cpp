//

// Created by Naor on 5/21/2020.

//

#include <iostream>

#include "Board.hpp"

#include "Soldier.hpp"

#include <cstdint>



using namespace std;



class Board {

private:

    std::vector<std::vector<Soldier*>> board;

public:

    enum MoveDIR { Up, Down, Right, Left };



    Board(unsigned int numRows, unsigned int numCols) :

            board(numRows, std::vector<Soldier*>(numCols, nullptr)) {}



    // operator for putting soldiers on the game-board during initialization.

    Soldier*& operator[](std::pair<int,int> location){

    return board[location.first][location.second];

    }



    // operator for reading which soldiers are on the game-board.

    Soldier* operator[](std::pair<int,int> location) const {

	return board[location.first][location.second];

    }



    // The function "move" tries to move the soldier of player "player"

    //     from the "source" location to the "target" location,

    //     and activates the special ability of the soldier.

    // If the move is illegal, it throws "std::invalid_argument".

    // Illegal moves include:

    //  * There is no soldier in the source location (i.e., the soldier pointer is null);

    //  * The soldier in the source location belongs to the other player.

    //  * There is already another soldier (of this or the other player) in the target location.

    // IMPLEMENTATION HINT: Do not write "if" conditions that depend on the type of soldier!

    // Your code should be generic. All handling of different types of soldiers

    //      must be handled by polymorphism.

    void move(unsigned int player_number, std::pair<int,int> source, MoveDIR direction) {



    	return;

    }



    // returns true iff the board contains one or more soldiers of the given player.

    bool has_soldiers(unsigned int player_number) const {



    	return false;

    }

};







