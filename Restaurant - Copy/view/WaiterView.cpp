#include "WaiterView.h"

WaiterView::WaiterView() {}

WaiterView::WaiterView(Restaurant *controller) : GeneralView(controller) {}

void WaiterView::DetailView(Waiter *ptr)
{
    cout << setw(5) << "" << setw(20) << "Waiter's id: " << ptr->getId() << endl;
    cout << setw(5) << "" << setw(20) << "Waiter's name: " << ptr->getName() << endl;
    cout << setw(5) << "" << setw(20) << "Waiter's Address: " << ptr->getAddress() << endl;
    cout << setw(5) << "" << setw(20) << "Waiter's phone: " << ptr->getPhoneNumber() << endl;
}

bool WaiterView::createWaiterView()
{
    Waiter *waiter_ptr;
    string name, address, phone;
    int id;

    cout << "Create Waiter : " << endl;

    while (true)
    {
        cout << "id : ";
        cin >> id;
        waiter_ptr = this->controller->filterWaiter(id);
        if (waiter_ptr != NULL)
        {
            cout << "id already exist, choose other please!" << endl;
        }
        else
            break;
    }

    clearCin();
    cout << "name :";
    getline(cin, name);
    cout << "address";
    getline(cin, address);
    cout << "phone :";
    getline(cin, phone);

    waiter_ptr = new Waiter(id, name, address, phone);
    this->controller->addWaiter(waiter_ptr);

    cout << "Successfully created waiter " << waiter_ptr->toString();
    return true;
}

void WaiterView::listWaiterView()
{

    vector<Waiter *> list = this->controller->getWaiterList();
    vector<Waiter *>::iterator it = list.begin();
    int count = 0;
    cout << "Waiter list: " << endl;
    for (it = it; it != list.end(); it++)
    {
        cout << ++count << "." << endl;
        this->DetailView(*it);
    }
}

void WaiterView::filterWaiterView()
{
    string name;
    Waiter *ptr;

    cout << "Seacrch a Waiter" << endl;
    cout << "Waiter name: ";
    // clearCin();
    getline(cin, name);
    cout << "Result :" << endl;
    ptr = this->controller->filterWaiter(name);

    if (!ptr)
        cout << setw(5) << "No result found";
    else
        this->DetailView(ptr);
}
