#ifndef NATURE_H
#define NATURE_H

#include <cstdint>
#include <iostream>

using namespace std;

class Nature
{
public:
    Nature();
    Nature(string name);


    double attMod() const;

    double defMod() const;

    double spattMod() const;

    double spdefMod() const;

    double speedMod() const;

private:

    double attMod_;
    double defMod_;
    double spattMod_;
    double spdefMod_;
    double speedMod_;




};

#endif // NATURE_H
