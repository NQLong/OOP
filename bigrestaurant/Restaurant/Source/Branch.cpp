#include "../Header/Branch.h"

Branch Branch::inputBranch()
{
    string branch_name;
    
    system("clear");

    cout << "Branch name:";
    getline(cin, branch_name);

    cout << "Branch location" << endl;
    Address location = Address::inputAddress();

    cout << "Branch's kitchen"<<endl;
    Kitchen kitchen = Kitchen::inputKitchen();
    return Branch(0,branch_name,location,kitchen);
}

int Branch::getBranch_id()
{
    return this->branch_id;
}

void Branch::setBranch_id(int branch_id)
{
    this->branch_id = branch_id;
}

string Branch::getName()
{
    return this->name;
}

void Branch::setName(string name)
{
    this->name = name;
}

Address *Branch::getLocation()
{
    return &location;
}

void Branch::setLocation(Address location)
{
    this->location = location;
}

Kitchen *Branch::getKitchen()
{
    return &kitchen;
}

void Branch::setKitchen(Kitchen kitchen)
{
    this->kitchen = kitchen;
}

Menu *Branch::getMenu()
{
    return &menu;
}

void Branch::setMenu(Menu menu)
{
    this->menu = menu;
}