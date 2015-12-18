#include "stats.h"

Stats::Stats() : hp_(0), att_(0), def_(0), spatt_(0), spdef_(0), speed_(0)  {

}

Stats::Stats(vector<int> stats) : hp_(stats[0]), att_(stats[1]), def_(stats[2]), spatt_(stats[3]), spdef_(stats[4]), speed_(stats[5])
{

}

Stats::Stats(string stat_string)
{


    vector<int> stat_vector;

    size_t i = 0;
    for (size_t j = 0; j < stat_string.length(); j ++){
        if (j == stat_string.length()-1 || stat_string.at(j+1) == ' '){
            stat_vector.push_back(stoi(stat_string.substr(i, j+1)));
            j ++;
            i = j+1;
        }
    }

    hp_ = stat_vector[0];
    att_ = stat_vector[1];
    def_ = stat_vector[2];
    spatt_ = stat_vector[3];
    spdef_ = stat_vector[4];
    speed_ = stat_vector[5];

}

void Stats::setHp(int hp)
{
    hp_ = hp;
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



