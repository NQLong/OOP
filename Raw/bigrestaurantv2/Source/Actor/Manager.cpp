#include "../../Header/Actor/Manager.h"

Manager::Manager() {}

Manager::~Manager() {}

void Manager::view()
{
    int option;
    bool loop = true;
    while (loop)
    {
        int count = 1;
        clear();

        cout
            << setw(3) << left << to_string(count++) + "."
            << "Account management." << endl
            << setw(3) << left << to_string(count++) + "."
            << "Menu management." << endl
            << setw(3) << left << to_string(count++) + "."
            << "Table management." << endl
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
            this->accountManageView();
            break;
        case 2:
            this->meuManageView();
            break;
        case 3:
            this->tableManagerView();
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
        clear();

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

bool Manager::add_employee()
{
    int option;
    bool loop = true;

    while (loop)
    {
        int count = 1;
        clear();

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
            return Restaurant::addEmployee(CHEF, this->getBranch_id());
            break;
        case 2:
            return Restaurant::addEmployee(RECEPTIONIST, this->getBranch_id());
            break;
        case 3:
            return Restaurant::addEmployee(WAITER, this->getBranch_id());
            break;

        default:
            loop = false;
            break;
        }
    }

    return true;
}

bool Manager::reassign_employee()
{
    return true;
}

bool Manager::cancel_employee()
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

void Manager::meuManageView()
{
    int option;
    bool loop = true;

    while (loop)
    {
        int count = 1;
        clear();

        cout
            << setw(3) << left << to_string(count++) + "."
            << "Add menu." << endl
            << setw(3) << left << to_string(count++) + "."
            << "Modify menu." << endl
            << setw(3) << left << to_string(count++) + "."
            << "print menu." << endl
            << setw(3) << left << "0."
            << "Back." << endl;

        cout << endl
             << "Enter your choice: ";
        cin >> option;
        cin.ignore();
        switch (option)
        {
        case 1:
            this->add_menu();
            break;
        case 2:
            this->modify_menu();
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

bool Manager::add_menu()
{
    clear();
    Branch *branch = Restaurant::getBranch(this->getBranch_id());
    if (!branch)
    {
        cout << "Your branch doesn't exist";
        wait();
        return false;
    }

    return branch->addMenu();
}

bool Manager::modify_menu()
{
    clear();
    Branch *branch = Restaurant::getBranch(this->getBranch_id());
    if (!branch)
    {
        cout << "Your branch doesn't exist";
        wait();
        return false;
    }
    return branch->modify_menu();
}

void Manager::tableManagerView()
{
    int option;
    bool loop = true;

    while (loop)
    {
        int count = 1;
        clear();

        cout
            << setw(3) << left << to_string(count++) + "."
            << "Add table." << endl
            << setw(3) << left << to_string(count++) + "."
            << "Modify table." << endl

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
            this->add_table();
            break;
        case 2:
            this->modify_table();
            break;
        default:
            loop = false;
            break;
        }
    }

    return;
}

bool Manager::add_table()
{
    clear();
    Table table = Table::inputTable(this->getBranch_id());
    int id = Table::getTables()->size() > 0 ? Table::getTables()->back().getTable_id() + 1 : 0;
    table.setTable_id(id);
    return Table::addTable(table);
}

bool Manager::modify_table()
{
    clear();
    int table_id = Table::selectTableId(this->getBranch_id());
    Table *table = Table::getTable(table_id);
    return table->modify_table();
}