//
// Created by Naor on 5/21/2020.
//

#ifndef WARGAME_A_MASTER_SOLDIER_HPP
#define WARGAME_A_MASTER_SOLDIER_HPP


#pragma once

#include <stdexcept>
#include <math.h>
#include <vector>

using namespace std;
class Soldier {

private:
    uint soldierId;
    uint initial_health;
    uint damage;

    double distance(uint x1, uint y1, uint x2, uint y2){
        return sqrt(pow(x1 - x2,2) + pow(y1 - y2,2));}

public:
    Soldier(uint sid, uint h, int d) : soldierId(sid), initial_health(h), damage(d) { }
    virtual ~Soldier() {}

    virtual void attack (std::vector<std::vector<Soldier*>> &soldi, pair<int,int> location) = 0;
    uint getSoldierId() ;
    uint getHealth() ;
    void setHealth(uint health) ;
    uint getDamage() ;
};



#endif //WARGAME_A_MASTER_SOLDIER_HPP
