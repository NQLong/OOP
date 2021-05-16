#ifndef BFC4C0F0_4337_42BC_A750_7E22D504F3AA
#define BFC4C0F0_4337_42BC_A750_7E22D504F3AA
#include "Notification.h"

class EmailNotification : public Notification
{
private:
    string email;

public:
    EmailNotification(
        int _notification_id,
        int _reservation_id,
        string _content,
        string _email)
        : Notification(_notification_id, _reservation_id, time(0), _content),
          email(_email) {}

    

    string getEmail();

    void setEmail(string email);
};

#endif /* BFC4C0F0_4337_42BC_A750_7E22D504F3AA */
