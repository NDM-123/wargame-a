#pragma once
#include "Soldier.hpp"
class ParamedicCommander : public Soldier {

public:
    ParamedicCommander(int pn): Soldier(pn, 200, 100) {}

    void attack(vector<vector<Soldier*>> &b, pair<int,int> location);
};

