#ifndef NATURE_H
#define NATURE_H

#include <cstdint>
#include <iostream>
using std::string;




class Nature
{
public:
    Nature();
    Nature(string name);

    bool operator ==( const Nature& rhs);


    double attMod() const;

    double defMod() const;

    double spattMod() const;

    double spdefMod() const;

    double speedMod() const;

    string name() const;

private:

    double attMod_;
    double defMod_;
    double spattMod_;
    double spdefMod_;
    double speedMod_;
    string name_;




};

#endif // NATURE_H
