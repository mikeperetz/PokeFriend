#ifndef POKEMON_H
#define POKEMON_H
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

using namespace std;

/**
 * @brief Each different pokemon is assigned a Pokemon object. These pokemon objects are stored within the pokemon_library in the PokeLibrary class. This is some complicated shit. Just like how PokeLibrary
 * had 8 trillion different libraries, Pokemon has almost as many, but they are little baby ones (so I used normal maps teehee. would be gucci to sort all of them. If I have time, I'll see what i can do as
 * far as incorporating the individual pokemon's statistics into the ability, item, etc. stats. They are small maps, though, (like... 1-20 things), so it doesn't really matter.
 * TODO:
 *  1) Figure out what I have to do. Probably initialize some stuff. Or finish the other classes first maybe. I have no idea right now. I'm so sleepy.
 *  2) Pokemon cpp is uncommented because it is bed time
 */


class Pokemon {


public:

    Pokemon();      //obvious default constructor is obvious. Initializes the maps to nothing

    Pokemon(string pokemon_name);       //oooh lordy this one initializes "name" to the name. Also, now we get to dig around in our PokeLibraries for all of that other info !


    /* the add____ functions are used to populate the potential_____
     * member maps. Pokelibrary extracts the data from the .txt file and will individually call the adders with the correct parameters */

    void addAbility(Ability ability, double probability);

    void addItem(Item item, double probability);

    void addStatSpread(StatSpread statspread, double probability);

    vector<pair<Ability, double>> getAbilities();           //returns all of the abilities in case you are into that or something. man, these comments are getting shitty.





    void setBase_stats(const BaseStats &base_stats);

private:

    string name_;                                //the name of the pokemon, man
    BaseStats base_stats_;


    map<StatSpread, double> potential_statspreads;    //map of the common stat spreads to their probability
    map<Ability, double> potential_abilities;   //map of the common abilities to their probability
    map<Item, double> potential_items;          //map of the common items to their probability
    map<Move, double> potential_moves;          //map of the common moves to their probability (probably want to associate moveset logic at some point. Idk we will see!)
    map<Type, double> potential_type;           //map of the common types to their probability for megas and zoroark I guess.

    bool mega;                                  //maybe i should make this a pair? It will have the same probability as the megastone item. Idk. We will see!






};

#endif // POKEMON_H
