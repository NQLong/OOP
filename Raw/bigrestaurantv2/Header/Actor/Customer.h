#ifndef BD02162A_FB7B_4604_9AC1_703F6A388BE6
#define BD02162A_FB7B_4604_9AC1_703F6A388BE6

#include "Person.h"
#include <list>
#include <ctime>
#include <iomanip>
#include "../../Header/Constraint/constraint.h"

class Customer : public Person
{
private:
    int customerId;
    time_t last_visited;

    static list<Customer> customers;

public:
    Customer() {}
    Customer(int _id,
             string _name,
             string _email,
             string _phone)
        : Person(_name, _email, _phone),
          customerId(_id),
          last_visited(time(0)) {}

    static int select_customer_id();

    static Customer input_customer();

    static bool add_customer();

    static bool add_customer(Customer);

    int getCustomerId();

    void setCustomerId(int customerId);

    time_t getLast_visited();

    void setLast_visited(time_t last_visited);

    static Customer *get_custoner(int id);
    static list<Customer> *getCustomers();
    static void setCustomers(list<Customer> customers);


    friend ostream& operator<<(ostream& os, const Customer& c);
};

#endif /* BD02162A_FB7B_4604_9AC1_703F6A388BE6 */
