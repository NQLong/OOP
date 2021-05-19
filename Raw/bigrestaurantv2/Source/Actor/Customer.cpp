#include "../../Header/Actor/Customer.h"

list<Customer> Customer::customers;

int Customer::select_customer_id()
{
    int id;
    for (auto it = customers.begin(); it != customers.end(); it++)
    {
        cout << setw(3) << left << to_string(it->getCustomerId()) + "." << it->getName() << endl;
        cout << setw(3) << left << "" << "Email: "<<it->getEmail() << endl;
    }
    cout << endl;
    cout << "Customer's id: ";
    cin >> id;
    cin.ignore();
    if (!Customer::get_custoner(id)){
        cout<<"invalid customer id";
        wait();
        return -1;
    }
    return id;
}

Customer Customer::input_customer()
{
    Customer temp;
    temp.input_person();
    temp.last_visited = time(0);
    return temp;
}

ostream &operator<<(ostream &os, const Customer &c)
{
    return os
           << Person(c) << endl
           << "Last visited at: " << (char*)ctime(&c.last_visited);
}

bool Customer::add_customer(Customer customer)
{
    customers.push_back(customer);
    return true;
}

bool Customer::add_customer()
{
    return true;
}

Customer *Customer::get_custoner(int id)
{
    for (auto it = customers.begin(); it != customers.end(); it++)
    {
        if (it->getCustomerId() == id)
            return &*it;
    }
    return NULL;
}

int Customer::getCustomerId()
{
    return this->customerId;
}

void Customer::setCustomerId(int customerId)
{
    this->customerId = customerId;
}

time_t Customer::getLast_visited()
{
    return this->last_visited;
}

void Customer::setLast_visited(time_t last_visited)
{
    this->last_visited = last_visited;
}

list<Customer> *Customer::getCustomers()
{
    return &customers;
}

void Customer::setCustomers(list<Customer> customers)
{
    customers = customers;
}
