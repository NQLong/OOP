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
        clear();
        print_option({
            "Reservation management",
            "Creat check",
            "Creat payment",
        });

        cin >> option;
        cin.ignore();
        switch (option)
        {
        case 1:
            this->reservations_manage();
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

void Receptionist::reservations_manage()
{
     ReservationManager(Storage::reservations).manage_elements(this->getBranch_id());
}

bool Receptionist::process_payment()
{
    // clear();
    // Order *order = Order::getOrder(Order::selectOrderId(this->getBranch_id()));
    // Check *check;
    // if (!order)
    // {
    //     cout << "invalid order id";
    //     wait();
    //     return false;
    // }
    // if (order->getCheckId() == -1)
    // {
    //     if (!create_order_check(order) || order->getCheckId() == -1)
    //     {
    //         cout << "invalid action";
    //         wait();
    //         return false;
    //     }
    // }

    // check = Check::get_check(order->getCheckId());
    // if (check->isPaid())
    // {
    //     cout << "Check already paid";
    //     wait();
    //     return false;
    // }
    // return check->createPayment();
    return true;
}

bool Receptionist::create_order_check(Order *_order)
{
    // clear();
    // cout << "Create check for: " << endl
    //      << endl;
    // Order *order;
    // if (!_order)
    //     order = Order::getOrder(Order::selectOrderId(this->getBranch_id()));
    // else
    //     order = _order;
    // if (!order)
    // {
    //     cout << "in valid order id";
    //     wait();
    //     return false;
    // }
    // clear();
    // if (order->getStatus() != O_COMPLETED && order->getStatus() != O_PREPARING && order->getStatus() != O_RECEIVED)
    // {
    //     cout << "Invalid action on order.";
    //     wait();
    //     return false;
    // }

    // Check check = Check::input_check(order);
    // clear();
    // check.setCheck_id(Check::getChecks()->size() > 0 ? Check::getChecks()->back().getCheck_id() + 1 : 0);
    // Check::add_check(check);
    // order->setCheckId(check.getCheck_id());
    // cout << check;
    // wait();
    // return true;
    return true;
}