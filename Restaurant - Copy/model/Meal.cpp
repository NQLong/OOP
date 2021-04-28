#include "Meal.h"

Meal::Meal() {}

Meal::Meal(const Meal &other)
{
    id = other.id;
    table = other.table;
    dishes = other.dishes;
    date = other.date;
    start = other.start;
    end = other.end;
    waiter = other.waiter;
    client = other.client;
    price = other.price;
    confirmed = other.confirmed;
}

Meal::Meal(Table *table, vector<ServedDish> dishes, int date, int start, int end, Waiter *waiter, Client *client, int id)
{
    this->table = table;
    this->dishes = dishes;
    this->date = date;
    this->start = start;
    this->end = end;
    this->waiter = waiter;
    this->client = client;
    this->price = 0;
    this->id = id;
    confirmed = false;
    for (vector<ServedDish>::iterator dish = dishes.begin(); dish != dishes.end(); dish++)
    {
        this->price += dish->getDish()->getPrice() * dish->getQuantity();
    }
}

Meal &Meal::operator=(const Meal &other)
{
    id = other.id;
    confirmed = other.confirmed;
    price = other.price;
    table = other.table;
    dishes = other.dishes;
    date = other.date;
    start = other.start;
    end = other.end;
    waiter = other.waiter;
    client = other.client;
    return *this;
}

bool Meal::isConfirmed()
{
    return this->confirmed;
}

void Meal::setConfirmed(bool confirmed)
{
    this->confirmed = confirmed;
}

int Meal::getId()
{
    return this->id;
}

void Meal::setId(int id)
{
    this->id = id;
}

Table *Meal::getTable()
{
    return table;
}

vector<ServedDish> Meal::getDishes()
{
    return dishes;
}

int Meal::getDate()
{
    return date;
}

int Meal::getStart()
{
    return start;
}

int Meal::getEnd() { return end; }

Waiter *Meal::getWaiter() { return waiter; }

Client *Meal::getClient() { return client; }

void Meal::setTable(Table *_table)
{
    table = _table;
}

void Meal::setDate(int _date)
{
    date = _date;
}

void Meal::setStart(int _start) { start = _start; }

void Meal::setEnd(int _end) { end = _end; }

void Meal::setDishes(vector<ServedDish> _dishes) { dishes = _dishes; }

void Meal::addDish(ServedDish item)
{
    vector<ServedDish>::iterator i = dishes.end();
    i = dishes.insert(i, item);
}

double Meal::getPrice()
{
    return this->price;
}

void Meal::setPrice(double price)
{
    this->price = price;
}

void Meal::setWaiter(Waiter *_waiter) { waiter = _waiter; }

void Meal::setClient(Client *client) { this->client = client; }

bool Meal::consistOfDish(Dish *dish)
{
    for (vector<ServedDish>::iterator it = this->dishes.begin(); it != this->dishes.end(); it++)
    {
        if (dish == it->getDish())
            return true;
    }
    return false;
}

void Meal::removeDish(Dish *dish)
{
    for (vector<ServedDish>::iterator it = this->dishes.begin(); it != this->dishes.end(); it++)
    {
        if (dish == it->getDish())
        {
            this->price -= it->getDish()->getPrice() * it->getQuantity();
            this->dishes.erase(it);
        }
    }
}

template <typename T>
string StringOfVector(vector<T> input)
{
    string res = "[";
    for (typename vector<T>::iterator i = input.begin(); i != input.end(); i++)
    {
        res += (i)->toString();
        if (i + 1 != input.end())
            res += ",";
    }
    res += "]";
    return res;
}

string Meal::toString()
{

    return "Meal(table = " + table->toString() + ",dishes = " + StringOfVector<ServedDish>(dishes) + ",date = " + to_string(date) + ",start = " + to_string(start) + ",end = " + to_string(end) + ")" +
           ",waiter =" + waiter->toString() + ",client = " + client->toString() + ")";
}