#include "../../Header/Meal/Meal.h"

int Meal::new_id = 0;
string Meal::class_name = "meal";
Meal::Meal()
{
    this->meal_id = new_id++;
}
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
    int space = 20;
    os << setfill(' ');
    os
        << setw(space) << left
        << "meal id"
        << ": " << meal.meal_id << endl
        << setw(space) << left
        << "seat id"
        << ": " << meal.seat_id << endl
        << setw(space) << left
        << "meal items"
        << ": " << endl
        << meal.meal_items;

    return os;
}

ostream &operator<<(ostream &os, const list<Meal> &lst)
{
     char border ='#';
    char inside_h_border = '-';
    char inside_v_border = '|';
    int border_size = 105;
    os
        << setw(border_size) << setfill(border) << "" << endl
        << setfill(' ');
    for (auto it = lst.begin(); it != lst.end(); it++)
    {
        stringstream ss;
        ss << *it;
        int title_size = -1;
        int text_size = -1;
        for (int k = 0; k < 3; k++)
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
            if (k != 2)
            {

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
            << setw(border_size) << setfill(border) << "" 
            << setfill(' ');
    }
    return os;
}

TableSeat *Meal::pick_seat(Table *t)
{
    return t->pick_seat();
}

Meal Meal::input(int menu, int table_id)
{
    Meal temp;
    ListManager<Table> t_m(Storage::tables);
    Table *table = t_m.get_element(table_id);
    clear();
    cout << "Meal for seat: \n";
    TableSeat *ts_ptr = temp.pick_seat(table);
    while (!ts_ptr)
    {
        clear();
        cout << "Invalid seat number";
        wait();
        clear();
        if (!select_statement("peak table seat list", "Continue pick seat"))
            cout << *(table->getSeats());
        ts_ptr = temp.pick_seat(table);
    }
    temp.seat_id = ts_ptr->get_id();
    clear();
    while (!select_statement("Add menu section", "Done"))
    {
        clear();
        temp.add_meal_item(menu);
        wait();
        clear();
    }
    return temp;
}

bool Meal::add_meal_item(int menu)
{
    return ListManager<MealItem>(&meal_items).add_element(menu);
}

int Meal::getMeal_id()
{
    return this->meal_id;
}

int Meal::get_id()
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
