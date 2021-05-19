#include "../../Header/Actor/Customer.h"

list<Customer> Customer::customers;

Customer Customer::input_customer()
{
    Customer temp;
    temp.input_person();
    temp.last_visited = DayTime(time(0));
    return temp;
}

ostream &operator<<(ostream &os, const Customer &c)
{
    return os
           << Person(c) << endl
           << "Last visited at: " << c.last_visited;
}

int Customer::getCustomerId()
{
    return this->customerId;
}

void Customer::setCustomerId(int customerId)
{
    this->customerId = customerId;
}

DayTime Customer::getLast_visited()
{
    return this->last_visited;
}

void Customer::setLast_visited(DayTime last_visited)
{
    this->last_visited = last_visited;
}

bool operator==(const Customer &lhs, const Customer &rhs)
{
    return (
        (rhs.customerId == lhs.customerId) &&
        (rhs.last_visited == lhs.last_visited) &&
        ((Person)rhs == (Person)lhs) &&
        true);
}

void Customer::render(list<Customer> lst)
{
    cout
        << setw(65) << setfill('*') << "" << endl
        << setfill(' ')
        << setw(7) << left << "|  id " << '|';
    Person::render_person_title();
    cout
        << endl
        << setw(65) << setfill('*') << "" << endl
        << setfill(' ');

    for (auto it = lst.begin(); it != lst.end(); it++)
    {
        if (!&*it)
            continue;
        cout
            << setw(7) << left << "|" + to_string(it->getCustomerId()) << '|';
        Person::render_person((Person)*it);
        cout
            << endl
            << setw(65) << setfill('*') << "" << endl
            << setfill(' ');
    }
}