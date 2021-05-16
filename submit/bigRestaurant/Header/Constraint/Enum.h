#ifndef D3B7ACAE_05C9_4D52_9D5F_264C3A2E2FFC
#define D3B7ACAE_05C9_4D52_9D5F_264C3A2E2FFC

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

enum EmployeeType
{
    CHEF,
    WAITER,
    RECEPTIONIST,
    MANAGER,
    ADMIN
};
ostream &operator<<(ostream &os,const EmployeeType &Typ);
EmployeeType select_employee_typ();

enum ReservationStatus
{
    R_REQUESTED,
    R_PENDING,
    R_CONFIRMED,
    R_CHECKED_IN,
    R_CANCELED,
    R_ABANDONED
};

ostream &operator<<(ostream &os,const ReservationStatus &Typ);
ReservationStatus select_reservation_status();

enum SeatType
{
    S_REGULAR,
    S_KID,
    S_ACCESSIBLE,
    S_OTHER
};

ostream &operator<<(ostream &os,const SeatType &e);
SeatType select_seat_type();

enum OrderStatus
{
    O_RECEIVED,
    O_PREPARING,
    O_COMPLETED,
    O_CANCELED,
    O_NONE
};
ostream &operator<<(ostream &os,const OrderStatus &e);
OrderStatus select_order_status();

enum TableStatus
{
    T_FREE,
    T_RESERVED,
    T_OCCUPIED,
    T_OTHER
};

ostream &operator<<(ostream &os,const TableStatus &e);
TableStatus select_table_status();

enum AccountStatus
{
    A_ACTIVE,
    A_CLOSED,
    A_CANCELLED,
    A_BLACKLISTED,
    A_BLOCKED
};
ostream &operator<<(ostream &os,const AccountStatus &e);
AccountStatus select_account_status();

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
ostream &operator<<(ostream &os,const PaymentStatus &e);
PaymentStatus select_payment_status();

enum PaymentType
{
    P_CARD,
    P_CHECK,
    P_CASH
};
ostream &operator<<(ostream &os,const PaymentType &e);
PaymentType select_payment_type();

#endif /* D3B7ACAE_05C9_4D52_9D5F_264C3A2E2FFC */
