#include "../../Header/Check/CashTransaction.h"

CashTransaction::CashTransaction() {}
CashTransaction::~CashTransaction() {}

CashTransaction CashTransaction::input(Check *check)
{
    CashTransaction temp;
    temp.setAmount(check->totalPay());
    temp.setCheck_id(check->getCheck_id());
    temp.setTyp(P_CASH);
    cout << "Cash tenderd: ";
    cin >> temp.cash_tendered;
    cin.ignore();
    return temp;
}
ostream &operator<<(ostream &os, const CashTransaction &c)
{
    return os
           << setw(5) << ""
           << "Pay by cash" << endl
           << setw(5) << ""
           << "Cash tendered: " << c.cash_tendered << endl
           << Payment(c);
}
double CashTransaction::getCash_tendered()
{
    return this->cash_tendered;
}

void CashTransaction::setCash_tendered(double cash_tendered)
{
    this->cash_tendered = cash_tendered;
}
