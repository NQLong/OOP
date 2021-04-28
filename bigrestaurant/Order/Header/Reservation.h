#ifndef E5D175CB_186B_4FC8_8D89_5FC035CBAE9B
#define E5D175CB_186B_4FC8_8D89_5FC035CBAE9B
// class Reservation:
//     def __init__(self, id, people_count, notes, customer):
//         reservation_id = id
//         time_of_reservation = datetime.now()
//         people_count = people_count
//         status = ReservationStatus.REQUESTED
//         notes = notes
//         checkin_time = datetime.now()
//         customer = customer
//         tables = []
//         notifications = []

//     def update_people_count(self, count):
//         None

#include <ctime>

#include "../../Constraint/constraint.h"
#include "../../Actor/Header/Customer.h"

// #include "../../Restaurant/Header/Table.h"
#include "../../Restaurant/Header/Table.h"

#include <string>

using namespace std;
class Reservation
{
private:
    int reservation_id;
    time_t time_of_reservation;
    int people_count;
    ReservationStatus status = R_REQUESTED;
    string notes = notes;
    time_t checkin_time;
    Customer customer = customer;
    list<Table *> tables;
    list<string> notifications;

public:
    bool update_people_count(int);
};
#endif /* E5D175CB_186B_4FC8_8D89_5FC035CBAE9B */
