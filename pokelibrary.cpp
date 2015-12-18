#include "pokelibrary.h"

using std::ifstream;


PokeLibrary::PokeLibrary() //default construtor is the only constructor, and it constructs all of the sub-libraries
{
    make_base_stat_library();
    make_move_library();
    make_pokemon_library();


    //   make_item_libarary();

}


void PokeLibrary::make_base_stat_library(){

    string name_stats;                                           //the line (pokemon name and stats)

    ifstream myfile ("C:\\Users\\mikeperetz2\\Documents\\Qt-Projects\\PokeFriend\\stats.txt"); //load in the file. Idk why it makes me put the whole address. I will have to check later. Double \\ to escape twice cuz syntax
    if (myfile.is_open()){
        while ( !myfile.eof() ){

            getline (myfile,name_stats);                                               //load each line to process
            if (name_stats == "") break;
            size_t i;                                                        //initializing i outside of the scope to use as a parameter in extracting the substring later

            for (i = 0; (name_stats.at(i)!= ' '); i++){       //continue until we hit the space preceding the usage percentage. We can't just iterate until we hit a space, because lots of abilities have spaces in them

                if (i == name_stats.length()-1){                    //alternatively, if we hit the end of the line without finding a digit, we screwed up, so we'll display an error message and terminate the program

                    cout << "Couldn't find start of base stat list" << endl;
                    return;
                }
            }


            string pokemon_name = name_stats.substr(0, i);                                        //Yay! We stored i, so now we can extract that substring up to the space preceding the percent to get the name
            string base_stat_string = name_stats.substr(i+1, name_stats.length());               //We also need to extract the probability. We extract the substring, then use stod (string to double) to convert it to a real number!




            base_stat_library[pokemon_name] = BaseStats(base_stat_string);;



        }
        myfile.close();
    }

    else cout << "Unable to read stats.txt" << endl;
}


