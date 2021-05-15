#include "../../Header/Menu/MenuItem.h"

MenuItem::MenuItem() {}
MenuItem::~MenuItem() {}

MenuItem MenuItem::input_menu_item()
{
    MenuItem temp;
    cout << "item's title: ";
    getline(cin, temp.title);
    cout << "item's description: ";
    getline(cin, temp.description);
    cout << "item's price: ";
    cin >> temp.price;
    cin.ignore();
    return temp;
}

ostream &operator<<(ostream &os, const MenuItem &item)
{
    os
        << "Item's id: " << item.menu_item_id << endl
        << "Item's title: " << item.title << endl
        << "Item's description: " << item.description << endl
        << "Item's price: " << item.price;
    return os;
}

int MenuItem::getMenu_item_id()
{
    return this->menu_item_id;
}

void MenuItem::setMenu_item_id(int menu_item_id)
{
    this->menu_item_id = menu_item_id;
}

string MenuItem::getTitle()
{
    return this->title;
}

void MenuItem::setTitle(string title)
{
    this->title = title;
}

string MenuItem::getDescription()
{
    return this->description;
}

void MenuItem::setDescription(string description)
{
    this->description = description;
}

double MenuItem::getPrice()
{
    return this->price;
}

void MenuItem::setPrice(double price)
{
    this->price = price;
}
