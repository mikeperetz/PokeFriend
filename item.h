#ifndef ITEM_H
#define ITEM_H

#include "effect.h"
#include <cstdint>
#include <iostream>



/**
 * @brief Each different item is assigned an Item object noting its "name" and its "effect". These item objects are stored within the item_library in the PokeLibrary class.
 * They are also used in the potential_items map in the Pokemon class.
 * TODO:
 *  1) Impelment the Item class
 *  2) Add operators to treat each item as if it were a string (for example: cout << (some item object); would print out the name of the item object)
 */

class Item
{
public:
    Item();                           //default constructor
    Item(string item_name);           //constructor takes in the name of the item and initializes "name" and "effect" (via the effect constructor)

    bool operator==(const string & item_name);
    bool operator<(const Item& other) const;        //overloaded < operator does nothing. map won't compile otherwise.

    string name() const;

private:
    string name_;
    Effect effect_;

};

#endif // ITEM_H
