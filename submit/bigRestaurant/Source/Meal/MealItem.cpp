#include "../../Header/Meal/MealItem.h"

MealItem::MealItem()
{
    this->meal_item_id = new_id++;
}
MealItem::~MealItem() {}
int MealItem::new_id = 0;
MenuItem *MealItem::get_menu_item()
{
    ListManager<Menu> menus_manager(Storage::menus);
    Menu *menu = menus_manager.get_element(this->menu_id);
    if (menu)
    {
        MenuSection *section = menu->get_element(this->menu_section_id);
        if (section)
        {
            MenuItem *item = section->get_element(this->menu_item_id);
            return item;
        }
    }
    return NULL;
}

double MealItem::getPrice()
{

    MenuItem *item = get_menu_item();
    if (item)
        return item->getPrice() * this->quantity;
    return 0;
}

ostream &operator<<(ostream &os, const MealItem &meal_item)
{
    MealItem temp = meal_item;
    MenuItem *item = temp.get_menu_item();
    os
        << setw(30) << left << "Meal item's id"
        << ": " << meal_item.meal_item_id << endl
        << setw(30) << left << "Item quantity"
        << ": " << meal_item.quantity << endl
        << setw(30) << left << "(menu_id,section_id,item_id)"
        << ": "
        << "(" << meal_item.menu_item_id << ","
        << meal_item.menu_section_id << ","
        << meal_item.menu_item_id << ")";
    if (item)
        os
            << endl
            << setw(20) << left << "Item's name"
            << ": " << item->getTitle() << endl
            << setw(20) << left << "Item's price"
            << ": "
            << item->getPrice() << " $";

    return os;
}

ostream &operator<<(ostream &os, const list<MealItem> &lst)
{
    char border = '#';
    char inside_h_border = '-';
    char inside_v_border = '|';
    int border_size = 120;
    os
        << setw(border_size) << setfill(border) << ""
        << setfill(' ') << endl;
    os
        << border << setw(5) << left << " id"
        << inside_v_border << setw(20) << left << "menu_id,section_id"
        << inside_v_border << setw(10) << left << "quantity"
        << inside_v_border << setw(30) << left << "        name"
        << inside_v_border << setw(10) << left << "unit $" << border << endl
        << border << setw(5) << left << " "
        << inside_v_border << setw(20) << left << "  item_id"
        << inside_v_border << setw(10) << left << ""
        << inside_v_border << setw(30) << left << ""
        << inside_v_border << setw(10) << left << "" << border << endl
        << setw(border_size) << setfill(border) << ""
        << setfill(' ');
    for (auto it = lst.begin(); it != lst.end(); it++)
    {
        os
            << endl
            << border << setw(5) << left << it->meal_item_id
            << inside_v_border << setw(20) << left << "(" + to_string(it->menu_item_id) + "," + to_string(it->menu_section_id) + "," + to_string(it->menu_item_id) + ")"
            << inside_v_border << setw(15) << left << it->quantity;
        MealItem temp = *it;
        MenuItem *item = temp.get_menu_item();
        if (item)
            os
                << inside_v_border << setw(30) << left << item->getTitle()
                << inside_v_border << setw(15) << left << item->getPrice() << border << endl
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

bool MealItem::pick_item(Menu *menu)
{

    MenuSection *ptr = menu->pick_element();
    if (!ptr)
    {
        clear();
        cout << "Invalid menu section id";
        return false;
    }
    MenuItem *item_ptr = ListManager<MenuItem>(ptr->getMenu_items()).pick_element();
    if (!item_ptr)
    {
        clear();
        cout << "Invalid menu item id";
        return false;
    }
    this->menu_section_id = ptr->get_id();
    this->menu_item_id = item_ptr->get_id();
    return true;
}

MealItem MealItem::input(int menu_id)
{
    ListManager<Menu> menus_manager(Storage::menus);
    Menu *menu = menus_manager.get_element(menu_id);
    MealItem temp;
    clear();
    temp.menu_id = menu->get_id();
    while (!temp.pick_item(menu))
    {
        cout << endl
             << endl;
        if (!select_statement("peak menu", "continue"))
        {
            clear();
            cout << *menu << endl
                 << endl;
        }
        else
            clear();
    }
    cout << "Item quantity: ";
    cin >> temp.quantity;
    cin.ignore();
    return temp;
}

//getter adnd setter

int MealItem::getMeal_item_id()
{
    return this->meal_item_id;
}

void MealItem::setMeal_item_id(int meal_item_id)
{
    this->meal_item_id = meal_item_id;
}

int MealItem::getQuantity()
{
    return this->quantity;
}

void MealItem::setQuantity(int quantity)
{
    this->quantity = quantity;
}

int MealItem::getMenu_id()
{
    return this->menu_id;
}

void MealItem::setMenu_id(int menu_id)
{
    this->menu_id = menu_id;
}

int MealItem::getMenu_section_id()
{
    return this->menu_section_id;
}

void MealItem::setMenu_section_id(int menu_section_id)
{
    this->menu_section_id = menu_section_id;
}

int MealItem::getMenu_item_id()
{
    return this->menu_item_id;
}

void MealItem::setMenu_item_id(int menu_item_id)
{
    this->menu_item_id = menu_item_id;
}
