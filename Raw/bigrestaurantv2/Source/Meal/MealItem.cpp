#include "../../Header/Meal/MealItem.h"

MealItem::MealItem() {}
MealItem::~MealItem() {}
double MealItem::getPrice()
{
    Menu *menu = Menu::getMenu(this->menu_id);
    MenuSection *section = menu->getMenu_section(this->menu_section_id);
    MenuItem *item = section->getMenu_item(this->menu_item_id);
    return item->getPrice() * this->quantity;
}
ostream &operator<<(ostream &os, const MealItem &meal_item)
{
    os << setfill(' ');
    os << setw(9) << to_string(meal_item.meal_item_id) + ".";
    Menu *menu = Menu::getMenu(meal_item.menu_id);
    MenuSection *section = menu->getMenu_section(meal_item.menu_section_id);
    MenuItem *item = section->getMenu_item(meal_item.menu_item_id);
    os << item->getTitle();
    os << setfill(' ');
    return os;
}

MealItem MealItem::input_meal_item(Menu *menu)
{
    MealItem temp;
    clear();
    temp.menu_id = menu->getMenu_id();

    temp.menu_section_id = menu->sectionIdSeclection();
    clear();
    temp.menu_item_id = menu->getMenu_section(temp.menu_section_id)->itemIdSelection();
    clear();
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
