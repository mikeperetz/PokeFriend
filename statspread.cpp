#include "statspread.h"

StatSpread::StatSpread()
{

}

StatSpread::StatSpread(Nature nature, BaseStats base_spread, Stats ev_spread, Stats iv_spread)
{
    int level = 100;         //insert level constructor if you need to do lc or something stupid

    nature_ = nature;

    hp_ = ( ( (2 * base_spread.hp() + iv_spread.hp() + ( ev_spread.hp() / 4 ) ) * level) / 100 ) + level + 10;

    att_ = ( ( ( (2 * base_spread.att() + iv_spread.att() + ( ev_spread.att() / 4 ) ) * level) / 100 ) + 5 ) * nature.attMod();

    def_ = ( ( ( (2 * base_spread.def() + iv_spread.def() + ( ev_spread.def() / 4 ) ) * level) / 100 ) + 5 ) * nature.defMod();

    spatt_ = ( ( ( (2 * base_spread.spatt() + iv_spread.spatt() + ( ev_spread.spatt() / 4 ) ) * level) / 100 ) + 5 ) * nature.spattMod();

    spdef_ = ( ( ( (2 * base_spread.spdef() + iv_spread.spdef() + ( ev_spread.spdef() / 4 ) ) * level) / 100 ) + 5 ) * nature.spdefMod();

    speed_ = ( ( ( (2 * base_spread.speed() + iv_spread.speed() + ( ev_spread.speed() / 4 ) ) * level) / 100 ) + 5 ) * nature.speedMod();

}


bool StatSpread::operator<(const StatSpread& other) const{
    return false;
}

int StatSpread::hp() const
{
    return hp_;
}

int StatSpread::att() const
{
    return att_;
}

int StatSpread::def() const
{
    return def_;
}

int StatSpread::spdef() const
{
    return spdef_;
}

int StatSpread::speed() const
{
    return speed_;
}

Nature StatSpread::nature() const
{
    return nature_;
}


int StatSpread::spatt() const
{
    return spatt_;
}
