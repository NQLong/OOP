#include "../../Header/Restaurant/Restaurant.h"

Restaurant::Restaurant() {
    this->set_list(&this->branches);
}
Restaurant::~Restaurant() {

}
Restaurant::Restaurant(string _name)
{
    this->name = _name;
    this->set_list(&this->branches);
}
Restaurant::Restaurant(string _name, list<Branch> branches)
{
    this->name = _name;
    this->branches = branches;
    this->set_list(&this->branches);
}

string Restaurant::get_name()
{
    return name;
}
void Restaurant::set_name(string name)
{
    this->name = name;
}

list<Branch> *Restaurant::get_branches()
{
    return &branches;
}
void Restaurant::set_branches(list<Branch> branches)
{
    this->branches = branches;
}