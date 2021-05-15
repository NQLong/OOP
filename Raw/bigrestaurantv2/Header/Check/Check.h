#ifndef FFD777D0_CADC_4D73_9AC7_0844AAD2E262
#define FFD777D0_CADC_4D73_9AC7_0844AAD2E262

#include "../Order/Order.h"

class Check
{
private:
    int check_id;
    int order_id;
    int branch_id;
    double amount;
    double tip;
    double tax;
    int payment_id = -1;
    bool is_paid = false;

    static list<Check> checks;

public:
    Check();
    ~Check();
    Check(
        int _check_id,
        int _order_id,
        double _amount,
        double _tip,
        double _tax,
        bool _ispaid)
        : check_id(_check_id),
          order_id(_order_id),
          amount(_amount),
          tip(_tip),
          tax(_tax),
          is_paid(_ispaid) {}

    double totalPay();
    static Check input_check(Order *order);

    static Check *get_check(int check_id);
    static int selectCheckId(int branch_id);

    bool createPayment();

    static bool add_check();
    static bool add_check(Check);

    static list<Check> *getChecks();
    static void setChecks(list<Check> checks);

    int getCheck_id();
    void setCheck_id(int check_id);
    int getOrder_id();
    void setOrder_id(int order_id);
    double getAmount();
    void setAmount(double amount);
    double getTip();
    void setTip(double tip);
    double getTax();
    void setTax(double tax);
    bool isPaid();
    void setIs_paid(bool ispaid);
    int getPayment_id();
    void setPayment_id(int payment_id);
    int getBranch_id();
    void setBranch_id(int branch_id);

    friend ostream &operator<<(ostream &os, Check &);
};

#endif /* FFD777D0_CADC_4D73_9AC7_0844AAD2E262 */
