#include "../../Header/Actor/Chef.h"
#include "../../Header/Order/Order.h"

Chef::Chef() {}
Chef::~Chef() {}

void Chef::view()
{
    int option;
    bool loop = true;
    while (loop)
    {
        int count = 1;
        clear();

        cout
            << setw(3) << left << to_string(count++) + "."
            << "Preapare order." << endl
            << setw(3) << left << to_string(count++) + "."
            << "Complete order." << endl

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
            this->prepare_order();
            break;
        case 2:
            this->complete_order();
            break;
        default:
            loop = false;
            break;
        }
    }

    return;
}

bool Chef::prepare_order()
{
    clear();
    // Order *order = Order::getOrder(Order::selectOrderId(this->getBranch_id()));
    // if (!order)
    // {
    //     cout << "in valid order id";
    //     wait();
    //     return false;
    // }
    // clear();
    // if (order->getStatus() != O_RECEIVED)
    // {
    //     cout << "Invalid action on order.";
    //     wait();
    //     return false;
    // }
    // order->setStatus(O_PREPARING);
    // cout<<"Success";
    // wait();
    return true;
}

bool Chef::complete_order()
{
    // clear();
    // Order *order = Order::getOrder(Order::selectOrderId(this->getBranch_id()));
    // if (!order)
    // {
    //     cout << "in valid order id";
    //     wait();
    //     return false;
    // }
    // clear();
    // if (order->getStatus() != O_PREPARING)
    // {
    //     cout << "Invalid action on order.";
    //     wait();
    //     return false;
    // }
    // order->setStatus(O_COMPLETED);
    // cout<<"Success";
    // wait();
    return true;
}


Chef Chef::input(int branch){
    Chef chef;
    chef.input_employee(branch);
    return chef;
}