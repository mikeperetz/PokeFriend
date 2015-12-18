#ifndef STATSPREAD_H
#define STATSPREAD_H
#include "effect.h"
#include "nature.h"
#include <cstdint>
#include <iostream>
#include <vector>
#include "stats.h"
#include "basestats.h"

class StatSpread
{
public:
    StatSpread();
    StatSpread(Nature nature, BaseStats base_spread, Stats ev_spread, Stats iv_spread);

    bool operator<(const StatSpread& other) const;



    int hp();

    int att() const;

    int def() const;

    int spatt() const;

    int spdef() const;

    int speed() const;

    Nature nature() const;

    bool operator==( const StatSpread& rhs);

    Stats ev() const;

    Stats iv() const;

    int curr_hp;

private:
    int hp_;
    int att_;
    int def_;
    int spatt_;
    int spdef_;
    int speed_;


    Nature nature_;
    BaseStats base_;
    Stats ev_;
    Stats iv_;

};

#endif // STATSPREAD_H
