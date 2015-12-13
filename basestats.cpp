#include "basestats.h"

BaseStats::BaseStats() : Stats(), bst_(0){

}

BaseStats::BaseStats(vector<int> stats) : Stats(stats)
{

    bst_ = hp_ + att_ + def_ + spatt_ + spdef_ + speed_;
}

BaseStats::BaseStats(string stats) : Stats(stats)
{

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



