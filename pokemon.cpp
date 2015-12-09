#include "pokemon.h"

/*vector<int> potential_stats;
vector<string> potential_abilities;
vector<string> potential_items;
vector<vector<string>> potential_moves;
vector<string> potential_type; //for megas and zoroark
*/

Pokemon::Pokemon(){
    name_ =  "N/A";
    potential_statspreads = map<StatSpread, double>();
    potential_abilities = map<Ability,double>();
    potential_items = map<Item, double>();
    potential_moves = map<Move,double>();
    mega = false;
}

Pokemon::Pokemon(string pokemon_name){
   name_ = pokemon_name;
   potential_statspreads = map<StatSpread, double>();
   potential_abilities = map<Ability,double>();
   potential_items = map<Item, double>();
   potential_moves = map<Move,double>();
   mega = false;
}

void Pokemon::addAbility(Ability ability, double probability){
    potential_abilities[ability] = probability;
}

void Pokemon::addItem(Item item, double probability){
    potential_items[item] = probability;
}


void Pokemon::addStatSpread(StatSpread statspread, double probability){

    potential_statspreads[statspread] = probability;
}


vector<pair<Ability, double> > Pokemon::getAbilities(){
   vector<pair<Ability, double>> abilities;
   for (auto it = potential_abilities.begin(); it!=potential_abilities.end(); it++ )
       abilities.push_back(*it); //push back the ability/probability pair
   return abilities;
}
