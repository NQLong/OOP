#include "../Header/Menu.h"

Menu::Menu() {}
Menu::~Menu() {}

bool add_menu_section(MenuSection);
bool add_menu_section();
void print();

Menu Menu::inputMenu()
{
    Menu temp;
    cout << "Menu's title: ";
    getline(cin, temp.title);
    cout<<"Menu's description: ";
    getline(cin, temp.description);
    return temp;
}

MenuSection *getMenu_section(int id);
MenuSection *getMenu_section(string title);

int Menu::getMenu_id()
{
    return this->menu_id;
}

void Menu::setMenu_id(int menu_id)
{
    this->menu_id = menu_id;
}

string Menu::getTitle()
{
    return this->title;
}

void Menu::setTitle(string title)
{
    this->title = title;
}

string Menu::getDescription()
{
    return this->description;
}

void Menu::setDescription(string description)
{
    this->description = description;
}

list<MenuSection> *Menu::getMenu_sections()
{
    return &this->menu_sections;
}

void Menu::setMenu_sections(list<MenuSection> menu_sections)
{
    this->menu_sections = menu_sections;
}
