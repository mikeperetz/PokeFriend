#ifndef STATSPREAD_H
#define STATSPREAD_H


class StatSpread
{
public:
    StatSpread();

    bool operator<(const StatSpread& other) const;
};

#endif // STATSPREAD_H
