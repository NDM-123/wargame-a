#include "doctest.h"
#include <iostream>
#include <stdexcept>
#include "DemoGame.hpp"
#include "FootSoldier.hpp"
#include "FootCommander.hpp"
#include "Sniper.hpp"
#include "SniperCommander.hpp"
#include "Paramedic.hpp"
#include "ParamedicCommander.hpp"
#include <cassert>


TEST_CASE("FootSoldier against FootSoldier") {
int length=6;
int width=6;
    WarGame::Board board(length,width);
/////enter solder to player 1
    CHECK(!board.has_soldiers(1));
    board[{1,0}] = new FootSoldier(1);
    CHECK(board.has_soldiers(1));
/////enter solder to player 2
	    
    CHECK(!board.has_soldiers(2));
	board[{3,2}] = new FootSoldier(2);
    CHECK(board.has_soldiers(2));
//start game
    board.move(1,{1,1},WarGame::Board::MoveDIR::Right);
    CHECK(board.has_soldiers(1));
    CHECK(board.has_soldiers(2));

    CHECK_THROWS(board.move(1,{4,2},WarGame::Board::MoveDIR::Down));
    board.move(1,{1,1},WarGame::Board::MoveDIR::Up);
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));

    CHECK_THROWS(board.move(1,{6,1},WarGame::Board::MoveDIR::Up));
    CHECK_THROWS(board.move(2,{6,1},WarGame::Board::MoveDIR::Up));
    board.move(2,{7,1},WarGame::Board::MoveDIR::Down);
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));
    board.move(2,{6,1},WarGame::Board::MoveDIR::Down);
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));
    board.move(2,{5,1},WarGame::Board::MoveDIR::Down);
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));

    board.move(1,{2,1},WarGame::Board::MoveDIR::Up);
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));

    CHECK_THROWS(board.move(1,{3,1},WarGame::Board::MoveDIR::Up));
    CHECK_THROWS(board.move(2,{4,1},WarGame::Board::MoveDIR::Down));
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));

    board.move(1,{3,1},WarGame::Board::MoveDIR::Down);
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));
    board.move(2,{4,1},WarGame::Board::MoveDIR::Up);
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));
}


TEST_CASE("Sniper soldier VS Sniper soldier") {
int length=10;
int width=10;
    WarGame::Board board(length,width);
/////enter solder to player 1

    CHECK(!board.has_soldiers(1));
    board[{0,1}] = new Sniper(1);
    CHECK(board.has_soldiers(1));
/////enter solder to player 2

    CHECK(!board.has_soldiers(2));
	board[{7,1}] = new Sniper(2);
    CHECK(board.has_soldiers(2));
//start game

    board.move(1,{0,1},WarGame::Board::MoveDIR::Up);
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));
    CHECK_THROWS(board.move(1,{0,1},WarGame::Board::MoveDIR::Up));
    board.move(1,{1,1},WarGame::Board::MoveDIR::Up);
    CHECK(!board.has_soldiers(2));
    CHECK(board.has_soldiers(1));
}

TEST_CASE("Playing with all soldiers"){
int length=10;
int width=10;
    WarGame::Board board(length,width);
    CHECK(!board.has_soldiers(1));
    board[{0,0}] = new FootSoldier(1);
    board[{0,1}] = new FootCommander(1);
    board[{0,2}] = new Sniper(1);
    board[{0,3}] = new SniperCommander(1);
    board[{0,4}] = new Paramedic(1);
    board[{0,5}] = new ParamedicCommander(1);
    CHECK(board.has_soldiers(1));
    CHECK_THROWS((board[{8,8}] = new ParamedicCommander(1)));
    CHECK(!board.has_soldiers(2));
    board[{7,0}] = new FootSoldier(2);
    board[{7,1}] = new FootCommander(2);
    board[{7,2}] = new Sniper(2);
    board[{7,3}] = new SniperCommander(2);
    board[{7,4}] = new Paramedic(2);
    board[{7,5}] = new ParamedicCommander(2);

    CHECK(board.has_soldiers(2));
    board.move(1,{0,0},WarGame::Board::MoveDIR::Up);
    CHECK(board.has_soldiers(2));
    board.move(1,{0,1},WarGame::Board::MoveDIR::Up);
    CHECK(board.has_soldiers(2));
    board.move(1,{0,2},WarGame::Board::MoveDIR::Up);
    CHECK(board.has_soldiers(2));
    board.move(1,{0,3},WarGame::Board::MoveDIR::Up);
    CHECK(board.has_soldiers(2));
    board.move(1,{0,4},WarGame::Board::MoveDIR::Up);
    CHECK(board.has_soldiers(2));
    board.move(1,{0,5},WarGame::Board::MoveDIR::Up);
    CHECK(board.has_soldiers(2));

     board.move(2,{7,0},WarGame::Board::MoveDIR::Down);
    CHECK(board.has_soldiers(1));
    board.move(2,{7,1},WarGame::Board::MoveDIR::Down);
    CHECK(board.has_soldiers(1));
    board.move(2,{7,2},WarGame::Board::MoveDIR::Down);
    CHECK(board.has_soldiers(1));
    board.move(2,{7,3},WarGame::Board::MoveDIR::Down);
    CHECK(board.has_soldiers(1));
    board.move(2,{7,4},WarGame::Board::MoveDIR::Down);
    CHECK(board.has_soldiers(1));
    board.move(2,{7,5},WarGame::Board::MoveDIR::Down);
    CHECK(board.has_soldiers(1));
    //sniper 1 will kill them all
    board.move(1,{1,3},WarGame::Board::MoveDIR::Down);
    board.move(1,{0,3},WarGame::Board::MoveDIR::Up);
    board.move(1,{1,3},WarGame::Board::MoveDIR::Down);
    CHECK(board.has_soldiers(2));
    board.move(1,{0,3},WarGame::Board::MoveDIR::Up);
    board.move(1,{1,3},WarGame::Board::MoveDIR::Down);
    board.move(1,{0,3},WarGame::Board::MoveDIR::Up);
    //just to be Sure all is dead
    CHECK(!board.has_soldiers(2));
}

