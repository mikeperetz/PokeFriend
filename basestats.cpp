#include "basestats.h"

BaseStats::BaseStats() : Stats(){
//    hp_ = 0;
//    att_ = 0;
//    def_ = 0;
//    spatt_ = 0;
//    spdef_ = 0;
//    speed_ = 0;
    bst_ = 0;
}

BaseStats::BaseStats(vector<int> stats) : Stats(stats)
{
//    hp_ = stats[0];
//    att_ = stats[1];
//    def_ = stats[2];
//    spatt_ = stats[3];
//    spdef_ = stats[4];
//    speed_ = stats[5];
    bst_ = hp_ + att_ + def_ + spatt_ + spdef_ + speed_;

}

//int BaseStats::hp() const
//{
//    return hp_;
//}

//int BaseStats::att() const
//{
//    return att_;
//}

//int BaseStats::def() const
//{
//    return def_;
//}

//int BaseStats::spatt() const
//{
//    return spatt_;
//}

//int BaseStats::spdef() const
//{
//    return spdef_;
//}

//int BaseStats::speed() const
//{
//    return speed_;
//}

int BaseStats::bst() const
{
    return bst_;
}



