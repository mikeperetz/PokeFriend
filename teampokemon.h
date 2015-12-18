#ifndef TEAMPOKEMON_H
#define TEAMPOKEMON_H

#include "pokemon.h"
#include <unordered_map>


class TeamPokemon : public Pokemon
{
public:
    TeamPokemon();




    StatSpread stats();

    Ability ability() const;

    Item item() const;

    vector<Move> moves() const;

    Type type() const;

    StatSpread stats_;

    Status status;

    int calcDamage(TeamPokemon defender, int move);

    TeamPokemon(Pokemon pokemon);
private:

    //The revealed attributes of the pokemon (ie. that fall within the potential's probability threshold)

    Ability ability_;
    Item item_;
    vector<Move> moves_;
    Type type_;



};

#endif // TEAMPOKEMON_H
