#ifndef STATUS_H
#define STATUS_H


#include <cstdint>
#include <iostream>

using std::string;


class Status
{
public:
    Status();


    string name() const;

    Status(string status_name, int count);


private:

    string name_;
    int count_;
};

#endif // STATUS_H
