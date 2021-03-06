#ifndef DC18D6FE_0E15_4FB6_912D_79977AAAC784
#define DC18D6FE_0E15_4FB6_912D_79977AAAC784

#include "Person.h"
#include "Actor.h"
#include <ctime>
#include "Account.h"
#include "../Constraint/Constraint.h"

#include <iomanip>

class Employee : public Person, public iActor
// , public iActor
{
private:
    int employee_id;
    DayTime date_joined;
    Account account;
    int branch_id;
    EmployeeType Typ;

    static int new_id;

public:
    Employee();
    ~Employee();

    Employee(string _name, Account _account, string _email, string _phone, EmployeeType _Typ)
        : Person(_name, _email, _phone), employee_id(new_id++), account(_account), date_joined(time(0)), Typ(_Typ) {}

    Employee(string _name, Account _account, string _email, string _phone, EmployeeType _Typ, int _branch_id)
        : Person(_name, _email, _phone), employee_id(new_id++), account(_account), date_joined(time(0)), Typ(_Typ), branch_id(_branch_id) {}

    void *getBranch();

    EmployeeType getTyp();
    void setTyp(EmployeeType Typ);

    int getBranch_id();
    void setBranch_id(int branch_id);

    DayTime getDate_joined();
    void setDate_joined(DayTime date_joined);

    int getEmployee_id();
    void setEmployee_id(int employee_id);

    Account *getAccount();
    void setAccount(Account account);

    // Branch* getBranch();
    void printMenu();
    void input_employee(int);

    friend ostream &operator<<(ostream &os, const Employee &);
};

#endif /* DC18D6FE_0E15_4FB6_912D_79977AAAC784 */
