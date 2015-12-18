#ifndef TYPE_H
#define TYPE_H

#include <cstdint>
#include <iostream>


using std::cout;
using std::endl;

using std::string;


class Type
{
public:
    Type();
    Type(string type_name);


    string name() const;
    double calcMod(Type defending);


    bool operator==(const Type& other) const;
    bool operator<(const Type& other) const;


private:
    string name_;


};

#endif // TYPE_H
