#include "statspread.h"

StatSpread::StatSpread()
{

}

StatSpread::StatSpread(string _nature, vector<int> ev_spread){

    nature = _nature;
    nature_effect = Effect(nature);
    hp = ev_spread[0]; att = ev_spread[1]; def = ev_spread[2]; spatt = ev_spread[3]; spdef = ev_spread[4]; speed = ev_spread[5];      //initialize member variables. convert to stats instead of ev spread

}

bool StatSpread::operator<(const StatSpread& other) const{
    return false;
}
