#include "../../Header/Restaurant/Branch.h"

bool Branch::modify_menu()
{
    Menu *menu = this->get_menu();
    if (!menu)
    {
        cout << "menu doesn't exist";
        wait();
        return false;
    }
    menu->modify();
    return true;
}

Menu *Branch::get_menu()
{
    return ListManager<Menu>(Storage::menus).get_element(this->menu_id);
}

bool Branch::add_menu()
{
    if (this->menu_id != -1 && get_menu())
    {
        cout << "Branch already have menu";

        return false;
    }
    ListManager<Menu> menus_manager(Storage::menus);
    if (menus_manager.add_element(this->branch_id))
    {
        this->menu_id = menus_manager.get_last()->get_id();
        cout << "Success";
        return true;
    }
    cout << "Fail";
    return false;
}

Branch Branch::inputBranch()
{
    string branch_name;

    clear();

    cout << "Branch name:";
    getline(cin, branch_name);
    clear();
    cout << "Branch location" << endl;
    Address location = Address::inputAddress();
    clear();
    cout << "Branch's kitchen" << endl;
    Kitchen kitchen = Kitchen::inputKitchen();
    return Branch(branch_name, location, kitchen);
}

int Branch::getBranch_id()
{
    return this->branch_id;
}

int Branch::get_id()
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

int Branch::getMenu_id()
{
    return menu_id;
}

void Branch::setMenu_id(int menu_id)
{
    this->menu_id = menu_id;
}


int Branch::new_id = 0;
