#include <iostream>

using namespace std;
#include "Board.hpp"
#include "FootSoldier.hpp"
#include "Paramedic.hpp"
#include "ParamedicCommander.hpp"
#include "FootCommander.hpp"
#include "SniperCommander.hpp"
#include "Sniper.hpp"
#include "Soldier.hpp"

    void FootSoldier::attack(vector<vector<Soldier*>> &board, pair<int,int> location){
double mindist=0;
Soldier *attack_it;
 for(int i= 0; i< board.size(); ++i){
			for(int j=0; j< board[i].size(); ++j) {
				Soldier *soldi = board[i][j];
			double dist=Soldier::distance( i,j,location.first,location.second);	
if (soldi != NULL &&soldi->Soldier::getSoldierId() != board[location.first][ location.second]->Soldier::getSoldierId()&&mindist>dist)
	mindist=dist;
attack_it=soldi;
			}
		}
if (FootCommander* pF=dynamic_cast<FootCommander*>(attack_it)){
attack_it->Soldier::setHealth(this->damage);
}
if (Sniper* pF=dynamic_cast<Sniper*>(attack_it)){
attack_it->Soldier::setHealth(this->damage);
}
if (SniperCommander* pF=dynamic_cast<SniperCommander*>(attack_it)){
attack_it->Soldier::setHealth(this->damage);
}
if (Paramedic* pF=dynamic_cast<Paramedic*>(attack_it)){
attack_it->Soldier::setHealth(this->damage);
}
if (ParamedicCommander* pF=dynamic_cast<ParamedicCommander*>(attack_it)){
attack_it->Soldier::setHealth(this->damage);
}
}


