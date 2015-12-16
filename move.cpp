#include "move.h"

Move::Move(): name_("N/A"), type_(Type()), category_("N/A"), damage_(0), accuracy_(1.0), pp_(0), effect_(Effect()), priority_(0)
{

}

Move::Move(string move_name, Type move_type, string move_cat, int move_dam, double move_acc, int move_pp, Effect move_eff): name_(move_name), type_(move_type), category_(move_cat), damage_(move_dam), accuracy_(move_acc), pp_(0), effect_(move_eff), priority_(0)
{

}

bool Move::operator<(const Move& other) const{
    return false;
}

Effect Move::effect() const
{
    return effect_;
}

