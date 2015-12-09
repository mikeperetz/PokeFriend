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
    StatSpread(string nature, BaseStats base_spread, Stats ev_spread, Stats iv_spread);

    bool operator<(const StatSpread& other) const;



    int hp() const;

    int att() const;

    int def() const;

    int spatt() const;

    int spdef() const;

    int speed() const;

    string nature() const;

    Effect nature_effect() const;

private:
    int hp_;
    int att_;
    int def_;
    int spatt_;
    int spdef_;
    int speed_;


    Stats iv_;
    Stats ev__;
    BaseStats base_;
    Nature nature_;
};

#endif // STATSPREAD_H
