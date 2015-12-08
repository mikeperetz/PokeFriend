#ifndef ABILITY_H
#define ABILITY_H
#include "effect.h"


class Ability
{
public:
    Ability();

private:
    string name;
    double probability;
    Effect effect;
};

#endif // ABILITY_H
