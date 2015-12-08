#include "item.h"

Item::Item()
{
    name = "N/A";
    effect = Effect();
}

Item::Item(string item_name){
    name = item_name;
    effect = Effect(name);
}


bool Item::operator<(const Item& other) const{
    return false;
}


