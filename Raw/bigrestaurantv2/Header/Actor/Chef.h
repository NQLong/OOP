#ifndef CBF407BA_C0F1_468F_A487_6637C014A0A0
#define CBF407BA_C0F1_468F_A487_6637C014A0A0

// class Chef(Employee):
//     def __init__(self, id, account, name, email, phone):
//         super().__init__(id, account, name, email, phone)

//     def take_order(self):
//         None
#include "../../Header/Constraint/constraint.h"
#include "Employee.h"

class Chef : public Employee
// , public iActor
{
private:
public:
    Chef();
    ~Chef();
    Chef(int _id, string _name, Account _account, string _email, string _phone) :
    Employee(_id, _name, _account, _email, _phone,CHEF) {}
    Chef(int _id, string _name, Account _account, string _email, string _phone, int _branch_id) :
    Employee(_id, _name, _account, _email, _phone,CHEF, _branch_id) {}
    
    bool prepare_order();
    bool complete_order();

    void view();
};

#endif /* CBF407BA_C0F1_468F_A487_6637C014A0A0 */
