#ifndef E7BB9784_C3AA_4CC5_BAC0_53762DF1C47C
#define E7BB9784_C3AA_4CC5_BAC0_53762DF1C47C
#include "Payment.h"
class CheckTransaction : public Payment
{
private:
    string bank_name;
    string check_number;

public:
    CheckTransaction();
    ~CheckTransaction();
    CheckTransaction(int _payment_id,
                     int _check_id,
                     int _amount)
        : Payment(_payment_id, _check_id, _amount, P_CHECK) {}

    CheckTransaction(
        double _cash_tendered,
        int _payment_id,
        int _check_id,
        int _amount,
        string _bank_name,
        string _check_number)
        : Payment(_payment_id, _check_id, _amount, P_CHECK),
          bank_name(_bank_name) ,
          check_number(_check_number) {}

    static CheckTransaction input(Check *);

    string getBank_name();
    void setBank_name(string bank_name);
    string getCheck_number();
    void setCheck_number(string check_number);

    friend ostream &operator<<(ostream &os, const CheckTransaction &c);
};
#endif /* E7BB9784_C3AA_4CC5_BAC0_53762DF1C47C */
