#ifndef ABILITY_H
#define ABILITY_H
#include "effect.h"
#include <cstdint>
#include <iostream>

using namespace std;
/**
 * @brief Each different ability is assigned an Ability object noting its "name" and its "effect". These ability objects are stored within the ability_library in the PokeLibrary class.
 * They are also used in the potential_abilities map in the Pokemon class.
 * TODO:
 *  1) Impelment the "effect" constructor properly, effectively storing the data of all of the abilities
 *  2) Add operators to treat each ability as if it were a string (for example: cout << (some ability object); would print out the name of the ability object)
 */


class Ability
{
public:
    Ability();                      //default constructor
    Ability(string ability_name);   //constructor takes in the name of the ability and initializes "name" and "effect" (via the effect constructor)



    bool operator<(const Ability& other) const;     //operator so that the map doesn't yell at me (doesn't do anything)




    string name() const;

    Effect effect() const;

private:
    string name_;                    //the name of the ability
    Effect effect_;                  //the effect of the ability
};

#endif // ABILITY_H
