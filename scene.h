#ifndef SCENE_H
#define SCENE_H

#include "teampokemon.h"
#include "team.h"

class Scene
{
public:
    Scene();

    TeamPokemon currMon, ocurrMon;
    Team player, opponent;
    bool isEnd, oisEnd;
    //Weather
    //Effects

    //updateScene(PlayTurn play);

    Scene potentialUpdate(int move, int side);
};

#endif // SCENE_H
