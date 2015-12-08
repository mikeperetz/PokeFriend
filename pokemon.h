#ifndef POKEMON_H
#define POKEMON_H
#include <cstdint>
#include <map>
#include <vector>

using namespace std;

class Pokemon {


public:

    Pokemon();

    Pokemon(string pokemon_name);

    void addAbilityPair(Ability ability);

    vector<pair<string, double>> getAbilities();





private:

    string name;

    //The potential attributes of the pokemon with probability values as the leading element.
    map<StatSpread> potential_stats; //map set name with the stat spread
    map<Ability> potential_abilities;
    map<Item> potential_items;
    map<Move> potential_moves; //map set name with the moves
    map<Type> potential_type; //for megas and zoroark

    bool mega;






};

#endif // POKEMON_H
