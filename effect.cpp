#include "effect.h"




Effect::Effect()
{

}

Effect::Effect(string description)
{



    if (description == "") return;

    if (description.find("lower") != string::npos && description.find("higher") == string::npos && description.find("slower") == string::npos && description.find("Slower") == string::npos){

        if ( description.substr(description.length() - 2, description.length()) == " -" ) chance1 = 1.0;

        else chance1 = (double)(stoi(description.substr(description.length() - 2, description.length())))/100.0;

        double mod;

        if (description.find("Sharply") != string::npos) mod = .5;
        else mod = .67;

        if (description.find("opponent") != string::npos) player = false;
        else player = true;


        if (description.find("Attack") != string::npos)
            player ? attmod = mod : oattmod = mod;

        else if (description.find("Defense") != string::npos)
            player ? defmod = mod : odefmod = mod;

        else if (description.find("Special Attack") != string::npos)
            player ? spamod = mod : ospamod = mod;

        else if (description.find("Special Defense") != string::npos)
            player ? spdefmod = mod : ospdefmod = mod;

        else  if (description.find("Speed") != string::npos)
            player ? speedmod = mod : ospeedmod = mod;
        else if (description.find("Accuracy") != string::npos)
            player ? accmod = mod : oaccmod = mod;
        else
            cout << "Failed to locate stat to lower." << endl;

    }

    if (description.find("raise") != string::npos && description.find("raised") == string::npos){
        if ( description.substr(description.length() - 2, description.length()) == " -" ) chance1 = 1.0;
        else chance1 = (double)(stoi(description.substr(description.length() - 2, description.length())))/100.0;

        double mod;

        if (description.find("Sharply") != string::npos) mod = 2.0;
        else if (description.find("Drastically") != string::npos) mod = 2.5;
        else if (description.find("maximum") != string::npos) mod = 4.0;
        else mod = 1.0;

        if (description.find("opponent") != string::npos) player = false;
        else player = true;


        if (description.find("Attack") != string::npos)
            player ? attmod = mod : oattmod = mod;

        else if (description.find("Defense") != string::npos)
            player ? defmod = mod : odefmod = mod;

        else if (description.find("Special Attack") != string::npos)
            player ? spamod = mod : ospamod = mod;

        else if (description.find("Special Defense") != string::npos)
            player ? spdefmod = mod : ospdefmod = mod;

        else  if (description.find("Speed") != string::npos)
            player ? speedmod = mod : ospeedmod = mod;

        else if (description.find("random") != string::npos)
            cout << "Accupressure not implemented." << endl;

        else if (description.find("Evasiveness") != string::npos)
            player ? evamod = mod : oevamod = mod;


        else if (description.find("all") != string::npos){
            player ? attmod = mod : oattmod = mod;
            player ? defmod = mod : odefmod = mod;
            player ? spamod = mod : ospamod = mod;
            player ? spdefmod = mod : ospdefmod = mod;
            player ? speedmod = mod : ospeedmod = mod;
        }


        else{
            cout << description << endl;
            cout << "Failed to locate stat to raise." << endl;
        }

    }

    else if (description.find("recovers") != string::npos){
        chance1 = 1.0;
        if (description.find("half") != string::npos)
            healPercent = .5;
        else if (description.find("most") != string::npos)
            healPercent = .75;
        else
            healPercent = .5; //not precise. somewhat accounts for synthesis/etc.
    }




}
