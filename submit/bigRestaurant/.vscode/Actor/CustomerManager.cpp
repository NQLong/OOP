#include "../../Header/Actor/CustomerManager.h"

CustomerManager::CustomerManager() {}
CustomerManager::~CustomerManager() {}
CustomerManager::CustomerManager(void *lst)
{
    this->customers = (list<Customer> *)lst;
}

int CustomerManager::select_customer_id()
{
    customers_list();
    cout << endl;

    Customer *ptr = pick_customer();
    if (!ptr)
    {
        cout << "Invalid id";
        return -1;
    }
    return ptr->getCustomerId();
}

bool CustomerManager::add_customer(Customer customer)
{
    if (!get_customer(customer.getCustomerId()))
    {
        customers->push_back(customer);
        return true;
    }
    return false;
}

bool CustomerManager::add_customer()
{
    cout << "add new customer: \n";
    Customer customer = Customer::input_customer();
    if (add_customer(customer))
    {
        cout << "Success";
        return true;
    }
    else
        cout << "Fail";
    return false;
}

Customer *CustomerManager::get_customer(int id)
{
    for (auto it = customers->begin(); it != customers->end(); it++)
    {
        if (it->getCustomerId() == id)
            return &*it;
    }
    return NULL;
}

list<Customer> *CustomerManager::getCustomers()
{
    return customers;
}

void CustomerManager::setCustomers(list<Customer> *customers)
{
    this->customers = customers;
}

Customer *CustomerManager::pick_customer()
{
    int id;
    cout << "Customer's id: ";
    cin >> id;
    cin.ignore();
    return get_customer(id);
}

bool CustomerManager::select_customer()
{
    Customer *ptr = pick_customer();
    if (!ptr)
    {
        cout << "Invalid id";
        return false;
    }
    cout << *ptr;
    return true;
}
void CustomerManager::customers_list()
{
    Customer::render(*customers);
}
bool CustomerManager::remove_customer()
{
    cout << "remove customer: \n";
    Customer *ptr = pick_customer();
    if (remove_customer(*ptr))
    {
        cout << "Done";
        return true;
    }
    else
        cout << "Fail";
    return false;
}
bool CustomerManager::remove_customer(Customer c)
{
    customers->remove(c);
    return true;
}

void CustomerManager::manage_customer()
{

    int option;
    bool loop = true;
    while (loop)
    {
        print_option({"add customer",
                      "remove cusomer",
                      "view customer",
                      "customers list"

        });

        cin >> option;
        cin.ignore();
        switch (option)
        {
        case 1:
            clear();
            add_customer();
            wait();
            break;
        case 2:
            clear();
            remove_customer();
            wait();
            break;

        case 3:
            clear();
            select_customer();
            wait();
            break;
        case 4:
            clear();
            customers_list();
            wait();
            break;

        default:
            loop = false;
            break;
        }
    }

    return;
}