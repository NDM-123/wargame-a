#include <iostream>

#include "Paramedic.hpp"
using namespace std;

	


    void Paramedic::attack(vector<vector<Soldier*>> &board, pair<int,int> location){

double dist=0;
 for(int i= 0; i< board.size(); ++i){
			for(int j=0; j< board[i].size(); ++j) {
				Soldier* soldi = board[i][j];
			dist=distance( i,j,location.first,location.second);	
if (soldi != NULL &&soldi->Soldier::getSoldierId() == board[location.first][location.second]->Soldier::getSoldierId()&&dist==1)
soldi->Soldier::setHealth(soldi->initial_health);
			}
		}

}

