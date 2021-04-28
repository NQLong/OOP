#include "../../Header/Check/Payment.h"
list<Payment *> Payment::payments;

bool Payment::addPayemnt(Payment *p)
{
    payments.push_back(p);
    return true;
}

Payment *Payment::getPayment(int id)
{
    for (auto it = payments.begin(); it != payments.cend(); it++)
        if ((*it)->getPayment_id() == id)
            return *it;
    return NULL;
}

ostream &operator<<(ostream &os, const Payment &p)
{
    os << setw(5) << ""
       << "Pay at: " << (char *)ctime(&p.creation_date);
    return os;
}
Payment::~Payment() {}
// void Payment::input_payment
bool Payment::initiateTransaction()
{
    return true;
}

list<Payment *> Payment::getPayments()
{
    return payments;
}

void Payment::setPayments(list<Payment *> _payments)
{
    payments = _payments;
}

int Payment::getPayment_id()
{
    return this->payment_id;
}

void Payment::setPayment_id(int payment_id)
{
    this->payment_id = payment_id;
}

int Payment::getCheck_id()
{
    return this->check_id;
}

void Payment::setCheck_id(int check_id)
{
    this->check_id = check_id;
}

int Payment::getAmount()
{
    return this->amount;
}

void Payment::setAmount(int amount)
{
    this->amount = amount;
}

time_t Payment::getCreation_date()
{
    return this->creation_date;
}

void Payment::setCreation_date(time_t creation_date)
{
    this->creation_date = creation_date;
}

PaymentType Payment::getTyp()
{
    return this->Typ;
}

void Payment::setTyp(PaymentType Typ)
{
    this->Typ = Typ;
}
