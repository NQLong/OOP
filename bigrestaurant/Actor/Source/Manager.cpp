#include "../Header/Manager.h"

Manager::Manager() {}

Manager::~Manager() {}

bool Manager::add_employee()
{
    int option;
    bool loop = true;

    while (loop)
    {
        int count = 1;
        system("clear");

        cout
            << setw(3) << left << to_string(count++) + "."
            << "Add chef" << endl
            << setw(3) << left << to_string(count++) + "."
            << "Add Receptinist" << endl
            << setw(3) << left << to_string(count++) + "."
            << "Add Waiter" << endl
            << setw(3) << left << "0."
            << "Back." << endl;

        cout << endl
             << "Enter your choice: ";
        cin >> option;
        cin.ignore();
        switch (option)
        {
        
        case 1:
            return Restaurant::addEmployee(CHEF);
            break;
        case 2:
            return Restaurant::addEmployee(RECEPTIONIST);
            break;
        case 3:
            return Restaurant::addEmployee(WAITER);
            break;

        default:
            loop = false;
            break;
        }
    }

    return true;
}

bool Manager::reassign_employee() { return true; }

void Manager::view()
{
    int option;
    bool loop = true;
    while (loop)
    {
        int count = 1;
        system("clear");

        cout
            << setw(3) << left << to_string(count++) + "."
            << "Account management." << endl
            << setw(3) << left << to_string(count++) + "."
            << "Menu management." << endl
            << setw(3) << left << "0."
            << "Back." << endl;

        cout << endl
             << "Enter your choice: ";
        cin >> option;
        cin.ignore();
        switch (option)
        {
        case 1:
            this->accountManageView();
            break;
        case 2:
            this->meuManageView();
            break;

        default:
            loop = false;
            break;
        }
    }

    return;
}

void Manager::accountManageView()
{
    int option;
    bool loop = true;

    while (loop)
    {
        int count = 1;
        system("clear");

        cout
            << setw(3) << left << to_string(count++) + "."
            << "Register new account." << endl
            << setw(3) << left << to_string(count++) + "."
            << "Cancel account." << endl
            << setw(3) << left << "0."
            << "Back." << endl;

        cout << endl
             << "Enter your choice: ";
        cin >> option;
        cin.ignore();
        switch (option)
        {
        case 1:
            this->add_employee();
            break;
        case 2:
            this->cancel_employee();
            break;

        default:
            loop = false;
            break;
        }
    }

    return;
}

bool Manager::cancel_employee()
{
    int id;
    system("clear");
    cout << "account id: ";
    cin >> id;
    cin.ignore();
    Employee *user = Restaurant::getEmployee(id);
    if (!user)
    {
        cout<<"Account doesn't exist";
        wait();
    }
    user->getAccount()->setStatus(A_CANCELLED);
    cout<<"SUCCESSFUL";
    wait();
    return true;
}

void Manager::meuManageView()
{
}