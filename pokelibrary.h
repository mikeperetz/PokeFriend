#ifndef POKELIBRARY_H
#define POKELIBRARY_H
#include <cstdint>
#include <unordered_map>
#include <fstream>
#include <iostream>
#include "pokemon.h"
#include "move.h"
#include "ability.h"
#include "item.h"

using namespace std;

//the library will be populated with the common pokemon for that tier.
//if you come across an unknown pokemon, it will add it to the map

class PokeLibrary {

public:

    PokeLibrary(); //instantiate the maps (data_library, abilities, items, effects, status).

    //vector<int> get_damage_range(string attacker, string defender); //return a damage calculation (vector of possible values, last element will be average damage) Param1: name of attacking pokemon, Param2: name of defending pokemon
    // void set_damage_range(string attacker, string defender); //store a damage calculation (vector) to data_library. Param1: name of attacking pokemon, Param2: name of defending pokemon

    //Pokemon get_pokemon_data(string pokemon_name); //retrieves the corresponding Pokemon object
    //maybe a setter?

    //Ability get_ability_data(string ability_name); //retrieves ability object

   // Move get_move_data(string move_name); //retrieve move object

   // Item get_item_data(string item_name); //retrieve item object






private:

    unordered_map<string, Pokemon> * pokemon_library; //our templatized map of pokemon_name -> data (T). T is another map (data_name -> some type of data).
    unordered_map<string, Move> * move_library;  //our templatized map of move_name -> data (T). T is another map (data_name -> some type of data).
    unordered_map<string, Item> * item_library; //our templatized map of item_name -> data (T). T is another map (data_name -> some type of data).
    unordered_map<string, Ability> * ability_library; //our templatized map of ability_name -> data (T). T is another map (data_name -> some type of data).

    void make_pokemon_library();
    void make_move_library();
    void make_ability_library();
    void make_item_libarary();

    //Pokemon one, two, three, four, five, six;   //six pokemon objects (your team)
    //Pokemon op_one, op_two, op_three, op_four, op_five, op_six; //six pokemon objects (opponent's team)



};

#endif // POKELIBRARY_H
