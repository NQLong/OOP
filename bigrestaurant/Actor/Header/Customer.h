#ifndef BD02162A_FB7B_4604_9AC1_703F6A388BE6
#define BD02162A_FB7B_4604_9AC1_703F6A388BE6

#include "Person.h"
#include <ctime>

class Customer : public Person
{
private:
    int customerId;
    time_t last_visited;


public:
    Customer() {}
    Customer(int _id, string _name, string _email, string _phone) : Person(_name, _email, _phone), customerId(_id), last_visited(time(0)) {}
    
    int getCustomerId();

    void setCustomerId(int customerId);

    time_t getLast_visited();

    void setLast_visited(time_t last_visited);
};

#endif /* BD02162A_FB7B_4604_9AC1_703F6A388BE6 */
