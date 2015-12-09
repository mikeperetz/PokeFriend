#include "stats.h"

Stats::Stats(){
    hp_ = 0;
    att_ = 0;
    def_ = 0;
    spatt_ = 0;
    spdef_ = 0;
    speed_ = 0;

}

Stats::Stats(vector<int> stats)
{
    hp_ = stats[0];
    att_ = stats[1];
    def_ = stats[2];
    spatt_ = stats[3];
    spdef_ = stats[4];
    speed_ = stats[5];

}

int Stats::hp() const
{
    return hp_;
}

int Stats::att() const
{
    return att_;
}

int Stats::def() const
{
    return def_;
}

int Stats::spatt() const
{
    return spatt_;
}

int Stats::spdef() const
{
    return spdef_;
}

int Stats::speed() const
{
    return speed_;
}



