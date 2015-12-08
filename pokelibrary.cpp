#include "pokelibrary.h"



PokeLibrary::PokeLibrary() //default construtor is the only constructor, and it constructs all of the sub-libraries
{
   make_pokemon_library();
//   make_move_library();
//   make_ability_library();
//   make_item_libarary();

}

void PokeLibrary::make_pokemon_library(){
    /* read a file with a list of all of the common pokemon, their abilities, movesets, */

/*segfaulting for some reason. I will have to check it out later. Or I can just not be a dick and call it at stupid times...
 *   if (!pokemon_library->empty())
 *       pokemon_library->clear();  */


    pokemon_library = new unordered_map<string, Pokemon>(); //lumps the pokemon_library hashtable onto the heap for consistent use
    pokemon_library->reserve(120);                          //hopefully saves some overhead by pre-sizing the table. Should probably store a variable instead, but meh.

    /* okay, so let's get something straight: I just refactored for a good while after deciding to make all of these things into objects instead of hellish maps.
     * I haven't really looked back at this file in the last 6 hours. I probably don't need any of these pairs. I don't really know what is going on here low-key.
     * I will try my best to annotate what I believe is staying for good <3
     *
     * We parse through the text file very deliberately. It is split up in a consistent pattern, so we are going to just brute force it <3 Can you think of a better way? I can't. */

    string name;                                           //the name of the pokemon !

    pair<vector<int>, double> stat_pair;                   //these are prolly unnecesary now
    pair<string,double> ability_pair;                      //+
    pair<string,double> item_pair;                         //+
    pair<string, double> move_pair;                        //+
    pair<string, double> type_pair;                        //+


    ifstream myfile ("C:\\Users\\mikeperetz2\\Documents\\Qt-Projects\\PokeFriend\\usagestats.txt"); //load in the file. Idk why it makes me put the whole address. I will have to check later. Double \\ to escape twice cuz syntax
    if (myfile.is_open()){
       //while ( !myfile.eof() ){                                              //temporarily commented out for debugging. Only cycles through one pokemon

          getline (myfile,name);                                               //first line is always the name. load it into "name", because we will modify that same pokemon until all of its maps are initialized
          pokemon_library->insert(pair<string, Pokemon>(name,Pokemon(name)));  //map the name to the pokemon object associated with that name
          string junk;                                                         //hold the "+" lines (see: .txt file), because i dont care to mess around with the semantics of streams rn :(
          getline (myfile, junk); getline(myfile,junk);                        //two of them seperate the name from the ability list

          while(myfile.peek() != '+'){                                         //don't know how many abilities there are, so we will continue iterating through the document 'til we hit another "+"
              string ability_probability;                                      //lines are in format   [name of pokemon ###%]. This will store the entire line to be broken up later
              getline (myfile, ability_probability);

              size_t i;                                                        //initializing i outside of the scope to use as a parameter in extracting the substring later

              for (i = 0; !(isdigit(ability_probability.at(i+1))); i++){       //continue until we hit the space preceding the usage percentage. We can't just iterate until we hit a space, because lots of abilities have spaces in them

                  if (i == ability_probability.length()-1){                    //alternatively, if we hit the end of the line without finding a digit, we screwed up, so we'll display an error message and terminate the program

                    cout << "Couldn't find probability associated with ability" << endl;
                    return;
                  }
              }


              string _ability = ability_probability.substr(0, i);                                        //Yay! We stored i, so now we can extract that substring up to the space preceding the percent to get the name
              double _probability = stod(ability_probability.substr(i+1, ability_probability.length())); //We also need to extract the probability. We extract the substring, then use stod (string to double) to convert it to a real number!



              Ability ability_obj(_ability);                                                             //construct an ability object using the ability name

              (*pokemon_library)[name].addAbility(ability_obj, _probability);                            //I believe that we still need to map the ability to the probability, because probability is dependent on ability AND pokemon. I guess you could get fancy with keys, but having them seperated (hopefully) comes with some useful functionality later


          }// end of ability line parsing

          /* Yay! It worked, miraculously. No number of compiler errors and type mismatches and oob errors can keep me down (maybe)
           * Now we have to continue this trend for the other libraries. Same general idea, slightly different patterns. I'm having
           * fun (kind of). This whole initializtion, class/structure definition, etc. is taking legitimately 60-70 hours. Sadly,
           * it isn't the glamorous, shiny part (which lol I hope I get to soon, else this is nothing) */



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



