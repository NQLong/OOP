#ifndef E5D175CB_186B_4FC8_8D89_5FC035CBAE9B
#define E5D175CB_186B_4FC8_8D89_5FC035CBAE9B

#include "../../Header/Constraint/constraint.h"
#include "../Actor/Customer.h"

// #include "../Restaurant/Table.h"

#include "../Manage/TableManager.h"

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
    ReservationStatus status = R_PENDING;
    string notes;
    DayTime time_of_reservation;
    DayTime checkin_time = DayTime(0);
    int branch_id;
    int duration;

    static int new_id;

public:
    static string class_name; // = "reservation";
    friend ostream &operator<<(ostream &, const Reservation &);
    friend ostream &operator<<(ostream &, const list<Reservation> &);
    friend bool operator==(const Reservation &, const Reservation &);
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
        list<int> _notification_ids,
        int branch_id,
        int duration);

    bool update_people_count(int);
    bool confirm();
    bool is_confirmable();
    bool is_colided(Reservation *other);
    int total_seat();

    static Reservation input(int branch);

    int getReservation_id();
    int get_id();
    void setReservation_id(int reservation_id);
    DayTime getTime_of_reservation();
    void setTime_of_reservation(DayTime time_of_reservation);
    int getPeople_count();
    void setPeople_count(int people_count);
    ReservationStatus getStatus();
    void setStatus(ReservationStatus status);
    string getNotes();
    void setNotes(string notes);
    DayTime getCheckin_time();
    void setCheckin_time(DayTime checkin_time);
    int getCustomer_id();
    void setCustomer_id(int customer_id);
    list<int> getTable_ids();
    void setTable_ids(list<int> table_ids);
    list<int> getNotification_ids();
    void setNotification_ids(list<int> notification_ids);
    int get_branch_id();
    void set_branch_id(int branch_id);
    int get_duration();
    void set_duration(int);
};
#endif /* E5D175CB_186B_4FC8_8D89_5FC035CBAE9B */
