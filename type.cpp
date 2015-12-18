#include "type.h"


Type::Type()
{

}

Type::Type(string name_name)
{

}

string Type::name() const
{
    return name_;
}

double Type::calcMod(Type defending)
{
    if (name_ == "Normal"){
        if ( defending.name() == "Rock" || defending.name() == "Steel") return 0.5;
        if (defending.name() == "Ghost") return 0.0;
        else return 1;
    }

    if (name_ == "Fire"){
        if (defending.name() == "Grass" || defending.name() == "Ice" || defending.name() =="Bug" || defending.name() == "Steel") return 2.0;
        if ( defending.name() == "Fire" || defending.name() == "Water" || defending.name() == "Rock" || defending.name() == "Dragon") return 0.5;
        else return 1;
    }

    if (name_ == "Water"){
        if (defending.name() == "Fire" || defending.name() == "Ground" || defending.name() =="Rock") return 2.0;
        if ( defending.name() == "Water" || defending.name() == "Grass" || defending.name() == "Dragon") return 0.5;
        else return 1;
    }
    if (name_ == "Electric"){
        if (defending.name() == "Water" || defending.name() == "Flying") return 2.0;
        if ( defending.name() == "Electric" || defending.name() == "Grass" || defending.name() == "Dragon") return 0.5;
        if (defending.name() == "Ground") return 0;
        else return 1;
    }
    if (name_ == "Grass"){
        if (defending.name() == "Water" || defending.name() == "Ground" || defending.name() =="Rock") return 2.0;
        if ( defending.name() == "Fire" || defending.name() == "Grass" || defending.name() == "Posion" || defending.name() == "Flying" || defending.name() == "Bug" || defending.name() == "Dragon") return 0.5;
        else return 1;
    }
    if (name_ == "Ice"){
        if (defending.name() == "Grass" || defending.name() == "Ground" || defending.name() =="Flying" || defending.name() == "Dragon") return 2.0;
        if ( defending.name() == "Fire" || defending.name() == "Water" || defending.name() == "Ice" || defending.name() == "Steel") return 0.5;
        else return 1;
    }
    if (name_ == "Fighting"){
        if (defending.name() == "Normal" || defending.name() == "Ice" || defending.name() =="Rock" || defending.name() == "Steel" || defending.name() == "Dark") return 2.0;
        if ( defending.name() == "Poison" || defending.name() == "Bug" || defending.name() == "Flying" || defending.name() == "Fairy" || defending.name() == "Psychic") return 0.5;
        if (defending.name() == "Ghost") return 0;
        else return 1;
    }
    if (name_ == "Poison"){
        if (defending.name() == "Grass" || defending.name() == "Fairy") return 2.0;
        if ( defending.name() == "Poison" || defending.name() == "Ground" || defending.name() == "Rock" || defending.name() == "Ghost") return 0.5;
        if (defending.name() == "Steel") return 0;
        else return 1;
    }
    if (name_ == "Ground"){
        if (defending.name() == "Fire" || defending.name() == "Electric" || defending.name() =="Poison" || defending.name() == "Steel") return 2.0;
        if ( defending.name() == "Grass" || defending.name() == "Bug") return 0.5;
        if (defending.name() == "Flying") return 0;
        else return 1;
    }
    if (name_ == "Flying"){
        if (defending.name() == "Grass" || defending.name() == "Fighting" || defending.name() =="Bug") return 2.0;
        if ( defending.name() == "Electric" || defending.name() == "Steel" || defending.name() == "Rock") return 0.5;
        else return 1;
    }
    if (name_ == "Psychic"){
        if (defending.name() == "Fighting" || defending.name() == "Electric") return 2.0;
        if ( defending.name() == "Psychic" || defending.name() == "Steel") return 0.5;
        if (defending.name() == "Dark") return 0;
        else return 1;
    }
    if (name_ == "Bug"){
        if (defending.name() == "Grass" || defending.name() == "Psychic" || defending.name() =="Dark") return 2.0;
        if ( defending.name() == "Fire" || defending.name() == "Steel" || defending.name() == "Rock" || defending.name() == "Fighting" || defending.name() == "Poison" || defending.name() == "Fairy" || defending.name() == "Flying") return 0.5;
        else return 1;
    }
    if (name_ == "Rock"){
        if (defending.name() == "Fire" || defending.name() == "Flying" || defending.name() =="Bug" || defending.name() == "Ice") return 2.0;
        if ( defending.name() == "Fighting" || defending.name() == "Steel" || defending.name() == "Ground") return 0.5;
        else return 1;
    }
    if (name_ == "Ghost"){
        if (defending.name() == "Psychic" || defending.name() == "Ghost") return 2.0;
        if ( defending.name() == "Dark") return 0.5;
        if (defending.name() == "Normal") return 0;
        else return 1;
    }
    if (name_ == "Dragon"){
        if (defending.name() == "Dragon") return 2.0;
        if ( defending.name() == "Steel") return 0.5;
        if (defending.name() == "Fairy") return 0;
        else return 1;
    }
    if (name_ == "Dark"){
        if (defending.name() == "Psychic" || defending.name() == "Ghost") return 2.0;
        if ( defending.name() == "Fighting" || defending.name() == "Dark" || defending.name() == "Fairy") return 0.5;
        else return 1;
    }
    if (name_ == "Steel"){
        if (defending.name() == "Ice" || defending.name() == "Rock" || defending.name() =="Fairy") return 2.0;
        if ( defending.name() == "Fire" || defending.name() == "Water" || defending.name() == "Electric" || defending.name() == "Steel") return 0.5;
        else return 1;
    }
    if (name_ == "Fairy"){
        if (defending.name() == "Fighting" || defending.name() == "Dragon" || defending.name() =="Dark") return 2.0;
        if ( defending.name() == "Fire" || defending.name() == "Posion" || defending.name() == "Steel") return 0.5;
        else return 1;
    }
    if (name_ == "???"){
        return 1;
    }


    cout << "Invalid type; could not generate mod." << endl;
    return 1;


}

bool Type::operator==(const Type &other) const
{
    return this->name() == other.name();

}

bool Type::operator<(const Type &other) const
{
    return true;
}

