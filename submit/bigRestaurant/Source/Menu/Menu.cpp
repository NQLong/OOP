#include "../../Header/Menu/Menu.h"
string Menu::class_name = "Menu";
int Menu::new_id = 0;

Menu::Menu() : menu_id(new_id++)
{
    // this->set_list(&menu_sections);
}

Menu::~Menu()
{
}

Menu::Menu(string _title, string _description, int branch)
    : menu_id(new_id++), title(_title), description(_description), branch_id(branch)
{
    // this->set_list(&menu_sections);
}

Menu::Menu(string _title, string _description, list<MenuSection> lst, int branch)
    : menu_id(new_id++), title(_title), description(_description), branch_id(branch)
{
    this->menu_sections = lst;
    // this->set_list(&menu_sections);
}

ostream &operator<<(ostream &os, const Menu &menu)
{
    os
        << setw(25) << left << "menu's id"
        << ": " << menu.menu_id << endl
        << setw(25) << left << "Branch's id"
        << ": " << menu.branch_id << endl
        << setw(25) << left << "menu's title"
        << ": " << menu.title << endl
        << setw(25) << left << "menu's description"
        << ": " << menu.description << endl
        << setw(25) << left << "menu's sections"
        << ": " << endl
        << menu.menu_sections;

    return os;
}
ostream &operator<<(ostream &os, const list<Menu> &lst)
{
    char border = '#';
    char inside_h_border = '-';
    char inside_v_border = '|';
    int border_size = 115;
    os
        << setw(border_size) << setfill(border) << ""
        << setfill(' ') << endl;
    os
        << border << setw(15) << left << "menu id"
        << inside_v_border << setw(15) << left << "branch id"
        << inside_v_border << setw(40) << left << "menu title"
        << inside_v_border << setw(40) << left << "menu description" << border << endl
        << setw(border_size) << setfill(border) << ""
        << setfill(' ');
    for (auto it = lst.begin(); it != lst.end(); it++)
    {
        os
            << endl
            << border << setw(15) << left << it->menu_id
            << inside_v_border << setw(15) << left << it->branch_id
            << inside_v_border << setw(40) << left << it->title
            << inside_v_border << setw(40) << left << it->description << border << endl
            << border << setw(border_size - 2) << setfill(inside_h_border) << "" << border
            << setfill(' ');
        ;
    }
    os
        << endl
        << setw(border_size) << setfill(border) << ""
        << setfill(' ') << endl;
    return os;
}

int Menu::section_id_seclection()
{
    int id;
    for (auto it = this->menu_sections.begin(); it != this->menu_sections.end(); it++)
    {
        cout << setw(3) << left << to_string(it->getMenu_section_id()) + "." << it->getTitle() << endl;
    }
    cout << endl;
    cout << "section's id: ";
    cin >> id;
    cin.ignore();
    return id;
}

void Menu::modify()
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
            this->add_element();
            break;
        case 4:
            // this->modify_menu_section();
            break;
        default:
            loop = false;
            break;
        }
    }

    return;
}

Menu Menu::input(int)
{
    Menu temp;
    cout << "Menu's title: ";
    getline(cin, temp.title);
    cout << "Menu's description: ";
    getline(cin, temp.description);
    clear();
    while (!select_statement("Add menu section", "Done"))
    {
        clear();
        temp.add_element();
        wait();
        clear();
    }
    return temp;
    return temp;
}

MenuSection* Menu::pick_element()
{
    return ListManager<MenuSection>(&menu_sections).pick_element();
}

bool Menu::add_element()
{
    return ListManager<MenuSection>(&menu_sections).add_element(-1);
}

MenuSection *Menu::get_element(int id)
{
    return ListManager<MenuSection>(&menu_sections).get_element(id);
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

int Menu::get_id()
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
