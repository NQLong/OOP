#include "../../Header/Menu/Menu.h"
list<Menu *> Menu::menus;

Menu::Menu() {}
Menu::~Menu() {}

ostream &operator<<(ostream &os, const Menu &menu)
{
    os
        << setw(20) << setfill('#') << ""
        << setw(30) << setfill('#') << "Menu" << endl
        << "Menu id: " << menu.menu_id << endl
        << "Title: " << menu.title << endl
        << "Description: " << menu.description << endl
        << endl;
    os << setw(20) << setfill('+') << ""
       << setw(30) << setfill('+') << "Menu's sections" << endl;

    for (auto it = menu.menu_sections.begin(); it != menu.menu_sections.end(); it++)
    {
        os << *it << endl
           << endl;
    }
    os
        << setw(60) << setfill('+') << "" << endl;
    os
        << setw(60) << setfill('#') << "";

    return os;
}

int Menu::sectionIdSeclection()
{
    int id;
    for (auto it = this->menu_sections.begin(); it != this->menu_sections.end(); it++)
    {
        cout << setw(3) << left << to_string(it->getMenu_section_id()) + "." << it->getTitle() << endl;
    }
    cout<<endl;
    cout<<"section's id: ";
    cin>>id;
    cin.ignore();
    return id;
}

void Menu::print(int menu_id)
{
}

bool Menu::modify_menu()
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
            << "Add menu section." << endl
            << setw(3) << left << to_string(count++) + "."
            << "Modify menu section." << endl
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
            this->add_menu_section();
            break;
        case 4:
            this->modify_menu_section();
            break;
        default:
            loop = false;
            break;
        }
    }

    return true;
}

bool Menu::add_menu_section(MenuSection menu_section)
{
    menu_sections.push_back(menu_section);
    return true;
}

bool Menu::add_menu_section()
{
    clear();
    cout << "add menu section:" << endl;
    MenuSection menu_section = MenuSection::input_menu_section();
    menu_section.setMenu_section_id(menu_sections.size() > 0 ? menu_sections.back().getMenu_section_id() + 1 : 0);

    return add_menu_section(menu_section);
}

bool Menu::modify_menu_section()
{
    clear();
    int id;
    cout << "Select section id:"<<endl;
    id = sectionIdSeclection();
    
    MenuSection *section = this->getMenu_section(id);
    if (!section)
    {
        cout << "Menu_section doesn't exist";
        wait();
    }
    return section->modify_menu_section();
}

Menu Menu::inputMenu()
{
    Menu temp;
    cout << "Menu's title: ";
    getline(cin, temp.title);
    cout << "Menu's description: ";
    getline(cin, temp.description);
    return temp;
}

MenuSection *Menu::getMenu_section(int id)
{
    for (auto it = this->menu_sections.begin(); it != this->menu_sections.cend(); it++)
        if (it->getMenu_section_id() == id)
            return &(*it);
    return NULL;
}

MenuSection *Menu::getMenu_section(string title)
{
    for (auto it = this->menu_sections.begin(); it != this->menu_sections.cend(); it++)
        if (it->getTitle() == title)
            return &(*it);
    return NULL;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int Menu::getBranch_id()
{
    return branch_id;
}

void Menu::setBranch_id(int branch_id)
{
    this->branch_id = branch_id;
}

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

void Menu::addMenu(Menu *menu)
{
    menu->menu_id = *(menus.end()) ? (*menus.end())->menu_id + 1 : 0;
    menus.push_back(menu);
}

Menu *Menu::getMenu(int id)
{
    for (auto it = menus.begin(); it != menus.cend(); it++)
        if ((*it)->getMenu_id() == id)
            return *it;
    return NULL;
}

list<Menu *> Menu::getMenus()
{
    return menus;
}
