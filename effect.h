#ifndef EFFECT_H
#define EFFECT_H
#include <cstdint>
#include <iostream>

/**
 * @brief Each different effect is assigned an Effect object noting ___________. These effect objects are stored within the effect_library in the PokeLibrary class.
 * They are also used in the potential_effects map in the Pokemon class.
 * TODO:
 *  1) Determine structure and implementation of effect class
 *  2) Impelment the constructor properly, covering the work for lots of the other classes
 *  3) Add operators to treat each effect as if it were a string (for example: cout << (some effect object); would print out the name of the effect object)
 */


using namespace std;


class Effect
{
public:
    Effect();
    Effect(string name);
};

#endif // EFFECT_H
