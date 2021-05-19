#ifndef F64A6D32_5553_4411_8071_4B303369BBA6
#define F64A6D32_5553_4411_8071_4B303369BBA6

#include "Check.h"

class Payment
{
private:
    int payment_id;
    int check_id;
    int amount;
    time_t creation_date;
    PaymentType Typ;

    static list<Payment *> payments;

public:
    Payment() : creation_date(time(0))
    {
    }
    ~Payment();
    Payment(int _payment_id,
            int _check_id,
            int _amount,
            PaymentType _Typ)
        : payment_id(_payment_id),
          check_id(_check_id),
          amount(_amount),
          Typ(_Typ) {}

    static bool addPayemnt(Payment*);
    static list<Payment *> getPayments();
    static void setPayments(list<Payment *> payments);
    static Payment* getPayment(int id);

    bool initiateTransaction();

    // void input_payment(PaymentType _Typ);
    int getPayment_id();
    void setPayment_id(int payment_id);
    int getCheck_id();
    void setCheck_id(int check_id);
    int getAmount();
    void setAmount(int amount);
    time_t getCreation_date();
    void setCreation_date(time_t creation_date);
    PaymentType getTyp();
    void setTyp(PaymentType Typ);

    friend ostream &operator<<(ostream &os,const Payment &c);
};

#endif /* F64A6D32_5553_4411_8071_4B303369BBA6 */
