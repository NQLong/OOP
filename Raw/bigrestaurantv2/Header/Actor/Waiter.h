#ifndef A0259975_52F1_498C_A286_02C666F7E5DA
#define A0259975_52F1_498C_A286_02C666F7E5DA
#include "Employee.h"
#include "../Order/Order.h"
class Waiter : public Employee
// , public iActor
{
private:
public:
    Waiter();
    ~Waiter();
    Waiter(int _id, string _name, Account _account, string _email, string _phone) : 
    Employee(_id, _name, _account, _email, _phone, WAITER) {}
    Waiter(int _id, string _name, Account _account, string _email, string _phone, int _branch_id) :
    Employee(_id, _name, _account, _email, _phone,WAITER, _branch_id) {}

    bool placeOrder();
    bool create_order();
    void view();
    void viewOrder();
};

#endif /* A0259975_52F1_498C_A286_02C666F7E5DA */
