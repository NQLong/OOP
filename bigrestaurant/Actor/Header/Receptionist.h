#ifndef DA385B57_7F48_4A01_833F_3632A285C34E
#define DA385B57_7F48_4A01_833F_3632A285C34E

#include "Employee.h"

// class Receptionist(Employee):
//     def __init__(self, id, account, name, email, phone):
//         super().__init__(id, account, name, email, phone)

//     def create_reservation(self):
//         None

//     def search_customer(self, name):
//         None

class Receptionist : public Employee
// , public iActor
{
private:
public:
    Receptionist();
    ~Receptionist();
    Receptionist(int _id, string _name, Account _account,  string _email, string _phone):
    Employee( _id,  _name,  _account,   _email,  _phone, RECEPTIONIST){}

    bool create_reservation();
     void view();
};
#endif /* DA385B57_7F48_4A01_833F_3632A285C34E */
