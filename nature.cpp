#include "nature.h"

Nature::Nature()
{
    attMod_ = 1;
    defMod_ = 1;
    spattMod_ = 1;
    spdefMod_ = 1;
    speedMod_ = 1;

}

Nature::Nature(string name)
{
    attMod_ = 1;
    defMod_ = 1;
    spattMod_ = 1;
    spdefMod_ = 1;
    speedMod_ = 1;


    if (name == "Hardy") {}
    else if (name == "Lonely") {attMod_ = 1.1; defMod_ = .9; }
    else if (name =="Brave") {attMod_ = 1.1; speedMod_ = .9; }
    else if (name =="Adamant") {attMod_ = 1.1; spattMod_ = .9; }
    else if (name =="Naughty") {attMod_ = 1.1; spdefMod_ = .9; }
    else if (name =="Bold") {defMod_ = 1.1; attMod_ = .9; }
    else if (name =="Docile") {}
    else if (name =="Relaxed") {defMod_ = 1.1; speedMod_ = .9; }
    else if (name =="Impish") {defMod_ = 1.1; spattMod_ = .9; }
    else if (name =="Lax") {defMod_ = 1.1; spdefMod_ = .9; }
    else if (name == "Timid") {speedMod_ = 1.1; attMod_ = .9; }
    else if (name == "Hasty") {speedMod_ = 1.1; defMod_ = .9; }
    else if (name == "Serious") {}
    else if (name == "Jolly") {speedMod_ = 1.1; spattMod_ = .9; }
    else if (name == "Naive") {speedMod_ = 1.1; spdefMod_ = .9; }
    else if (name == "Modest") {spattMod_ = 1.1; attMod_ = .9; }
    else if (name == "Mild") {spattMod_ = 1.1; defMod_ = .9; }
    else if (name == "Quiet") {spattMod_ = 1.1; speedMod_ = .9; }
    else if (name == "Bashful") {}
    else if (name == "Rash") {spattMod_ = 1.1; spdefMod_ = .9; }
    else if (name == "Calm") {spdefMod_ = 1.1; attMod_ = .9; }
    else if (name == "Gentle") {spdefMod_ = 1.1; defMod_ = .9; }
    else if (name == "Sassy") {spdefMod_= 1.1; speedMod_ = .9; }
    else if (name == "Careful") {spdefMod_= 1.1; spattMod_ = .9; }
    else if (name == "Quirky") {}

}





double Nature::attMod() const
{
    return attMod_;
}

double Nature::defMod() const
{
    return defMod_;
}

double Nature::spattMod() const
{
    return spattMod_;
}

double Nature::spdefMod() const
{
    return spdefMod_;
}

double Nature::speedMod() const
{
    return speedMod_;
}







