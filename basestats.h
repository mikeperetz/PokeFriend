#ifndef BASESTATS_H
#define BASESTATS_H

#include "effect.h"
#include <cstdint>
#include <iostream>
#include <vector>
#include "stats.h"

class BaseStats : public Stats
{
public:

    BaseStats();
    BaseStats(vector<int> stats);




//    int hp() const;

//    int att() const;

//    int def() const;

//    int spatt() const;

//    int spdef() const;

//    int speed() const;

   int bst() const;



   BaseStats(string stats);
private:
//    int hp_;
//    int att_;
//    int def_;
//    int spatt_;
//    int spdef_;
//    int speed_;
    int bst_;

\
};


#endif // BASESTATS_H
