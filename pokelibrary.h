#ifndef POKELIBRARY_H
#define POKELIBRARY_H
#include <cstdint>
#include <unordered_map>
#include <fstream>
#include <iostream>
#include <memory>
#include "pokemon.h"
#include "move.h"
#include "ability.h"
#include "item.h"

/**
 * @brief The PokeLibrary class is the backbone of the entire structure (shit, didn't even get to the logic yet.... how tedious). It contains libraries to store pokemon, moves, abilities, items, teams(?), and effects(?).
 * Lots of the information is scattered amongst .txt documents that I could scramble up. At the start of the program, this class initializes all of the libraries and structures, for the most part.
 * It does so primarily by parsing through the .txt documents (lord knows how I got that to work...) and extracting current simulator (Pokemon Showdown!) statistics.
 * TODO:
 *  1) Finish the parsing algorithm, and initialize the relevent libraries.
 *  2) Figure out what else I have to do.
 */

using namespace std;

//the library will be populated with the common pokemon for that tier.
//if you come across an unknown pokemon, it will add it to the map

class PokeLibrary {

public:

    PokeLibrary(); //instantiate the maps (data_library, abilities, items, effects, status).

    /* probably some getters here to extract data (lol they aren't gonna know about the ratchet, grueling tedium that goes on under the hood) */





private:

    /* these are all hash-maps. their size cancels out the initial overhead of a hash-map vs a dictionary.
     * The sizes of them happen to be about constant as well, meaning that resizing+rehashing is not an issue!
     * I hope that I don't realize that this is stupid... 30 hours later. Idk, when in doubt, more hash-maps.
     * Pretty much the only use for these will be to access data, so it would be stupid to use an ordered dictionary,
     * especially when there is no worthwhile (as in, worth the effort) ordering, and the runtime wouldn't compare
     * to a hash-map regardless */

    unordered_map<string, Pokemon> * pokemon_library; //maps the name of a pokemon to its Pokemon object
    unordered_map<string, Move> * move_library;  //maps the name of a move to its Move object
    unordered_map<string, Item> * item_library; //maps the name of an item to its Item object
    unordered_map<string, Ability> * ability_library; //maps the name of an ability to its Ability object

    /* these are the constructors for each library. The are private because they are called only by the default constructor (and that constructor is called only once at the beginning of the program).
     * The pokemon library is probably the largest. The pokemon objects themselves utilize most of the other libraries, probably, and there are lots of pokemon. That one is initialized via .txt file.
     * The others may be viable enought to input manually (lol as if I realistically have a choice */

    void make_pokemon_library();
    void make_move_library();
    void make_ability_library();
    void make_item_libarary();




};

#endif // POKELIBRARY_H
