#include "../../Header/Actor/Waiter.h"

Waiter::Waiter() {}
Waiter::~Waiter() {}

void Waiter::view()
{
    int option;
    bool loop = true;

    while (loop)
    {
        int count = 1;
        clear();

        cout
            << setw(3) << left << to_string(count++) + "."
            << "place order." << endl
            << setw(3) << left << to_string(count++) + "."
            << "view order." << endl
            << setw(3) << left << to_string(count++) + "."
            << "view menu." << endl

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
            this->placeOrder();
            break;
        case 2:
            this->viewOrder();
            break;
        case 3:
            this->printMenu();
            break;

        default:
            loop = false;
            break;
        }
    }

    return;
}

bool Waiter::placeOrder()
{
    clear();
    cout << "Place an order:" << endl;
    Order order = Order::inputOrder(this->getBranch_id(), this->getEmployee_id());
    order.setOrder_id(Order::getOrders()->size() > 0?Order::getOrders()->back().getOrder_id() + 1: 0);
    Order::add_order(order);
    return true;
}

void Waiter::viewOrder()
{
    clear();
    Order *order = Order::getOrder(Order::selectOrderId(this->getBranch_id()));
    if (!order)
    {
        cout << "in valid order id";
        wait();
        return;
    }
    clear();
    cout << *order;
    wait();
    return;
}
