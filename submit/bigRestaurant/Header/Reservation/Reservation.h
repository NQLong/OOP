#ifndef E5D175CB_186B_4FC8_8D89_5FC035CBAE9B
#define E5D175CB_186B_4FC8_8D89_5FC035CBAE9B

#include "../../Header/Constraint/constraint.h"
#include "../Actor/Customer.h"

// #include "../../Restaurant/Header/Table.h"
#include "../Restaurant/Table.h"

#include <string>

using namespace std;
class Reservation
{
private:
    int reservation_id;
    int customer_id;
    list<int> table_ids;
    list<int> notification_ids;
    int people_count;
    ReservationStatus status = R_REQUESTED;
    string notes;
    DayTime time_of_reservation;
    time_t checkin_time;

    static int new_id;

public:
    Reservation();
    ~Reservation();
    Reservation(
        time_t _time_of_reservation,
        int _people_count,
        ReservationStatus _status,
        string _notes,
        time_t _checkin_time,
        int _customer_id,
        list<int> _table_ids,
        list<int> _notification_ids)
        : time_of_reservation(_time_of_reservation),
          people_count(_people_count),
          status(_status),
          notes(_notes),
          checkin_time(_checkin_time),
          customer_id(_customer_id),
          table_ids(_table_ids),
          notification_ids(_notification_ids) {}

    bool update_people_count(int);

    static Reservation input(int);

    static list<Reservation> *getReservations();

    static void setReservations(list<Reservation> reservations);

    int getReservation_id();
    void setReservation_id(int reservation_id);
    time_t getTime_of_reservation();
    void setTime_of_reservation(time_t time_of_reservation);
    int getPeople_count();
    void setPeople_count(int people_count);
    ReservationStatus getStatus();
    void setStatus(ReservationStatus status);
    string getNotes();
    void setNotes(string notes);
    time_t getCheckin_time();
    void setCheckin_time(time_t checkin_time);
    int getCustomer_id();
    void setCustomer_id(int customer_id);
    list<int> getTable_ids();
    void setTable_ids(list<int> table_ids);
    list<int> getNotification_ids();
    void setNotification_ids(list<int> notification_ids);
};
#endif /* E5D175CB_186B_4FC8_8D89_5FC035CBAE9B */
