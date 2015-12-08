#ifndef TEAMPOKEMON_H
#define TEAMPOKEMON_H

#include "pokemon.h"


class TeamPokemon : public Pokemon
{
public:
    TeamPokemon();

private:

    //The revealed attributes of the pokemon (ie. that fall within the potential's probability threshold)
    vector<int> stats;
    string ability;
    string item;
    vector<string> moves;
    string type;

};

#endif // TEAMPOKEMON_H
