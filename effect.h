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
    Effect(string name, double chance);

    int priority() const;

private:
    string type_;
    double chance_;

    int priority_;
    Status status_;

    double drain_;
    double statChange_;
    double critBoost_;
    double flinch_;
    double switch_;
    double multiHit_;
    double remove_item_;
    double use_item_;
    double trap_;
    double hazard_;
    double clearHazard_;
    double forceSwitch_;
    double recoil_;
    double multiTurn_;
    double speedInfluence_;
    double moveRestrict_;
    double changePP_;
    double changeHP_;
    double constant_;
    double useWeight_;
    double clearStatus_;










};

#endif // EFFECT_H
