#include "../../Header/Actor/Admin.h"

Admin::Admin() {}
Admin::~Admin()
{
}

void Admin::view()
{
    int option;
    bool loop = true;
    while (loop)
    {
        int count = 1;
        clear();

        cout
            << setw(3) << left << to_string(count++) + "."
            << "Manager management." << endl
            << setw(3) << left << to_string(count++) + "."
            << "Branch management." << endl
            << setw(3) << left << "0."
            << "Back." << endl;

        cout << endl
             << "Enter your choice: ";
        cin >> option;
        cin.ignore();
        switch (option)
        {
        case 1:
            this->managerManage();
            break;
        case 2:
            this->branchManage();
            break;

        default:
            loop = false;
            break;
        }
    }

    return;
}

bool Admin::addBranch()
{
    clear();
    return Restaurant::addBranch();
}

bool Admin::removeBranch()
{
    // return Restaurant::addBranch();
    return true;
}

void Admin::branchManage()
{
    int option;
    bool loop = true;

    while (loop)
    {
        int count = 1;
        
        clear();

        cout
            << setw(3) << left << to_string(count++) + "."
            << "Register new branch." << endl
            << setw(3) << left << to_string(count++) + "."
            << "Remove a branch." << endl
            << setw(3) << left << "0."
            << "Back." << endl;

        cout << endl
             << "Enter your choice: ";
        cin >> option;
        cin.ignore();
        switch (option)
        {
        case 1:
            this->addBranch();
            break;
        case 2:
            this->removeBranch();
            break;

        default:
            loop = false;
            break;
        }
    }

    return;
}

void Admin::managerManage()
{
    int option;
    bool loop = true;

    while (loop)
    {
        int count = 1;
        clear();

        cout
            << setw(3) << left << to_string(count++) + "."
            << "Register new manager." << endl
            << setw(3) << left << to_string(count++) + "."
            << "Remove a manager." << endl
            << setw(3) << left << to_string(count++) + "."
            << "Assign a manager to a branch." << endl
            << setw(3) << left << "0."
            << "Back." << endl;

        cout << endl
             << "Enter your choice: ";
        cin >> option;
        cin.ignore();
        switch (option)
        {
        case 1:
            this->addManager();
            break;
        case 2:
            this->removeManager();
            break;
        case 3:
            this->assignManager();
            break;

        default:
            loop = false;
            break;
        }
    }

    return;
}

bool Admin::removeManager()
{
    int id;
    clear();
    cout << "account id: ";
    cin >> id;
    cin.ignore();
    Employee *user = Restaurant::getEmployee(id);
    if (!user)
    {
        cout << "Account doesn't exist";
        wait();
    }
    user->getAccount()->setStatus(A_CANCELLED);
    cout << "SUCCESSFUL";
    wait();
    return true;
}

bool Admin::addManager()
{
    clear();
    return Restaurant::addEmployee(MANAGER,-1);
}

bool Admin::assignManager()
{
    clear();

    int id;
    int branch_id;

    cout << "Manager id: ";
    cin >> id;
    cout << "Branch id: ";
    cin >> branch_id;
    cin.ignore();

    Actor *manager = Restaurant::getEmployee(id);
    if (!manager || manager->getTyp()!= MANAGER)
    {
        cout << "Invalid id";
        wait();
    }

    else if (!Restaurant::getBranch(branch_id)){
        cout<<"invalid branch id";
        wait();
    }
    
    manager->setBranch_id(branch_id);
    cout<<manager->getBranch_id();
    cout<<"Success";
    wait();
    return true;
        
}