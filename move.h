#ifndef MOVE_H
#define MOVE_H
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
#include "statspread.h"
#include "type.h"

/**
 * @brief Each different move is assigned a Move object noting its name, damage, type, physical/special/none, and effect. These move objects are stored within the move_library in the PokeLibrary class.
 * They are also used in the potential_moves map in the Pokemon class.
 * TODO:
 *  1) Determine structure and implementation of move class
 *  2) Impelment the constructor. Do we need a physical/special/none object? Nah, right? Maybe just a boolean or a string. Fuck secret sword and psyshock.
 *  3) Add operators to treat each move as if it were a string (for example: cout << (some move object); would print out the name of the move object)
 */
class Move
{
public:
    Move();                                         //default constructor, obviously. Has a lot of work to do (see: #1)
    bool operator<(const Move& other) const;        //overloaded < operator gets the compiler off my back (map class)
private:
    string name_;
    Type type_;
    string classification_;
    Effect effect_;
    int priority_;
    double accuracy_;


};

#endif // MOVE_H
