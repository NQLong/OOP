#ifndef BD02162A_FB7B_4604_9AC1_703F6A388BE6
#define BD02162A_FB7B_4604_9AC1_703F6A388BE6

#include "Person.h"
#include <list>
#include <ctime>
#include <iomanip>
#include "../Constraint/Constraint.h"


class Customer : public Person
{
private:
    int customerId;
    DayTime last_visited;

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

    static Customer input_customer();

    int getCustomerId();

    void setCustomerId(int customerId);

    DayTime getLast_visited();

    void setLast_visited(DayTime last_visited);

    static void render(list<Customer> lst);

    friend ostream &operator<<(ostream &os, const Customer &c);
    
    friend bool operator==(const Customer &lhs, const Customer &rhs);

};

#endif /* BD02162A_FB7B_4604_9AC1_703F6A388BE6 */
