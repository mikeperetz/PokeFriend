#include "move.h"

Move::Move()
{
    name_ = "N/A";
    type_ = Type();
    classification_ = "N/A";
    effect_ = Effect();
    priority_ = 0;
    accuracy_ = 100;
}

bool Move::operator<(const Move& other) const{
    return false;
}

