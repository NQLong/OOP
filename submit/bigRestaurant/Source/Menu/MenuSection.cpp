#include "../../Header/Menu/MenuSection.h"
string MenuSection::class_name = "menu section";

int MenuSection::new_id = 0;

MenuSection::MenuSection()
{
    this->menu_section_id = new_id++;
    // set_list(&this->menu_items);
}
MenuSection::~MenuSection() {}

MenuSection::MenuSection(string _title, string _description) : menu_section_id(new_id++), title(_title), description(_description)
{
    // set_list(&this->menu_items);
}
MenuSection::MenuSection(string _title, string _description, list<MenuItem> items) : menu_section_id(new_id++), title(_title), description(_description), menu_items(items)
{
    // set_list(&this->menu_items);
}

MenuItem *MenuSection::get_element(int id)
{
    return ListManager<MenuItem>(&menu_items).get_element(id);
}

bool MenuSection::add_element()
{
    return ListManager<MenuItem>(&menu_items).add_element(-1);
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
    MenuItem menu_item = MenuItem::input(-1);
    clear();
    if (add_menu_item(menu_item))
    {

        cout << "done";
        return true;
    }
    cout << "fail";
    return true;
}

ostream &operator<<(ostream &os, const list<MenuSection> &lst)
{
    char border = '#';
    char inside_h_border = '-';
    char inside_v_border = '|';
    int border_size = 109;
    os
        << setw(border_size) << setfill(border) << "" << endl
        << setfill(' ');
    for (auto it = lst.begin(); it != lst.end(); it++)
    {
        stringstream ss;
        ss << *it;
        int title_size = -1;
        int text_size = -1;
        for (int k = 0; k < 4; k++)
        {
            os << border;
            string line;
            getline(ss, line, ':');
            os << " " << line << inside_v_border;
            if (text_size == -1)
            {
                title_size = line.length() + 1;
                text_size = border_size - title_size - 3;
            }
            getline(ss, line);
            if (k != 3)
            {
                if (line.length() > text_size)
                {
                    int i = 0;
                    for (i = 0; i < line.length() - text_size; i += text_size)
                    {
                        string text = line.substr(i, text_size);
                        if (text[text_size - 1] == ' ')
                        {
                            text = text;
                        }
                        else
                        {
                            if (line[i + text_size] == ' ')
                                text = text;
                            else
                            {
                                if (text[text_size - 2] == ' ')
                                {
                                    text[text_size - 1] = ' ';
                                }
                                else
                                    text[text_size - 1] = '-';
                                i--;
                            }
                        }

                        os << setw(text_size) << left << text << border << endl;
                        os << border << setw(title_size) << "" << inside_v_border;
                    }
                    os << setw(text_size) << left << line.substr(i, text_size) << border << endl;
                }
                else
                    os << setw(text_size) << left << line << border << endl;

                os
                    << border << setw(border_size - 2) << setfill(inside_h_border) << ""
                    << setfill(' ') << border << endl;
            }
            else
            {
                while (!ss.eof())
                {
                    getline(ss, line);
                    os << line << border << endl;
                    if (!ss.eof())
                    {
                        os << border << setw(title_size) << "" << inside_v_border;
                    }
                }
            }
        }
        os
            << setw(border_size) << setfill(border) << "" << endl
            << setfill(' ');
    }
    return os;
}

bool MenuSection::remove_menu_item(MenuItem i)
{
    this->menu_items.remove(i);
    return true;
}

bool MenuSection::remove_menu_item()
{
    cout << "remove menu item: \n";
    MenuItem *ptr = pick_menu_item();
    if (ptr && remove_menu_item(*ptr))
    {
        clear();
        cout << "Done";
        return true;
    }
    clear();
    cout << "Fail";
    return false;
}

MenuItem *MenuSection::pick_menu_item()
{
    int id;
    cout << "item's id: " << endl;
    cin >> id;
    cin.ignore();
    return get_menu_item(id);
}

MenuItem *MenuSection::get_menu_item(int id)
{
    for (auto it = menu_items.begin(); it != menu_items.end(); it++)
        if (it->getMenu_item_id() == id)
            return &(*it);
    return NULL;
}
void MenuSection::menu_items_list()
{
    cout << menu_items;
}

bool MenuSection::select_menu_item()
{
    return true;
}

MenuSection MenuSection::input(int)
{
    MenuSection temp;
    cout << "section's name: ";
    getline(cin, temp.title);
    cout << "section's description: ";
    getline(cin, temp.description);
    clear();
    while (!select_statement("Add menu item", "Done"))
    {
        clear();
        temp.add_element();
        wait();
        clear();
    }
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

ostream &operator<<(ostream &os, const MenuSection &section)
{
    os
        << setw(25) << left << "Section's id"
        << ": " << section.menu_section_id << endl
        << setw(25) << left << "Section's title"
        << ": " << section.title << endl
        << setw(25) << left << "Section's description"
        << ": " << section.description << endl
        << setw(25) << left << "Section's items"
        << ": " << endl
        << section.menu_items;

    return os;
}

bool MenuSection::modify_menu_item()
{
    cout << "select menu item: \n";
    MenuItem *ptr = pick_menu_item();
    if (ptr)
    {
        clear();
        ptr->modify();
        return true;
    }
    clear();
    cout << "Invalid metu item id";
    return false;
    return true;
}

bool MenuSection::modify_menu_section()
{
    int option;
    bool loop = true;
    string temp;
    while (loop)
    {
        print_option({"modify title.",
                      "Modify description.",
                      "Add menu item.",
                      "Remove menu item.",
                      "Modify menu item.",
                      "Menu item list"

        });

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
            clear();
            this->add_menu_item();
            break;
        case 4:
            clear();
            remove_menu_item();
            break;
        case 5:
            clear();
            modify_menu_item();
            break;
        case 6:
            clear();

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

int MenuSection::get_id()
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
