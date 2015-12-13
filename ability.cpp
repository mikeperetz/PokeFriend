#include "ability.h"

Ability::Ability() : name_("N/A"), effect_(Effect())          //default constructor simply sets default values
{

}

Ability::Ability(string ability_name): name_(ability_name), effect_(Effect(name_)) {     //takes in a string, assigns it to "name", and fetches the appropriate effect

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

