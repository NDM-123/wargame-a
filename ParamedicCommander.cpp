#include <iostream>

using namespace std;

#include "Board.hpp"
#include "Paramedic.hpp"
#include "ParamedicCommander.hpp"


	


    void ParamedicCommander::attack(vector<vector<Soldier*>> &board, pair<int,int> location){

double dist=0;
 for(int i= 0; i< board.size(); ++i){
			for(int j=0; j< board[i].size(); ++j) {
								Soldier* soldi = board[i][j];
			dist=distance( i,j,location.first,location.second);	
if (soldi != NULL &&soldi->Soldier::getSoldierId() == board[location.first][location.second]->Soldier::getSoldierId()&&dist==1)
soldi->Soldier::setHealth(soldi->initial_health);
			}
		}
/////wake up all paramedics
 for(int i= 0; i< board.size(); ++i){
			for(int j=0; j< board[i].size(); ++j) {
				Soldier* soldi = board[i][j];
Paramedic* pF;
ParamedicCommander* pFc;
if((soldi != NULL &&soldi->Soldier::getSoldierId() == this->soldierId) &&(pF ==dynamic_cast< Paramedic*>(soldi)||pFc==dynamic_cast<ParamedicCommander*>(soldi))){
pair<int,int> loc;
loc.first=i;
loc.second=j;
soldi->attack(board,  loc);
}
			}
		}
}


