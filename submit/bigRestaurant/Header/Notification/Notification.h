#ifndef DD445CE6_C34D_4208_8AAE_5AF853B413D3
#define DD445CE6_C34D_4208_8AAE_5AF853B413D3

#include <ctime>
#include <iostream>
#include <iomanip>

using namespace std;

class Notification
{
private:
    int notification_id;
    int reservation_id;
    time_t created_on;
    string content;


public:
    Notification();
    ~Notification();
    Notification(
        int _notification_id,
        int _reservation_id,
        time_t _created_on,
        string _content)
        : notification_id(_notification_id),
          reservation_id(_reservation_id),
          created_on(_created_on),
          content(_content) {}

    bool send();


    int getNotification_id();
    void setNotification_id(int notification_id);
    int getReservation_id();
    void setReservation_id(int reservation_id);
    time_t getCreated_on();
    void setCreated_on(time_t created_on);
    string getContent();
    void setContent(string content);
};

#endif /* DD445CE6_C34D_4208_8AAE_5AF853B413D3 */
