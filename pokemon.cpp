#include "pokemon.h"

/*vector<int> potential_stats;
vector<string> potential_abilities;
vector<string> potential_items;
vector<vector<string>> potential_moves;
vector<string> potential_type; //for megas and zoroark
*/

Pokemon::Pokemon(){
    name =  "N/A";
    potential_stats = map<vector<int>, double>();
    potential_abilities = map<string,double>();
    potential_items = map<string, double>();
    potential_moves = map<string,double>();
    mega = false;
}

Pokemon::Pokemon(string pokemon_name){
   name = pokemon_name;
   potential_stats = map<vector<int>, double>();
   potential_abilities = map<string,double>();
   potential_items = map<string, double>();
   potential_moves = map<string,double>();
   mega = false;
}

void Pokemon::addAbilityPair(Ability ability){
    potential_abilities.insert(ability);
}

vector<pair<string, double> > Pokemon::getAbilities(){
   vector<pair<string, double>> abilities;
   for (auto it = potential_abilities.begin(); it!=potential_abilities.end(); it++ )
       abilities.push_back(*it); //push back the ability/probability pair
   return abilities;
}