void PokeLibrary::make_move_library()
{
    move_library.reset(new unordered_map<string, Move>());



    ifstream myfile ("C:\\Users\\mikeperetz2\\Documents\\Qt-Projects\\PokeFriend\\movelist.txt"); //load in the file. Idk why it makes me put the whole address. I will have to check later. Double \\ to escape twice cuz syntax
    if (myfile.is_open()){
        while ( !myfile.eof() ){

            string all_move_data;
            getline (myfile,all_move_data);                                               //load each line to process
            if (all_move_data == "") break;

            int typeIndex = findTypeIndex(all_move_data);

            if (typeIndex == -1){
                cout << "Couldn't find move name" << endl;
                return;
            }

            string move_name = all_move_data.substr(0, typeIndex-1);                                        //Yay! We stored i, so now we can extract that substring up to the space preceding the percent to get the name
            string type_cat_dam_acc_pp_eff = all_move_data.substr(typeIndex, all_move_data.length());               //We also need to extract the probability. We extract the substring, then use stod (string to double) to convert it to a real number!


            int catIndex;
            for (catIndex = 0; (type_cat_dam_acc_pp_eff.at(catIndex)!= ' '); catIndex++){       //continue until we hit the space preceding the usage percentage. We can't just iterate until we hit a space, because lots of abilities have spaces in them

                if (catIndex == type_cat_dam_acc_pp_eff.length()-1){                    //alternatively, if we hit the end of the line without finding a digit, we screwed up, so we'll display an error message and terminate the program

                    cout << "Couldn't find move type" << endl;
                    return;
                }
            }

            string move_type = type_cat_dam_acc_pp_eff.substr(0, catIndex);                                        //Yay! We stored i, so now we can extract that substring up to the space preceding the percent to get the name
            string cat_dam_acc_pp_eff = type_cat_dam_acc_pp_eff.substr(catIndex+1, type_cat_dam_acc_pp_eff.length());


            int damIndex;
            for (damIndex = 0; (cat_dam_acc_pp_eff.at(damIndex)!= ' '); damIndex++){       //continue until we hit the space preceding the usage percentage. We can't just iterate until we hit a space, because lots of abilities have spaces in them

                if (damIndex == cat_dam_acc_pp_eff.length()-1){                    //alternatively, if we hit the end of the line without finding a digit, we screwed up, so we'll display an error message and terminate the program

                    cout << "Couldn't find damage" << endl;
                    return;
                }
            }

            string move_cat = cat_dam_acc_pp_eff.substr(0, damIndex);                                        //Yay! We stored i, so now we can extract that substring up to the space preceding the percent to get the name
            string dam_acc_pp_eff = cat_dam_acc_pp_eff.substr(damIndex+1, cat_dam_acc_pp_eff.length());


            int accIndex;
            for (accIndex = 0; (dam_acc_pp_eff.at(accIndex)!= ' '); accIndex++){       //continue until we hit the space preceding the usage percentage. We can't just iterate until we hit a space, because lots of abilities have spaces in them

                if (accIndex == dam_acc_pp_eff.length()-1){                    //alternatively, if we hit the end of the line without finding a digit, we screwed up, so we'll display an error message and terminate the program

                    cout << "Couldn't find damage" << endl;
                    return;
                }
            }

            string move_dam = dam_acc_pp_eff.substr(0, accIndex);                                        //Yay! We stored i, so now we can extract that substring up to the space preceding the percent to get the name
            if (move_dam == "-") move_dam = "0";
            string acc_pp_eff = dam_acc_pp_eff.substr(accIndex+1, dam_acc_pp_eff.length());


            int ppIndex;
            for (ppIndex = 0; (acc_pp_eff.at(ppIndex)!= ' '); ppIndex++){       //continue until we hit the space preceding the usage percentage. We can't just iterate until we hit a space, because lots of abilities have spaces in them

                if (ppIndex == acc_pp_eff.length()-1){                    //alternatively, if we hit the end of the line without finding a digit, we screwed up, so we'll display an error message and terminate the program

                    cout << "Couldn't find damage" << endl;
                    return;
                }
            }

            string move_acc = acc_pp_eff.substr(0, ppIndex);                                        //Yay! We stored i, so now we can extract that substring up to the space preceding the percent to get the name
            if (move_acc == "-") move_acc = "100";
            if (move_acc == "∞") move_acc = "-1";
            string pp_eff = acc_pp_eff.substr(ppIndex+1, acc_pp_eff.length());


            int effOrTMIndex;
            for (effOrTMIndex = 0; (pp_eff.at(effOrTMIndex)!= ' '); effOrTMIndex++){       //continue until we hit the space preceding the usage percentage. We can't just iterate until we hit a space, because lots of abilities have spaces in them

                if (effOrTMIndex == pp_eff.length()-1){                    //alternatively, if we hit the end of the line without finding a digit, we screwed up, so we'll display an error message and terminate the program

                    cout << "Couldn't find damage" << endl;
                    return;
                }
            }



            string move_pp = pp_eff.substr(0, effOrTMIndex);                                        //Yay! We stored i, so now we can extract that substring up to the space preceding the percent to get the name

            if (move_pp == "-") move_pp = "-1";
            string eff_or_tm = pp_eff.substr(effOrTMIndex+1, pp_eff.length());


            if ((eff_or_tm.at(0) == 'T' && eff_or_tm.at(1) == 'M' ) || (eff_or_tm.at(0) == 'H' && eff_or_tm.at(1) == 'M')){

                int effIndex;
                for (effIndex = 0; (eff_or_tm.at(effIndex)!= ' '); effIndex++){       //continue until we hit the space preceding the usage percentage. We can't just iterate until we hit a space, because lots of abilities have spaces in them

                    if (effIndex == eff_or_tm.length()-1){                    //alternatively, if we hit the end of the line without finding a digit, we screwed up, so we'll display an error message and terminate the program

                        cout << "Thought that the move was a TM; couldn't find TM#" << endl;
                        return;
                    }


                }


                eff_or_tm = eff_or_tm.substr(effIndex+1, eff_or_tm.length());

            }



            string move_eff = eff_or_tm;

            //cout << move_eff << endl;

            if (move_eff == " -" || move_eff== "-") move_eff = "";


            //move_name, move_type, move_cat, move_dam, move_acc, move_pp, move_eff, effChance


            //  cout << "(Debug) All extracted info: " << move_name << " " << move_type << " " << move_cat << " " << move_dam << " " << move_acc << " " << move_pp << " " << move_eff << " " << effChance << endl;

            (*move_library)[move_name] = Move(move_name, Type(move_type), move_cat, stoi(move_dam), stod(move_acc)/100, stoi(move_pp), Effect(move_eff));



        }
        myfile.close();
    }

    else cout << "Unable to read movelist.txt" << endl;
}



