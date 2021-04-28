#include "../../Header/Restaurant/Branch.h"

bool Branch::modify_menu(){
    Menu *menu = this->getMenu();
    if (!menu){
        cout<<"menu doesn't exist";
        wait();
        return false;
    }
    return menu->modify_menu();
}

bool Branch::addMenu()
{
    
    if (this->menu_id!= -1 && getMenu())
        {
            cout<<"Branch already have menu";
            wait();
            return false;
        }
    Menu *menu = new Menu(Menu::inputMenu());
    menu->setBranch_id(this->branch_id);
    Menu::addMenu(menu);
    this->menu_id = menu->getMenu_id();
    cout<<"Success";
    wait();
    return true;
}

Branch Branch::inputBranch()
{
    string branch_name;

    system("clear");

    cout << "Branch name:";
    getline(cin, branch_name);

    cout << "Branch location" << endl;
    Address location = Address::inputAddress();

    cout << "Branch's kitchen" << endl;
    Kitchen kitchen = Kitchen::inputKitchen();
    return Branch(0, branch_name, location, kitchen);
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

int Branch::getMenu_id()
{
    return menu_id;
}

void Branch::setMenu_id(int menu_id)
{
    this->menu_id = menu_id;
}

Menu *Branch::getMenu()
{
    if (this->menu_id != -1)
        return Menu::getMenu(this->menu_id);
    return NULL;
}
