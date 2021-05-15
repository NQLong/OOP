#ifndef C5AE98DF_13F2_4331_AC74_3F24471746E0
#define C5AE98DF_13F2_4331_AC74_3F24471746E0
#include "Payment.h"
class CashTransaction : public Payment
{
private:
    double cash_tendered;

public:
    CashTransaction();
    ~CashTransaction();
    CashTransaction(int _payment_id,
                    int _check_id,
                    int _amount)
        : Payment(_payment_id, _check_id, _amount, P_CASH) {}

    CashTransaction(
        double _cash_tendered,
        int _payment_id,
        int _check_id,
        int _amount)
        : Payment(_payment_id, _check_id, _amount, P_CASH),
          cash_tendered(_cash_tendered) {}

    static CashTransaction input(Check *);

    double getCash_tendered();
    void setCash_tendered(double cash_tendered);

    friend ostream &operator<<(ostream &os, const CashTransaction &c);
};
#endif /* C5AE98DF_13F2_4331_AC74_3F24471746E0 */
