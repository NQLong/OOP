#include "../../Header/Check/Check.h"
#include "../../Header/Check/Payment.h"
#include "../../Header/Check/CashTransaction.h"
#include "../../Header/Check/CheckTransaction.h"
#include "../../Header/Check/CreditCardTransaction.h"

list<Check> Check::checks;

Check::Check() {}
Check::~Check() {}

bool Check::add_check(Check check)
{
    checks.push_back(check);
    return true;
}

int Check::selectCheckId(int branch_id)
{
    for (auto it = checks.begin(); it != checks.cend(); it++)
        if (it->getBranch_id() == branch_id)
            cout << setw(3) << left << to_string(it->getCheck_id()) + "."
                 << "Order id: " << it->getOrder_id() << endl;
    cout << "check id: ";
    int id;
    cin >> id;
    cin.ignore();
    if (!get_check(id))
    {
        cout << "invalid check id";
        wait();
        return -1;
    }
    return id;
}

bool Check::createPayment()
{
    clear();
    Payment *payment;
    cout << "Payment: " << endl;
    int count = 1;

    cout

        << setw(3) << left << to_string(count++) + "."
        << "Cash." << endl
        << setw(3) << left << to_string(count++) + "."
        << "Check." << endl
        << setw(3) << left << to_string(count++) + "."
        << "Credit card." << endl;

    cout << endl
         << "Pay by: ";
    int option;
    cin >> option;
    cin.ignore();
    clear();
    if (!(option < 4 && option > 0))
    {
        cout << "invalid option";
        wait();
        return false;
    }

    switch (option)
    {
    case 1:
        payment = new CashTransaction(CashTransaction::input(this));

        break;
    case 2:
        payment = new CheckTransaction(CheckTransaction::input(this));

        break;
    case 3:
        payment = new CreditCardTransaction(CreditCardTransaction::input(this));
        break;
    }
    payment->setPayment_id(Payment::getPayments().size() ? Payment::getPayments().back()->getPayment_id() + 1 : 0);
    Payment::addPayemnt(payment);
    this->payment_id = payment->getPayment_id();
    this->is_paid = true;
    clear();
    cout << *this;
    wait();
    return true;
}

Check *Check::get_check(int check_id)
{
    for (auto it = checks.begin(); it != checks.cend(); it++)
        if (it->getCheck_id() == check_id)
            return &(*it);
    return NULL;
}

ostream &operator<<(ostream &os, Check &c)
{
    os << "Check id: " << c.check_id << endl;
    os << "Order id: " << c.order_id << endl;
    os << "Amount : " << c.amount << endl;
    os << "Tip : " << c.tip << endl;
    os << "Tax : " << c.tax << endl;
    os << "payment : ";
    if (c.payment_id == -1)
        os << "None\n";
    else
    {
        Payment *payment = Payment::getPayment(c.payment_id);
        if (payment)
        {
            switch (payment->getTyp())
            {
            case P_CASH:
                os <<endl<< *(CashTransaction *)payment;
                break;
            case P_CHECK:
                os <<endl<< *(CheckTransaction *)payment;
                break;
            case P_CARD:
                os <<endl<< *(CreditCardTransaction *)payment;
                break;
            }
        }
        else
            os << "None\n";
    }
    os << "-------------------------------" << endl;
    os << "Total: " << c.totalPay();
    return os;
}
Check Check::input_check(Order *order)
{
    Check temp;
    temp.amount = order->getPrice();
    temp.tax = temp.amount * 0.1;
    temp.order_id = order->getOrder_id();
    temp.branch_id = order->getBranch_id();
    temp.is_paid = false;
    cout << "Tip: ";
    cin >> temp.tip;
    cin.ignore();
    return temp;
}
double Check::totalPay()
{
    return this->amount + this->tax + this->tip;
}
//getter & setter
int Check::getPayment_id()
{
    return payment_id;
}
void Check::setPayment_id(int payment_id)
{
    this->payment_id = payment_id;
}

int Check::getCheck_id()
{
    return this->check_id;
}

void Check::setCheck_id(int check_id)
{
    this->check_id = check_id;
}

int Check::getOrder_id()
{
    return this->order_id;
}

void Check::setOrder_id(int order_id)
{
    this->order_id = order_id;
}

double Check::getAmount()
{
    return this->amount;
}

void Check::setAmount(double amount)
{
    this->amount = amount;
}

double Check::getTip()
{
    return this->tip;
}

void Check::setTip(double tip)
{
    this->tip = tip;
}

double Check::getTax()
{
    return this->tax;
}

void Check::setTax(double tax)
{
    this->tax = tax;
}

bool Check::isPaid()
{
    return this->is_paid;
}

void Check::setIs_paid(bool ispaid)
{
    this->is_paid = ispaid;
}

list<Check> *Check::getChecks()
{
    return &checks;
}

void Check::setChecks(list<Check> checks)
{
    checks = checks;
}

int Check::getBranch_id()
{
    return branch_id;
}
void Check::setBranch_id(int branch_id)
{
    this->branch_id = branch_id;
}