#include "mainwindow.h"
#include "pokelibrary.h"
#include <QApplication>
#include <memory>

int main(int argc, char *argv[])
{
    /*  QApplication a(argc, argv);
    MainWindow w;
    w.show();
*/


    /*map<Move, double> breloom_move = (*(*library).pokemon_library)["Breloom"].getPotential_moves();
    cout << breloom_move.size() << endl;
    for (auto it : breloom_move){
        cout << it.first.name() << endl;
    }*/

    /*Imagine some kind of "controller" class*/

    std::unique_ptr<PokeLibrary> library( new PokeLibrary);

    /* initialize the teams (with the GUI input)
     *
     * while not in endgame:
     *      create decision tree about the current scene
     *      run negamax !
     *      it will return the best move. manually perform it, then c+p result into program to parse
     *      lol that's all... make new trees
     *
     * No need to destruct because smart pointers <3
     *
     * What an anticlimactic finish to 100-something hours of work.
     */

    return 0;
}
