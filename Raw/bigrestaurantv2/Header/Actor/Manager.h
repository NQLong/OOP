#ifndef E71D3C88_C79F_414F_9163_C1AF6FD01C25
#define E71D3C88_C79F_414F_9163_C1AF6FD01C25
// class Manager(Employee):
//     def __init__(self, id, account, name, email, phone):
//         super().__init__(id, account, name, email, phone)

//     def add_employee(self):
//         None

#include "Employee.h"
#include "Actor.h"
#include "../Restaurant/Restaurant.h"
#include "../Constraint/constraint.h"
#include "../Restaurant/Table.h"

class Manager : public Employee
// , public iActor
{
private:
public:
    Manager();
    ~Manager();
    Manager(int _id, string _name, Account _account, string _email, string _phone) : 
    Employee(_id, _name, _account, _email, _phone, MANAGER) {}
    Manager(int _id, string _name, Account _account, string _email, string _phone, int _branch_id) :
    Employee(_id, _name, _account, _email, _phone, MANAGER, _branch_id) {}

    bool add_employee();
    bool cancel_employee();
    bool reassign_employee();

    bool add_table();
    bool modify_table();

    bool add_menu();
    bool modify_menu();

    void view();
    void meuManageView();
    void accountManageView();
    void tableManagerView();

};
#endif /* E71D3C88_C79F_414F_9163_C1AF6FD01C25 */
