#include "status.h"

Status::Status()
{

}

string Status::name() const
{
    return name_;
}

Status::Status(std::string status_name, int count)
{
    name_ = status_name;
    count_ = count;
}
