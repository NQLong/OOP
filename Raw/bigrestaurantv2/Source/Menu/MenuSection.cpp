#include "../../Header/Menu/MenuSection.h"

MenuSection::MenuSection() {}
MenuSection::~MenuSection() {}

MenuSection MenuSection::input_menu_section()
{
    MenuSection temp;
    cout << "section's name: ";
    getline(cin, temp.title);
    cout << "section's description: ";
    getline(cin, temp.description);
    return temp;
}

int MenuSection::itemIdSelection()
{
    int id;
    for (auto it = this->menu_items.begin(); it != this->menu_items.end(); it++)
    {
        cout << setw(3) << left << to_string(it->getMenu_item_id()) + "." << it->getTitle() << endl;
    }
    cout << endl;
    cout << "item's id: " << endl;
    cin >> id;
    cin.ignore();
    return id;
}

MenuItem *MenuSection::getMenu_item(int id)
{
    for (auto it = menu_items.begin(); it != menu_items.end(); it++)
        if (it->getMenu_item_id() == id)
            return &(*it);
    return NULL;
}

ostream &operator<<(ostream &os, const MenuSection &section)
{
    os
        << "Section's id: " << section.menu_section_id << endl
        << "Section's title: " << section.title << endl
        << "Section's description: " << section.description << endl
        << endl
        << setw(25) << setfill('-') << "Section's items"
        << setw(25) << setfill('-') << "" << endl;
    for (auto it = section.menu_items.begin(); it != section.menu_items.end(); it++)
        os << *it << endl
           << endl;
    os
        << setw(50) << setfill('-') << "";
    return os;
}

bool MenuSection::add_menu_item(MenuItem item)
{
    menu_items.push_back(item);
    return true;
}

bool MenuSection::add_menu_item()
{
    clear();
    cout << "add menu item:" << endl;
    MenuItem menu_item = MenuItem::input_menu_item();
    menu_item.setMenu_item_id(menu_items.size() > 0 ? menu_items.back().getMenu_item_id() + 1 : 0);
    return add_menu_item(menu_item);
}

bool MenuSection::modify_menu_item()
{
    return true;
}

bool MenuSection::modify_menu_section()
{
    int option;
    bool loop = true;
    string temp;
    while (loop)
    {
        int count = 1;
        clear();

        cout
            << setw(3) << left << to_string(count++) + "."
            << "modify title." << endl
            << setw(3) << left << to_string(count++) + "."
            << "Modify description." << endl
            << setw(3) << left << to_string(count++) + "."
            << "Add menu item." << endl
            << setw(3) << left << to_string(count++) + "."
            << "Modify menu item." << endl
            << setw(3) << left << to_string(count++) + "."
            << setw(3) << left << "0."
            << "Back." << endl;

        cout << endl
             << "Enter your choice: ";
        cin >> option;
        cin.ignore();
        switch (option)
        {
        case 1:
            clear();
            cout << "new title: ";
            getline(cin, this->title);
            break;
        case 2:
            clear();
            cout << "new description: ";
            getline(cin, this->description);
            break;
        case 3:
            this->add_menu_item();
            break;
        case 4:
            this->modify_menu_item();
        default:
            loop = false;
            break;
        }
    }

    return true;
}

int MenuSection::getMenu_section_id()
{
    return this->menu_section_id;
}

void MenuSection::setMenu_section_id(int menu_section_id)
{
    this->menu_section_id = menu_section_id;
}

string MenuSection::getTitle()
{
    return this->title;
}

void MenuSection::setTitle(string title)
{
    this->title = title;
}

string MenuSection::getDescription()
{
    return this->description;
}

void MenuSection::setDescription(string description)
{
    this->description = description;
}

list<MenuItem> *MenuSection::getMenu_items()
{
    return &this->menu_items;
}

void MenuSection::setMenu_items(list<MenuItem> menu_items)
{
    this->menu_items = menu_items;
}
