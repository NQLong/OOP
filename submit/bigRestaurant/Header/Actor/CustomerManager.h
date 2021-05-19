#ifndef C58C01F0_534F_4A2C_9AEF_E661019DECEF
#define C58C01F0_534F_4A2C_9AEF_E661019DECEF

#include "Customer.h"

class CustomerManager
{
    list<Customer> *customers;

public:
    CustomerManager();
    ~CustomerManager();
    CustomerManager(void *);

    int select_customer_id();

    list<Customer> *getCustomers();
    void setCustomers(list<Customer> *customers);

    bool add_customer(Customer);
    bool add_customer();
    bool remove_customer();
    bool remove_customer(Customer);
    Customer *pick_customer();
    Customer *get_customer(int id);
    bool select_customer();
    void customers_list();
    void manage_customer();
};

#endif /* C58C01F0_534F_4A2C_9AEF_E661019DECEF */
