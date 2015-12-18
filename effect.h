#ifndef EFFECT_H
#define EFFECT_H
#include <cstdint>
#include <iostream>
#include "status.h"

using std::string;
using std::cout;
using std::endl;


/**
 * @brief Each different effect is assigned an Effect object noting ___________. These effect objects are stored within the effect_library in the PokeLibrary class.
 * They are also used in the potential_effects map in the Pokemon class.
 * TODO:
 *  1) Determine structure and implementation of effect class
 *  2) Impelment the constructor properly, covering the work for lots of the other classes
 *  3) Add operators to treat each effect as if it were a string (for example: cout << (some effect object); would print out the name of the effect object)
 */



/*

class BoostOpp {
public:
    BoostOpp(string description);

private:


};


class BoostSelf {
public:
    BoostSelf();
    void operator()(Move move);

private:
    double att_, def_, spa_, spdef_, speed;
    double chance_;

};

class StatusOpp {
public:

private:
};

class HealSelf {
public:

private:
};

class DrainOpp {
public:

private:
};
class ConstDamage {
public:

private:
};
class HighCrit {
public:

private:
};
class CureSelfStatus {
public:

private:
};
class CureTeamStatus {
public:

private:
};
class SwitchSelf {
public:

private:
};
class SwitchOpp {
public:

private:
};
class MultiHit {
public:

private:
};
class BatonPass {
public:

private:
};
class ClearHazard {
public:

private:
};
class MultiTurn {
public:

private:
};
class Weather {
public:

private:
};

class Recoil {
public:

private:
};
class Explode {
public:

private:
};
class Trap {
public:

private:
};
class PreventMove {
public:

private:
};
class Flinch {
public:

private:
};

class Confuse {
public:

private:
};
class Protect {
public:

private:
};
class Sub {
public:

private:
};
class PassSub {
public:

private:
};
class KnockOff {
public:

private:
};
class PriorityDiff {
public:

private:
};
class Screens {
public:

private:
};
class Trick {
public:

private:
};*/



class Effect {
public:

    Effect();
    Effect(string description);

//double chance2; implement later, maybe

double attmod, defmod, spamod, spdefmod, speedmod, accmod, evamod;

double oattmod, odefmod, ospamod, ospdefmod, ospeedmod, oaccmod, oevamod;

double healPercent;

double recoilPercent;

double chance1 = evamod = oevamod = attmod = defmod = spamod = spdefmod = speedmod = oattmod = odefmod = ospamod = ospdefmod = ospeedmod= accmod = oaccmod = healPercent = recoilPercent = 0;


int multiTurn;

int priority;

int trap;

int preventMove = multiTurn = priority = trap = 0;

bool explode;

bool cureSelf, cureTeam;

bool switchSelf, switchOpp;

bool multiHit;

bool clearSide, clearBothSides;

bool flinch;

bool confuse;

bool protect;

bool sub;

bool passSub;

bool knockOff;

bool player;

bool tradeItem = explode = cureSelf = cureTeam = switchOpp = switchSelf = multiHit = clearBothSides = clearSide = flinch
       = confuse = protect = sub = passSub = knockOff = player = false;



Status status;





};

#endif // EFFECT_H