int PokeLibrary::findTypeIndex(string & move_data)
{
    int index = -1;

    if ( ( index = move_data.find("NORMAL") )  != -1)
        return index;
    if ( ( index = move_data.find("FIRE") )  != -1)
        return index;
    if ( ( index = move_data.find("FIGHTING") )  != -1)
        return index;
    if ( ( index = move_data.find("WATER") )  != -1)
        return index;
    if ( ( index = move_data.find("FLYING") )  != -1)
        return index;
    if ( ( index = move_data.find("GRASS") )  != -1)
        return index;
    if ( ( index = move_data.find("POISON") )  != -1)
        return index;
    if ( ( index = move_data.find("ELECTRIC") )  != -1)
        return index;
    if ( ( index = move_data.find("GROUND") )  != -1)
        return index;
    if ( ( index = move_data.find("PSYCHIC") )  != -1)
        return index;
    if ( ( index = move_data.find("ROCK") )  != -1)
        return index;
    if ( ( index = move_data.find("ICE") )  != -1)
        return index;
    if ( ( index = move_data.find("BUG") )  != -1)
        return index;
    if ( ( index = move_data.find("DRAGON") )  != -1)
        return index;
    if ( ( index = move_data.find("GHOST") )  != -1)
        return index;
    if ( ( index = move_data.find("DARK") )  != -1)
        return index;
    if ( ( index = move_data.find("STEEL") )  != -1)
        return index;
    if ( ( index = move_data.find("FAIRY") )  != -1)
        return index;
    if ( ( index = move_data.find("???") )  != -1)
        return index;

    return index;
}



