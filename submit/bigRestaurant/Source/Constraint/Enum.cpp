#include "../../Header/Constraint/Enum.h"
#include "../../Header/Constraint/Constraint.h"

ostream &operator<<(ostream &os, const EmployeeType &l)
{

    switch (l)
    {
    case CHEF:
        return os << "Chef";
    case WAITER:
        return os << "Waiter";
    case RECEPTIONIST:
        return os << "Receptionist";
    case MANAGER:
        return os << "Manager";
    case ADMIN:
        return os << "Admin";
    }
    return os;
}

EmployeeType select_employee_typ()
{
    cout << "Select type" << endl
         << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << setw(3) << left << to_string(i + 1) + "." << (EmployeeType)i << endl;
    }
    cout << endl
         << "Choose type: ";
    int state;
    cin >> state;
    cin.ignore();
    if (state > 5 || state < 1)
    {
        cout << "invalid option, try again";
        wait();
        clear();
        return select_employee_typ();
    }
    return (EmployeeType)(state - 1);
}

ostream &operator<<(ostream &os, const ReservationStatus &l)
{

    switch (l)
    {
    // case R_REQUESTED:
    //     return os << "Requested";
    case R_PENDING:
        return os << "Pending";
    case R_CONFIRMED:
        return os << "Confirmed";
    case R_CHECKED_IN:
        return os << "Checked in";
    case R_CANCELED:
        return os << "Canceled";
    case R_ABANDONED:
        return os << "Abandoned";
    }
    return os;
}

ReservationStatus select_reservation_status()
{
    cout << "Select stat" << endl
         << endl;
    for (int i = 0; i < 6; i++)
    {
        cout << setw(3) << left << to_string(i + 1) + "." << (ReservationStatus)i << endl;
    }
    cout << endl
         << "Choose stat: ";
    int state;
    cin >> state;
    cin.ignore();
    if (state > 6 || state < 1)
    {
        cout << "invalid option, try again";
        wait();
        clear();
        return select_reservation_status();
    }
    return (ReservationStatus)(state - 1);
}

ostream &operator<<(ostream &os, const SeatType &l)
{

    switch (l)
    {
    case S_REGULAR:
        return os << "Regular";
    case S_KID:
        return os << "Kid";
    case S_ACCESSIBLE:
        return os << "Accessible";
    case S_OTHER:
        return os << "Other";
    }
    return os;
}

SeatType select_seat_type()
{
    cout << "Select seat type" << endl
         << endl;
    for (int i = 0; i < 4; i++)
    {
        cout << setw(3) << left << to_string(i + 1) + "." << (SeatType)i << endl;
    }
    cout << endl
         << "Choose type: ";
    int state;
    cin >> state;
    cin.ignore();
    if (state > 4 || state < 1)
    {
        cout << "invalid option, try again";
        wait();
        clear();
        return select_seat_type();
    }
    return (SeatType)(state - 1);
}

ostream &operator<<(ostream &os, const OrderStatus &l)
{

    switch (l)
    {
    case O_RECEIVED:
        return os << "Received";
    case O_PREPARING:
        return os << "Preparing";
    case O_COMPLETED:
        return os << "Completed";
    case O_CANCELED:
        return os << "Canceled";
    case O_NONE:
        return os << "None";
    }
    return os;
}

OrderStatus select_order_status()
{
    cout << "Select stat" << endl
         << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << setw(3) << left << to_string(i + 1) + "." << (OrderStatus)i << endl;
    }
    cout << endl
         << "Choose type: ";
    int state;
    cin >> state;
    cin.ignore();
    if (state > 5 || state < 1)
    {
        cout << "invalid option, try again";
        wait();
        clear();
        return select_order_status();
    }
    return (OrderStatus)(state - 1);
}

ostream &operator<<(ostream &os, const TableStatus &l)
{

    switch (l)
    {
    case T_FREE:
        return os << "Free";
    case T_RESERVED:
        return os << "Reserved";
    case T_OCCUPIED:
        return os << "Occupied";
    case T_OTHER:
        return os << "Other";
    }
    return os;
}

TableStatus select_table_status()
{
    cout << "Select stat" << endl
         << endl;
    for (int i = 0; i < 4; i++)
    {
        cout << setw(3) << left << to_string(i + 1) + "." << (TableStatus)i << endl;
    }
    cout << endl
         << "Choose stat: ";
    int state;
    cin >> state;
    cin.ignore();
    if (state > 4 || state < 1)
    {
        cout << "invalid option, try again";
        wait();
        clear();
        return select_table_status();
    }
    return (TableStatus)(state - 1);
}

ostream &operator<<(ostream &os, const AccountStatus &l)
{

    switch (l)
    {
    case A_ACTIVE:
        return os << "Active";
    case A_CLOSED:
        return os << "Closed";
    case A_CANCELLED:
        return os << "Cancelled";
    case A_BLACKLISTED:
        return os << "Blacklisted";
    case A_BLOCKED:
        return os << "Blocked";
    }
    return os;
}

AccountStatus select_account_status()
{
    cout << "Select stat" << endl
         << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << setw(3) << left << to_string(i + 1) + "." << (AccountStatus)i << endl;
    }
    cout << endl
         << "Choose stat: ";
    int state;
    cin >> state;
    cin.ignore();
    if (state > 5 || state < 1)
    {
        cout << "invalid option, try again";
        wait();
        clear();
        return select_account_status();
    }
    return (AccountStatus)(state - 1);
}

ostream &operator<<(ostream &os, const PaymentStatus &l)
{

    switch (l)
    {
    case P_UNPAID:
        return os << "Unpaid";
    case P_PENDING:
        return os << "Pending";
    case P_COMPLETED:
        return os << "Completed";
    case P_FILLED:
        return os << "Filled";
    case P_DECLINED:
        return os << "Declined";
    case P_CANCELLED:
        return os << "Cancelled";
    case P_ABANDONED:
        return os << "Abandoned";
    case P_SETTLING:
        return os << "Settling";
    case P_SETTLED:
        return os << "Settled";
    case P_REFUNDED:
        return os << "Refunded";
    }
    return os;
}

PaymentStatus select_payment_status()
{
    cout << "Select stat" << endl
         << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << setw(3) << left << to_string(i + 1) + "." << (PaymentStatus)i << endl;
    }
    cout << endl
         << "Choose stat: ";
    int state;
    cin >> state;
    cin.ignore();
    if (state > 10 || state < 1)
    {
        cout << "invalid option, try again";
        wait();
        clear();
        return select_payment_status();
    }
    return (PaymentStatus)(state - 1);
}

ostream &operator<<(ostream &os, const PaymentType &l)
{

    switch (l)
    {
    case P_CARD:
        return os << "Card";
    case P_CHECK:
        return os << "Check";
    case P_CASH:
        return os << "Cash";
    }
    return os;
}

PaymentType select_payment_type()
{
    cout << "Select type" << endl
         << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << setw(3) << left << to_string(i + 1) + "." << (PaymentType)i << endl;
    }
    cout << endl
         << "Choose type: ";
    int state;
    cin >> state;
    cin.ignore();
    if (state > 3 || state < 1)
    {
        cout << "invalid option, try again";
        wait();
        clear();
        return select_payment_type();
    }
    return (PaymentType)(state - 1);
}
