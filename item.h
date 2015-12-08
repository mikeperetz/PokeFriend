#ifndef ITEM_H
#define ITEM_H
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
    Item();         //default constructor

    bool operator<(const Item& other) const;        //overloaded < operator does nothing. map won't compile otherwise.

};

#endif // ITEM_H
