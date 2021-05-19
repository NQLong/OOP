#ifndef B876215C_B40B_42C3_9E5F_A34DFE9D2CA7
#define B876215C_B40B_42C3_9E5F_A34DFE9D2C

#include "Payment.h"
class CreditCardTransaction : public Payment
{
private:
    string nameOnCard;

public:
    CreditCardTransaction();
    ~CreditCardTransaction();
    CreditCardTransaction(int _payment_id,
                          int _check_id,
                          int _amount)
        : Payment(_payment_id, _check_id, _amount, P_CARD) {}

    CreditCardTransaction(
        double _cash_tendered,
        int _payment_id,
        int _check_id,
        int _amount,
        string _nameOnCard
        )
        : Payment(_payment_id, _check_id, _amount, P_CARD),
          nameOnCard(_nameOnCard)
           {}

    static CreditCardTransaction input(Check *);

    string getNameOnCard();

    void setNameOnCard(string nameOnCard);

    friend ostream &operator<<(ostream &os, const CreditCardTransaction &c);
};

#endif /* B876215C_B40B_42C3_9E5F_A34DFE9D2CA7 */
