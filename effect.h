#ifndef EFFECT_H
#define EFFECT_H
#include <cstdint>
#include <map>
#include <vector>
#include "ability.h"
#include "effect.h"
#include "item.h"
#include "move.h"
#include "stats.h"
#include "nature.h"
#include "basestats.h"
#include "status.h"
#include "statspread.h"
#include "type.h"

/**
 * @brief Each different effect is assigned an Effect object noting ___________. These effect objects are stored within the effect_library in the PokeLibrary class.
 * They are also used in the potential_effects map in the Pokemon class.
 * TODO:
 *  1) Determine structure and implementation of effect class
 *  2) Impelment the constructor properly, covering the work for lots of the other classes
 *  3) Add operators to treat each effect as if it were a string (for example: cout << (some effect object); would print out the name of the effect object)
 */


using namespace std;

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

double chance1, chance2;

double attmod, defmod, spamod, spdefmod, speedmod;

double healPercent;

bool cureSelf, cureTeam;

bool switchSelf, switchOpp;

int priority;

bool multiHit;

bool clearSide, clearBothSides;

int multiTurn;

//weather

double recoilPercent;

bool explode;

int trap;

int preventMove;

bool flinch;

bool confuse;

bool protect;

bool sub;

bool passSub;

bool knockOff;

bool tradeItem;




Status status_type;





};

#endif // EFFECT_H
