#include "../../Header/Check/CheckTransaction.h"

CheckTransaction::CheckTransaction() {}
CheckTransaction::~CheckTransaction() {}

ostream &operator<<(ostream &os, const CheckTransaction &c)
{
    return os
           << setw(5) << ""
           << "Pay by check" << endl
           << setw(5) << ""
           << "bank name: " << c.bank_name << endl
           << setw(5) << ""
           << "check number: " << c.check_number << endl
           << Payment(c);
}
CheckTransaction CheckTransaction::input(Check *check)
{
    CheckTransaction temp;
    temp.setAmount(check->totalPay());
    temp.setCheck_id(check->getCheck_id());
    temp.setTyp(P_CHECK);
    cout << "bank name: ";
    getline(cin, temp.bank_name);
    cout << "check number: ";
    getline(cin, temp.check_number);
    return temp;
}
string CheckTransaction::getBank_name()
{
    return this->bank_name;
}

void CheckTransaction::setBank_name(string bank_name)
{
    this->bank_name = bank_name;
}

string CheckTransaction::getCheck_number()
{
    return this->check_number;
}

void CheckTransaction::setCheck_number(string check_number)
{
    this->check_number = check_number;
}
