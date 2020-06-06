#include <iostream>
#include "FootSoldier.hpp"
#include "Paramedic.hpp"
#include "ParamedicCommander.hpp"
#include "FootCommander.hpp"
#include "SniperCommander.hpp"
#include "Sniper.hpp"
#include "Soldier.hpp"
using namespace std;

    void Sniper::attack(vector<vector<Soldier*>> &board, pair<int,int> location){
int maxhel=0;
Soldier *attack_it;
 for(int i= 0; i< board.size(); ++i){
			for(int j=0; j< board[i].size(); ++j) {
				Soldier *soldi = board[i][j];


if (soldi != NULL &&soldi->Soldier::getSoldierId() != board[location.first][location.second]->Soldier::getSoldierId()&&maxhel<soldi->Soldier::getHealth())
	maxhel=soldi->Soldier::getHealth();
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
