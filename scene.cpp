#include "scene.h"

Scene::Scene()
{
    currMon = TeamPokemon();
    ocurrMon = TeamPokemon();
    player = Team();
    opponent = Team();
    isEnd = false;
    oisEnd = false;
}

Scene Scene::potentialUpdate(int move, int side)
{
    if ( side == 1 ){

        int damage = currMon.calcDamage(ocurrMon, move);

        ocurrMon.stats_.curr_hp -= damage;

        if (ocurrMon.stats_.curr_hp<= 0)
            isEnd = true;

        if (currMon.item() == "Life Orb")
            currMon.stats_.curr_hp -= (currMon.stats().hp() * 0.1);

        if (currMon.stats_.curr_hp <= 0 && !isEnd)
            oisEnd = true;

        //leftiez later

    }

    else if ( side == -1 ){
        int damage = ocurrMon.calcDamage(currMon, move);

        currMon.stats_.curr_hp -= damage;

        if (currMon.stats_.curr_hp<= 0)
            oisEnd = true;

        if (ocurrMon.item() == "Life Orb")
            ocurrMon.stats_.curr_hp -= (ocurrMon.stats().hp() * 0.1);

        if (ocurrMon.stats_.curr_hp <= 0 && !oisEnd)
            isEnd = true;


    }
    else
        cout << "Invalid side: " << side << " (scene.cpp, potentialUpdate)" << endl;




    return (*this);

}

