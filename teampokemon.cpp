#include "teampokemon.h"

TeamPokemon::TeamPokemon(Pokemon pokemon)
{
    /*if(pokemon.name_ == "Breloom"){
        moves.push_back();

    }
       */

}

TeamPokemon::TeamPokemon()
{

}

StatSpread TeamPokemon::stats()
{
    return stats_;
}

Ability TeamPokemon::ability() const
{
    return ability_;
}

Item TeamPokemon::item() const
{
    return item_;
}

vector<Move> TeamPokemon::moves() const
{
    return moves_;
}

Type TeamPokemon::type() const
{
    return type_;
}

int TeamPokemon::calcDamage(TeamPokemon defender, int move)
{

        Move currMove = this->moves()[move];
        int att_spatt, def_spdef;

        if (currMove.category() == "Physical"){
            def_spdef = defender.stats().def();
            att_spatt = this->stats().att();
        }
        else if (currMove.category() == "Special"){
            def_spdef = defender.stats().spdef();
            att_spatt = this->stats().spatt();
        }
        else
            att_spatt = 0;

        double modifier = 1.0;


        modifier *= currMove.type().calcMod(defender.type());

        if (this->item() == "Life Orb")
            modifier *= 1.3;
        if (this->item() == "Choice Band")
            modifier *= 1.5;
        if (this->item() == "Choice Specs")
            modifier *= 1.5;

        if (this->type() == currMove.type())
            modifier *= 1.5;

        int damage =
                ( .84 * (att_spatt/def_spdef) * currMove.damage() + 2 ) * modifier * .925;

        return damage;
}





