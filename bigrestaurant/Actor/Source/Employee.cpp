#include "../Header/Employee.h"

Employee::~Employee() {}
Employee::Employee() {}

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

time_t Employee::getDate_joined()
{
    return this->date_joined;
}

void Employee::setDate_joined(time_t date_joined)
{
    this->date_joined = date_joined;
}

Account* Employee::getAccount()
{
    return &account;
}

void Employee::setAccount(Account account)
{
    this->account = account;
}


ostream& operator << (ostream& os,const Employee& e){
    os 
    <<e.employee_id<<endl
    <<Person(e)<<endl
    <<(char*)ctime(&e.date_joined)
    <<e.Typ<<endl
    <<e.account
    ;
    return os;
}