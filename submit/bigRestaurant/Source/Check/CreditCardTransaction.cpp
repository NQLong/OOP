#include "../../Header/Check/CreditCardTransaction.h"

CreditCardTransaction::CreditCardTransaction() {}
CreditCardTransaction::~CreditCardTransaction() {}


CreditCardTransaction CreditCardTransaction::input(Check* check){
    CreditCardTransaction temp;
    temp.setAmount(check->totalPay());
    temp.setCheck_id(check->getCheck_id());
    temp.setTyp(P_CARD);
    cout << "name on card: ";
    getline(cin, temp.nameOnCard);
    return temp;
}

ostream &operator<<(ostream &os, const CreditCardTransaction &c)
{
    return os
           << setw(5) << ""
           << "Pay by credit card" << endl
           << setw(5) << ""
           << "name on card: " << c.nameOnCard << endl
           << Payment(c);
}

string CreditCardTransaction::getNameOnCard()
{
    return this->nameOnCard;
}

void CreditCardTransaction::setNameOnCard(string nameOnCard)
{
    this->nameOnCard = nameOnCard;
}
