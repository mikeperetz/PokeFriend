#ifndef STATS_H
#define STATS_H


#include <cstdint>
#include <iostream>
#include <vector>

using std::string;
using std::vector;

class Stats
{
public:

    Stats();
    Stats(vector<int> stats);

    int hp() const;

    int att() const;

    int def() const;

    int spatt() const;

    int spdef() const;

    int speed() const;

    int curr_hp;




    Stats(string stat_string);


    void setHp(int hp);
protected:
    int hp_;
    int att_;
    int def_;
    int spatt_;
    int spdef_;
    int speed_;



};


#endif // STATS_H
