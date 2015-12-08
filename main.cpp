#include "mainwindow.h"
#include "pokelibrary.h"
#include <QApplication>
#include <memory>

int main(int argc, char *argv[])
{
   /* QApplication a(argc, argv);
    MainWindow w;
    w.show();
*/
    std::unique_ptr<PokeLibrary> library( new PokeLibrary);

    //library.make_pokemon_library();

    //return a.exec();


    return 0;
}