TEST_CASE("2 Soldiers VS 2 Soldiers"){
int length=10;
int width=10;
    WarGame::Board board(length,width);
	/////enter solder to player 1

    CHECK(!board.has_soldiers(1));
    board[{0,1}] = new FootSoldier(1);
    CHECK_THROWS((board[{0,1}] = new FootSoldier(1)));
    board[{0,0}] = new FootCommander(1);
    CHECK(board.has_soldiers(1));
/////enter solder to player 2

    CHECK(!board.has_soldiers(2));
    board[{7,0}] = new FootCommander(2);
	board[{7,1}] = new FootSoldier(2);

    CHECK(board.has_soldiers(2));
//start game
    board.move(1,{0,1},WarGame::Board::MoveDIR::Up);
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));
    CHECK_THROWS(board.move(1,{0,1},WarGame::Board::MoveDIR::Up));
    board.move(1,{1,1},WarGame::Board::MoveDIR::Up);
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));

    CHECK_THROWS(board.move(2,{7,0},WarGame::Board::MoveDIR::Left));
    board.move(2,{7,0},WarGame::Board::MoveDIR::Down);
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));

    board.move(1,{0,0},WarGame::Board::MoveDIR::Up);
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));

    board.move(1,{1,0},WarGame::Board::MoveDIR::Up);
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));
    board.move(1,{2,0},WarGame::Board::MoveDIR::Down);
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));

    board.move(1,{1,0},WarGame::Board::MoveDIR::Up);
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));
    board.move(1,{2,0},WarGame::Board::MoveDIR::Down);
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));

    board.move(1,{1,0},WarGame::Board::MoveDIR::Up);
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));
    board.move(1,{2,0},WarGame::Board::MoveDIR::Down);
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));

    board.move(1,{1,0},WarGame::Board::MoveDIR::Up);
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));
    board.move(1,{2,0},WarGame::Board::MoveDIR::Down);
    CHECK(!board.has_soldiers(2));
    CHECK(board.has_soldiers(1));
}

TEST_CASE("3 soldiers VS 3 soldiers") {
   int length=8;
int width=8;
    WarGame::Board board(length,width);
/////enter solder to player 1

    CHECK(!board.has_soldiers(1));
    board[{0,1}] = new FootSoldier(1);
    CHECK_THROWS((board[{0,1}] = new FootSoldier(1)));
    board[{0,0}] = new FootCommander(1);
    board[{0,2}] = new FootSoldier(1);
    CHECK(board.has_soldiers(1));
/////enter solder to player 2

    CHECK(!board.has_soldiers(2));
    board[{7,0}] = new FootCommander(2);
	board[{7,1}] = new FootSoldier(2);
    board[{7,2}] = new FootSoldier(2);

    CHECK(board.has_soldiers(2));
//start game
    board.move(1,{0,1},WarGame::Board::MoveDIR::Up);
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));
    CHECK_THROWS(board.move(1,{0,1},WarGame::Board::MoveDIR::Up));
    board.move(1,{1,1},WarGame::Board::MoveDIR::Up);
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));

    CHECK_THROWS(board.move(2,{7,0},WarGame::Board::MoveDIR::Left));
    board.move(2,{7,0},WarGame::Board::MoveDIR::Down);
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));

    board.move(1,{0,0},WarGame::Board::MoveDIR::Up);
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));
}
