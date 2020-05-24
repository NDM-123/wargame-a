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
    unsigned int soldierId;
    unsigned int initial_health;
    unsigned int damage;

    double distance(unsigned int x1, unsigned int y1, unsigned int x2, unsigned int y2){
        return sqrt(pow(x1 - x2,2) + pow(y1 - y2,2));}

public:
    Soldier(unsigned int sid, unsigned int h, int d) : soldierId(sid), initial_health(h), damage(d) { }
    virtual ~Soldier() {}

    virtual void attack (std::vector<std::vector<Soldier*>> &soldi, pair<int,int> location) = 0;
    unsigned int getSoldierId() ;
    unsigned int getHealth() ;
    void setHealth(unsigned int health) ;
    unsigned int getDamage() ;
};



#endif //WARGAME_A_MASTER_SOLDIER_HPP
