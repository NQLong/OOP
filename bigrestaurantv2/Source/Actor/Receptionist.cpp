#include "../../Header/Actor/Receptionist.h"
#include "../../Header/Reservation/Reservation.h"
#include "../../Header/Check/Check.h"

Receptionist::Receptionist() {}
Receptionist::~Receptionist() {}

void Receptionist::view()
{
    int option;
    bool loop = true;

    while (loop)
    {
        int count = 1;
        system("clear");

        cout
            << setw(3) << left << to_string(count++) + "."
            << "Creat Reservation." << endl
            << setw(3) << left << to_string(count++) + "."
            << "Create check." << endl
            << setw(3) << left << to_string(count++) + "."
            << "process payment." << endl
            // << setw(3) << left << to_string(count++) + "."
            // << "view menu." << endl

            << endl
            << setw(3) << left << "0."
            << "Back." << endl;

        cout << endl
             << "Enter your choice: ";
        cin >> option;
        cin.ignore();
        switch (option)
        {
        case 1:
            this->create_reservation();
            break;
        case 2:
            this->create_order_check(NULL);
            break;
        case 3:
            this->process_payment();
            break;

        default:
            loop = false;
            break;
        }
    }

    return;
}

bool Receptionist::create_reservation()
{
    system("clear");
    Reservation r = Reservation::input_reservation(this->getBranch_id());
    r.setReservation_id(
        Reservation::getReservations()->size() > 0
            ? Reservation::getReservations()->back().getReservation_id() + 1
            : 0);
    Reservation::add_reservation(r);
    wait();
    return true;
}

bool Receptionist::process_payment()
{
    system("clear");
    Order *order = Order::getOrder(Order::selectOrderId(this->getBranch_id()));
    Check *check;
    if (!order)
    {
        cout << "invalid order id";
        wait();
        return false;
    }
    if (order->getCheckId() == -1)
    {
        if (!create_order_check(order) || order->getCheckId() == -1)
        {
            cout << "invalid action";
            wait();
            return false;
        }
    }

    check = Check::get_check(order->getCheckId());
    if (check->isPaid())
    {
        cout << "Check already paid";
        wait();
        return false;
    }
    return check->createPayment();
}

bool Receptionist::create_order_check(Order *_order)
{
    system("clear");
    cout << "Create check for: " << endl
         << endl;
    Order *order;
    if (!_order)
        order = Order::getOrder(Order::selectOrderId(this->getBranch_id()));
    else
        order = _order;
    if (!order)
    {
        cout << "in valid order id";
        wait();
        return false;
    }
    system("clear");
    if (order->getStatus() != O_COMPLETED && order->getStatus() != O_PREPARING && order->getStatus() != O_RECEIVED)
    {
        cout << "Invalid action on order.";
        wait();
        return false;
    }

    Check check = Check::input_check(order);
    system("clear");
    check.setCheck_id(Check::getChecks()->size() > 0 ? Check::getChecks()->back().getCheck_id() + 1 : 0);
    Check::add_check(check);
    order->setCheckId(check.getCheck_id());
    cout << check;
    wait();
    return true;
}