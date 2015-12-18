#include "item.h"

Item::Item() : name_("N/A"), effect_(Effect())
{

}

Item::Item(string item_name): name_(item_name), effect_(Effect(name_)){

}

bool Item::operator==(const string &item_name)
{
    return this->name() == item_name;
}


bool Item::operator<(const Item& other) const{
    return false;
}

string Item::name() const
{
    return name_;
}


