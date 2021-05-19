#ifndef B7E5AD63_D675_4BF5_ADCA_80920130FD08
#define B7E5AD63_D675_4BF5_ADCA_80920130FD08
// from enum import Enum
#include <string>
#include <iostream>
#include <ctime>
#include <list>

using namespace std;
enum EmployeeType
{
    CHEF,
    WAITER,
    RECEPTIONIST,
    MANAGER,
    ADMIN
};

enum ReservationStatus
{
    R_REQUESTED,
    R_PENDING,
    R_CONFIRMED,
    R_CHECKED_IN,
    R_CANCELED,
    R_ABANDONED
};

enum SeatType
{
    S_REGULAR,
    S_KID,
    S_ACCESSIBLE,
    S_OTHER
};

enum OrderStatus
{
    O_RECEIVED,
    O_PREPARING,
    O_COMPLETED,
    O_CANCELED,
    O_NONE
};

enum TableStatus
{
    T_FREE,
    T_RESERVED,
    T_OCCUPIED,
    T_OTHER
};

enum AccountStatus
{
    A_ACTIVE,
    A_CLOSED,
    A_CANCELLED,
    A_BLACKLISTED,
    A_BLOCKED
};

enum PaymentStatus
{
    P_UNPAID,
    P_PENDING,
    P_COMPLETED,
    P_FILLED,
    P_DECLINED,
    P_CANCELLED,
    P_ABANDONED,
    P_SETTLING,
    P_SETTLED,
    P_REFUNDED
};

enum PaymentType
{
    P_CARD,
    P_CHECK,
    P_CASH
};

class Address
{
public:
    string
        street,
        city,
        state,
        zip_code,
        country;
    Address();
    Address(string _street, string _city, string _state, string _zip_code, string _country) : street(_street), city(_city), state(_state), zip_code(_zip_code), country(_country)
    {
    }

    friend ostream &operator<<(ostream &os, const Address &address)
    {
        return os << address.street << " street, " << address.city << " city, " << address.state << " state, " << address.country << ", zipcode: " << address.zip_code;
    }

    static Address inputAddress();
};

bool is_consist(list<int>, int);

bool is_valid_date(time_t);

time_t input_time();

void clear();

void wait();

ostream &operator<<(ostream &os, EmployeeType &Typ);
ostream &operator<<(ostream &os, const time_t &T);
ostream &operator<<(ostream &os, const SeatType &T);
ostream &operator<<(ostream &os, const OrderStatus &T);
#endif /* B7E5AD63_D675_4BF5_ADCA_80920130FD08 */
