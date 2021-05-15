#include "../../Header/Meal/Meal.h"
#include "../../Header/Restaurant/Restaurant.h"

Meal::Meal() {}
Meal::~Meal() {}

double Meal::getPrice()
{
    double total = 0;
    for (auto it = this->meal_items.begin(); it != this->meal_items.end(); it++)
        total += it->getPrice();
    return total;
}

ostream &operator<<(ostream &os, const Meal &meal)
{
    os << setfill(' ');
    os
        << setw(6) << ""
        << "meal id: " << meal.meal_id << endl
        << setw(6) << ""
        << "seat id: " << meal.seat_id << endl
        << setw(30) << right << ""
        << "MEAL ITEMs" << endl
        << setw(60) << setfill('_') << "" << endl;
    os << setfill(' ');
    for (auto it = meal.meal_items.begin(); it != meal.meal_items.end(); it++)
        os << *it << endl;

    os << setw(60) << setfill('_') << "" << endl;
    os << setfill(' ');
    return os;
}

bool Meal::add_meal_item(MealItem meal_item)
{
    meal_items.push_back(meal_item);
    return true;
}

Meal Meal::inputMeal(Table *table, int branch_id)
{
    Meal temp;
    clear();
    temp.seat_id = table->selectSeatId();
    Menu *menu = Restaurant::getBranch(branch_id)->getMenu();
    clear();
    int option;
    bool loop = true;

    while (loop)
    {
        int count = 1;
        clear();

        cout
            << setw(3) << left << to_string(count++) + "."
            << "add new mealitem." << endl
            << endl
            << setw(3) << left << "0."
            << "Done." << endl;

        cout << endl
             << "Enter your choice: ";
        cin >> option;
        cin.ignore();
        switch (option)
        {
        case 1:
            temp.add_meal_item(menu);
            break;
        default:
            loop = false;
            break;
        }
    }
    return temp;
}

bool Meal::add_meal_item(Menu *menu)
{
    clear();
    MealItem meal_item = MealItem::input_meal_item(menu);
    meal_item.setMeal_item_id(meal_items.size() > 0 ? meal_items.back().getMeal_item_id() + 1 : 0);
    return this->add_meal_item(meal_item);
}

int Meal::getMeal_id()
{
    return this->meal_id;
}

void Meal::setMeal_id(int meal_id)
{
    this->meal_id = meal_id;
}

int Meal::getSeat_id()
{
    return this->seat_id;
}

void Meal::setSeat_id(int seat_id)
{
    this->seat_id = seat_id;
}

list<MealItem> *Meal::getMeal_items()
{
    return &this->meal_items;
}

void Meal::setMeal_items(list<MealItem> meal_items)
{
    this->meal_items = meal_items;
}
