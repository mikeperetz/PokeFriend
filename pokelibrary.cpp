#include "pokelibrary.h"



PokeLibrary::PokeLibrary()
{
   make_pokemon_library();
//   make_move_library();
//   make_ability_library();
//   make_item_libarary();

}

void PokeLibrary::make_pokemon_library(){
    /* read a file with a list of all of the common pokemon, their abilities, movesets, */


//    if (!pokemon_library->empty())
//        pokemon_library->clear();

    pokemon_library = new unordered_map<string, Pokemon>();
    pokemon_library->reserve(120);

    string name;
    pair<vector<int>, double> stat_pair;
    pair<string,double> ability_pair;
    pair<string,double> item_pair;
    pair<string, double> move_pair;
    pair<string, double> type_pair;


    ifstream myfile ("C:\\Users\\mikeperetz2\\Documents\\Qt-Projects\\PokeFriend\\usagestats.txt");
    if (myfile.is_open()){
       //while ( !myfile.eof() ){

          getline (myfile,name); //first line is always the name

          pokemon_library->insert(pair<string, Pokemon>(name,Pokemon(name)));
          string junk; //hold the "+" lines
          getline (myfile, junk); getline(myfile,junk); //two of them

          while(myfile.peek() != '+'){
              string ability_probability;
              getline (myfile, ability_probability); //retrieve the ability line

              size_t i;

              for (i = 0; !(isdigit(ability_probability.at(i+1))); i++){
                  if (i == ability_probability.length()-1){
                    cout << "Couldn't find probability associated with ability" << endl;
                    return;
                  }
              }

              //cout << i << endl;
              string _ability = ability_probability.substr(0, i); //cout << _ability << endl;
              double _probability = stod(ability_probability.substr(i+1, ability_probability.length())); //cout << _probability << endl;

              ability_pair = pair<string, double>(_ability, _probability);

              (*pokemon_library)[name].addAbilityPair(ability_pair);


              cout << (*pokemon_library)["Garchomp"].getAbilities()[0].first << " " << (*pokemon_library)["Garchomp"].getAbilities()[0].second << endl;


          }// end of ability line parsing

          /*getline (myfile, junk); //one of them

          while(myfile.peek() != '+'){
              string ability_probability;
              getline (myfile, ability_probability); //retrieve the ability line

              size_t i;

              for (i = 0; !(isdigit(ability_probability.at(i+1))); i++){
                  if (i == ability_probability.length()-1){
                    cout << "Couldn't find probability associated with ability" << endl;
                    return;
                  }
              }

              //cout << i << endl;
              string _ability = ability_probability.substr(0, i); cout << _ability << endl;
              double _probability = stod(ability_probability.substr(i+1, ability_probability.length())); cout << _probability << endl;

              ability_pair = pair<string, double>(_ability, _probability);



          }// end of ability line parsing*/

     // } //end of iteration through entire file while loop

      myfile.close();

   }
   else cout << "Unable to open file" << endl;

}


//vector<int> PokeLibrary::get_damage_range(string attacker, string defender){
//    return vector<int>(); //change this!
//}

//Pokemon PokeLibrary::get_pokemon_data(string pokemon_name){
//    return Pokemon(); //change this!
//}

//Ability PokeLibrary::get_ability_data(string ability_name){
//    return Ability(); //change this!
//}

//Move PokeLibrary::get_move_data(string move_name){
//    return Move(); //change this!
//}

//Item PokeLibrary::get_item_data(string item_name){
//    return Item();
//}


