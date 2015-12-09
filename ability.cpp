#include "ability.h"

Ability::Ability()          //default constructor simply sets default values
{
    name_ = "N/A";
    effect_ = Effect();
}

Ability::Ability(string ability_name){      //takes in a string, assigns it to "name", and fetches the appropriate effect
    name_ = ability_name;
    effect_ = Effect(name_);
}

bool Ability::operator<(const Ability& other) const{        //does nothing. needed so that the map doesn't yell at me
    return false;
}

string Ability::name() const
{
    return name_;
}

Effect Ability::effect() const
{
    return effect_;
}

