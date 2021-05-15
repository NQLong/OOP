#include "../../Header/Menu/MenuItem.h"

int MenuItem::new_id = 0;

string MenuItem::class_name= "Menu item";

MenuItem::MenuItem()
{
    this->menu_item_id = new_id++;
}
MenuItem::~MenuItem() {}

ostream &operator<<(ostream &os, const list<MenuItem> lst)
{
    char border = '#';
    char inside_h_border = '-';
    char inside_v_border = '|';
    int border_size = 80;
    os
        << setw(border_size) << setfill(border) << ""
        << setfill(' ');
    for (auto it = lst.begin(); it != lst.end(); it++)
    {
        os<< endl;
        stringstream ss;
        ss << *it;
        while (!ss.eof())
        {
            os << border;
            string line;
            getline(ss, line, ':');
            os << " " << line << inside_v_border;
            int title_size = line.length() + 1;
            int text_size = border_size - title_size - 3;
            getline(ss, line);
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
            if (!ss.eof())
            {
                os
                    << border << setw(border_size - 2) << setfill(inside_h_border) << ""
                    << setfill(' ') << border << endl;
            }
        }
        os
            << setw(border_size) << setfill(border) << "" 
            << setfill(' ');
    }
    return os;
}

MenuItem MenuItem::input(int)
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

void MenuItem::modify()
{
    int option;
    bool loop = true;
    while (loop)
    {
        print_option({
            "modify title",
            "modify description",
            "modify price",

        });

        cin >> option;
        cin.ignore();
        switch (option)
        {
        case 1:
            clear();
            cout << "item's title: ";
            getline(cin, this->title);
            wait();
            break;
        case 2:
            clear();
            cout << "item's description: ";
            getline(cin, this->description);
            wait();
            break;

        case 3:
            clear();
            cout << "item's price: ";
            cin >> this->price;
            cin.ignore();
            wait();
            break;

        default:
            loop = false;
            break;
        }
    }

    return;
}

ostream &operator<<(ostream &os, const MenuItem &item)
{
    os
        << setw(20) << left << "Item's id"
        << ": " << item.menu_item_id << endl
        << setw(20) << left << "Item's title"
        << ": " << item.title << endl
        << setw(20) << left << "Item's description"
        << ": " << item.description << endl
        << setw(20) << left << "Item's price"
        << ": "
        << item.price << " $";
    return os;
}

int MenuItem::getMenu_item_id()
{
    return this->menu_item_id;
}

int MenuItem::get_id()
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
