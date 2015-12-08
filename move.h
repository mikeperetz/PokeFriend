#ifndef MOVE_H
#define MOVE_H

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

};

#endif // MOVE_H
