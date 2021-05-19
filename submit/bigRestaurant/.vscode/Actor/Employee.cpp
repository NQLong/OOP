#include "../../Header/Actor/Employee.h"
// #include "../../Header/Restaurant/Restaurant.h"

int Employee::new_id = 0;

Employee::~Employee() {}
Employee::Employee() {}

// Branch* Employee::getBranch(){
//     Rest
// }

void *Employee::getBranch()
{
    // if (this->branch_id != -1)
    //     return Restaurant::getBranch(this->branch_id);
    return NULL;
}
void Employee::printMenu()
{
    // Branch *br = (Branch *)getBranch();
    // if (!br)
    // {
    //     cout << "your branch doesn't exist";
    //     wait();
    //     return;
    // }
    // Menu *menu = br->getMenu();
    // if (!menu)
    // {
    //     cout << "your branch doesn't have menu";
    //     wait();
    //     return;
    // }
    // clear();
    // cout << *menu;
    // wait();
    // cout << setfill(' ');
    // return;
}

void Employee::input_employee(int branch)
{
    this->input_person();
    this->branch_id = branch;
    this->employee_id = new_id++;
    account = Account::inputAccount();
}

EmployeeType Employee::getTyp()
{
    return this->Typ;
}

void Employee::setTyp(EmployeeType Typ)
{
    this->Typ = Typ;
}

int Employee::getBranch_id()
{
    return this->branch_id;
}

void Employee::setBranch_id(int branch_id)
{
    this->branch_id = branch_id;
}

int Employee::getEmployee_id()
{
    return this->employee_id;
}

void Employee::setEmployee_id(int employee_id)
{
    this->employee_id = employee_id;
}

DayTime Employee::getDate_joined()
{
    return this->date_joined;
}

void Employee::setDate_joined(DayTime date_joined)
{
    this->date_joined = date_joined;
}

Account *Employee::getAccount()
{
    return &account;
}

void Employee::setAccount(Account account)
{
    this->account = account;
}

ostream &operator<<(ostream &os, const Employee &e)
{
    os
        << "Employee's id" << e.employee_id << endl
        << Person(e) << endl
        << "Employee's join date" << (e.date_joined)
        << "Employee's type" << e.Typ << endl
        << e.account;
    return os;
}