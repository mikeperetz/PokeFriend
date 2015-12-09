#include "item.h"

Item::Item()
{
    name_ = "N/A";
    effect_ = Effect();
}

Item::Item(string item_name){
    name_ = item_name;
    effect_ = Effect(name_);
}


bool Item::operator<(const Item& other) const{
    return false;
}


