#ifndef STATSPREAD_H
#define STATSPREAD_H
#include "effect.h"
#include <cstdint>
#include <iostream>
#include <vector>

class StatSpread
{
public:
    StatSpread();
    StatSpread(string _nature, vector<int> ev_spread);

    bool operator<(const StatSpread& other) const;


private:
    int hp;
    int att;
    int def;
    int spatt;
    int spdef;
    int speed;
    string nature;
    Effect nature_effect;
};

#endif // STATSPREAD_H
