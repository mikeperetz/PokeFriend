#include "ability.h"

Ability::Ability()          //default constructor simply sets default values
{
    name = "N/A";
    effect = Effect();
}

Ability::Ability(string ability_name){      //takes in a string, assigns it to "name", and fetches the appropriate effect
    name = ability_name;
    effect = Effect(name);
}

bool Ability::operator<(const Ability& other) const{        //does nothing. needed so that the map doesn't yell at me
    return false;
}

string Ability::getName(){                  //retrieves "name"
    return name;
}


Effect Ability::getEffect(){                //retrieves "effect"
    return effect;
}