void PokeLibrary::make_pokemon_library(){
    /* read a file with a list of all of the common pokemon, their abilities, movesets, */




    pokemon_library.reset(new unordered_map<string, Pokemon>());  //lumps the pokemon_library hashtable onto the heap for consistent use


    /* okay, so let's get something straight: I just refactored for a good while after deciding to make all of these things into objects instead of hellish maps.
     * I haven't really looked back at this file in the last 6 hours. I probably don't need any of these pairs. I don't really know what is going on here low-key.
     * I will try my best to annotate what I believe is staying for good <3
     *
     * We parse through the text file very deliberately. It is split up in a consistent pattern, so we are going to just brute force it <3 Can you think of a better way? I can't. */

    string name;                                           //the name of the pokemon !


    ifstream myfile ("C:\\Users\\mikeperetz2\\Documents\\Qt-Projects\\PokeFriend\\usagestats.txt"); //load in the file. Idk why it makes me put the whole address. I will have to check later. Double \\ to escape twice cuz syntax
    if (myfile.is_open()){
        while ( !myfile.eof() ){                                              //temporarily commented out for debugging. Only cycles through one pokemon

            getline (myfile,name);

            //first line is always the name. load it into "name", because we will modify that same pokemon until all of its maps are initialized
            pokemon_library->insert(pair<string, Pokemon>(name,Pokemon(name)));  //map the name to the pokemon object associated with that name
            string junk;                                                         //hold the "+" lines (see: .txt file), because i dont care to mess around with the semantics of streams rn :(
            getline (myfile, junk);

            getline(myfile,junk);                        //two of them seperate the name from the ability list

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


            }                                                                    // end of ability line parsing


            /* Yay! It worked, miraculously. No number of compiler errors and type mismatches and oob errors can keep me down (maybe)
           * Now we have to continue this trend for the other libraries. Same general idea, slightly different patterns. I'm having
           * fun (kind of). This whole initializtion, class/structure definition, etc. is taking legitimately 60-70 hours. Sadly,
           * it isn't the glamorous, shiny part (which lol I hope I get to soon, else this is nothing). This next segment isn't commented
           * because it is the same thing as the previous. get over it ~ */



            getline (myfile, junk); //one of them


            while(myfile.peek() != '+'){
                string item_probability;
                getline (myfile, item_probability); //retrieve the ability line

                size_t i;

                for (i = 0; !(isdigit(item_probability.at(i+1))); i++){
                    if (i == item_probability.length()-1){
                        cout << "Couldn't find probability associated with ability" << endl;
                        return;
                    }
                }

                string _item = item_probability.substr(0, i);
                double _probability = stod(item_probability.substr(i+1, item_probability.length()));

                Item item_obj(_item);
                (*pokemon_library)[name].addItem(item_obj, _probability);



            } // end of item line parsing


            getline (myfile, junk); //one of them


            //start the problematic statspread one

            while(myfile.peek() != 'O' && myfile.peek() != '+'){

                string statspread_probability;
                getline (myfile, statspread_probability); //retrieve the stat spread line

                size_t i;


                for (i = 0; statspread_probability.at(i) != ':'; i++){

                    if (i == statspread_probability.length()-1){

                        cout << "Couldn't locate nature associated with stat spread" << endl;
                        return;
                    }


                }



                string spread_nature = statspread_probability.substr(0, i);

                size_t j;
                for (j = i+1; statspread_probability.at(j) != ' '; j++){           //they are numbers, but we can parse via spaces for this one!!

                    if (j == statspread_probability.length()-1){
                        cout << "Couldn't find probability associated with stat spread" << endl;
                        return;
                    }
                }


                string _ev_spread = statspread_probability.substr(i+1, j);
                double _probability = stod(statspread_probability.substr(j+1, statspread_probability.length()));


                vector<int> ev_spread_vector;
                vector<int> iv_spread_vector;

                for (size_t k = 0; k < _ev_spread.length(); k ++){
                    string temp_stat = "";

                    while (k <_ev_spread.length() && _ev_spread.at(k) != '/'){
                        temp_stat += _ev_spread.at(k);
                        k++;
                    }

                    ev_spread_vector.push_back(stoi(temp_stat));
                }

                for (int i = 0; i < 6; i ++)
                    iv_spread_vector.push_back(31);



                StatSpread statspread_obj(Nature(spread_nature), base_stat_library[name], Stats(ev_spread_vector), Stats(iv_spread_vector)); //finish constructing later (baseStats is default)
                (*pokemon_library)[name].addStatSpread(statspread_obj, _probability);



            } // end of item line parsing

            if (myfile.peek() == 'O') getline(myfile, junk); //get rid of other stat spread... we dont need it
            getline(myfile, junk); //one +


            while(myfile.peek() != '+'){
                string move_probability;
                getline (myfile, move_probability); //retrieve the ability line

                size_t i;

                for (i = 0; !(isdigit(move_probability.at(i+1))); i++){
                    if (i == move_probability.length()-1){
                        cout << "Couldn't find probability associated with move" << endl;
                        return;
                    }
                }


                string move_name = move_probability.substr(0, i);
                double move_prob = stod(move_probability.substr(i+1, move_probability.length()));

                //   cout << (*pokemon_library)[name].potential_moves.size() << endl;


                (*pokemon_library)[name].addMove((*move_library)[move_name], move_prob);


              }

            /*now to discard the teammates section */
            getline(myfile, junk); //one +

            while(myfile.peek() != '+' && myfile.peek() != EOF)
                getline (myfile, junk);

            if (myfile.peek() == '+'){
                getline (myfile, junk);
                getline (myfile, junk);
                getline (myfile, junk);
            }





        } //end of iteration through entire file while loop

        cout << "Parse complete; closing file" << endl;

        myfile.close();

    }

    else cout << "Unable to open file" << endl;

}



