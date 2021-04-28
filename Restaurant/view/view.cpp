#include "view.h"

using namespace std;

void clearCin()
{
    cin.clear();
    cin.ignore(10000, '\n');
}

View::View() {}

void View::startApp()
{
    bool loop = true;
    string wait;

    //clear the screen
    system("clear");

    //print the command panel
    this->commandsView();

    //wait the user to start the app
    cout << "Press Enter to start the app";
    clearCin();
    // getline(cin, wait);
    system("clear");

    //start looping for reading user option
    while (loop)
    {
        loop = this->mainView();
        // clearCin();
        getline(cin, wait);
        system("clear");
    }
}

Restaurant *View::getRestaurant()
{
    return &restaurant;
}

bool View::mainView()
{
    int option;
    string wait;
    cout << "input your command: ";
    cin >> option;
    clearCin();
    switch (option)
    {
    case 0:
        this->commandsView();
        break;
    case 1:
        return this->createIngridientView();
    case 2:
        return this->createDishView();
    case 3:
        return this->createTableView();
    case 4:
        return this->createWaiterView();
    case 5:
        return this->createClientView();
    case 6:
        return this->createMealView();
    case 7:
        this->listIngridientView();
        return true;
    case 8:
        this->listDishView();
        return true;
    case 9:
        this->listTableView();
        return true;
    case 10:
        this->listWaiterView();
        return true;
    case 11:
        this->listClientView();
        return true;
    case 12:
        this->listMealView();
        return true;
    case 13:
        this->filterIngridientView();
        return true;
    case 14:
        this->filterDishView();
        return true;
    case 15:
        this->filterTableView();
        return true;
    case 16:
        this->filterWaiterView();
        return true;
    case 17:
        this->filterClientView();
        return true;
    default:
        return false;
        break;
    }
    return true;
}

void View::commandsView()
{
    cout
        << "Creating group command: " << endl
        << setw(40) << left
        << "\t1: Create a Ingridient"
        << "2: Create a Dish" << endl
        << setw(40) << left
        << "\t3: Create a Table"
        << "4: Create a Waiter" << endl
        << setw(40) << left
        << "\t5: Create a Client"
        << "6: Create a Meal" << endl;

    cout
        << endl
        << "listing commands group:" << endl
        << setw(40) << left
        << "\t7: list all ingridients"
        << "8: list all dishes" << endl
        << setw(40) << left
        << "\t9: list all tables"
        << "10: list all waiters" << endl
        << setw(40) << left
        << "\t11: list all clients"
        << "12: list all meals" << endl;

    cout
        << endl
        << "Searching commands group:" << endl
        << setw(40) << left
        << "\t13: Search an ingridient"
        << "14: Search a dish" << endl
        << setw(40) << left
        << "\t15: Search a table"
        << "16: Search a waiter" << endl
        << setw(40) << left
        << "\t17: Search a client" << endl;
    // << "12: Search a meal" << endl;

    cout
        << endl
        << "show commands panel: 0" << endl;
}

bool View::createIngridientView()
{
    bool success = false;
    int res;
    string name, mUnit, choice;
    double stock;
    while (!success)
    {
        cout << "Creating Ingridient" << endl;
        cout << "name :";
        getline(cin, name);

        cout << "measure unit : ";
        getline(cin, mUnit);
        // getline(cin, mUnit);
        cout << "stock: ";
        cin >> stock;
        clearCin();
        res = this->restaurant.createIngridient(name, mUnit, stock);
        if (res != this->restaurant.SUCCESS)
        {
            cout << "some thing went wrong, try again?(Y/N) ";
            getline(cin, choice);
            success = choice == "Y" ? false : true;
            if (success)
                cout << "abort create ingridient" << endl;
            return true;
        }
        else
        {
            success = true;
            cout << "Ingridient created successfully\n";
        }
    }

    return true;
}

bool View::createDishView()
{
    bool success = false;
    string name, ingriName, choice;
    int id, nIngridient;
    double quantity;
    vector<double> neededQuantity;
    vector<string> ingridients;
    int res;
    while (!success)
    {
        cout << "Creating Dish" << endl;
        cout << "id : ";
        cin >> id;
        clearCin();
        cout << "name :";
        getline(cin, name);
        cout << "numer of in gridient :";
        cin >> nIngridient;
        for (int i = 0; i < nIngridient; i++)
        {
            clearCin();
            cout << "Ingridient 's name :";
            getline(cin, ingriName);
            cout << "needed quantity : ";
            cin >> quantity;
            clearCin();
            ingridients.insert(ingridients.end(), ingriName);
            neededQuantity.insert(neededQuantity.end(), quantity);
        }
        res = this->restaurant.createDish(id, name, ingridients, neededQuantity);
        if (res == this->restaurant.SUCCESS)
            success = true;
        else if (res == this->restaurant.EXISTING_OBJECT)
        {
            cout << "id or name existed" << endl;
        }
        else if (res == this->restaurant.NON_EXISTING_DEPENDENCIES)
            cout << "one or some ingridient don't exist." << endl;
        if (!success)
        {
            cout << "try again?(Y/N) ";

            getline(cin, choice);
            success = choice == "Y" ? false : true;
            if (success)
                cout << "abort create dish";
        }
        else
            cout << "dish created successfully";
    }
    return true;
}

bool View::createTableView()
{
    int id, capacity;
    Table *table_ptr;

    cout << "Create table:" << endl;
    cout << "id : ";
    cin >> id;
    cout << "max capacity : ";
    cin >> capacity;
    table_ptr = new Table(id, capacity);
    this->restaurant.addTable(table_ptr);
    cout << "Successful create table " << table_ptr->toString() << endl;
    return true;
}

bool View::createWaiterView()
{
    Waiter *waiter_ptr;
    string name, address, phone;
    int id;

    cout << "Create Waiter : " << endl;

    while (true)
    {
        cout << "id : ";
        cin >> id;
        waiter_ptr = this->restaurant.filterWaiter(id);
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
    this->restaurant.addWaiter(waiter_ptr);

    cout << "Successfully created waiter " << waiter_ptr->toString();
    return true;
}

bool View::createClientView()
{
    Client *client_ptr;
    string name, address, taxId;

    cout << "Create Client : " << endl;

    cout << "name :";
    getline(cin, name);
    cout << "address";
    getline(cin, address);
    cout << "taxId :";
    getline(cin, taxId);

    client_ptr = new Client(name, address, taxId);
    this->restaurant.addClient(client_ptr);

    cout << "Successfully created client " << client_ptr->toString();
    return true;
}

bool View::createMealView()
{
    vector<string> listOfName;
    vector<int> listOfQuantity;

    bool success = false;
    int res;
    int tableId, waiterId, nDish, quantity, date, start, end;
    string clientName, dishName, choice;

    while (!success)
    {
        //IO phase
        cout << "Create Meal :" << endl;
        cout << "table id : ";
        cin >> tableId;
        cout << "waiter id : ";
        cin >> waiterId;
        cout << "Client name : ";
        clearCin();
        getline(cin, clientName);
        // cout << clientName << endl;
        cout << "date :";
        cin >> date;
        cout << "start :";
        cin >> start;
        cout << "end :";
        cin >> end;
        cout << " number of Dishes: ";
        cin >> nDish;
        clearCin();

        for (int i = 0; i < nDish; i++)
        {
            cout << "dish no." << i << " 's name :";
            getline(cin, dishName);
            // cout << dishName << endl;
            cout << "quantity : ";
            cin >> quantity;
            clearCin();
            listOfName.insert(listOfName.end(), dishName);
            listOfQuantity.insert(listOfQuantity.end(), quantity);
        }

        //send create
        res = this->restaurant.createMeal(tableId, waiterId, clientName, date,
                                          start, end, listOfName, listOfQuantity);

        //process response
        if (res == this->restaurant.SUCCESS)
            success = true;
        // else if (res == this->restaurant.EXISTING_OBJECT)
        // {
        //     cout << "id or name existed" << endl;
        // }
        else if (res == this->restaurant.NON_EXISTING_DEPENDENCIES)
            cout << "table or waiter or client or some dish don't exist." << endl;
        if (!success)
        {
            cout << "try again?(Y/N) ";

            getline(cin, choice);
            success = choice == "Y" ? false : true;
            if (success)
                cout << "abort create meal";
        }
        else
            cout << "meal created successfully";
    }

    return true;
}

void View::listIngridientView()
{
    cout << "Ingridients list: " << endl;
    vector<Ingridient *> list = this->restaurant.getIngridientList();
    int count = 0;
    for (vector<Ingridient *>::iterator it = list.begin(); it != list.end(); it++)
    {
        cout << ++count << "." << endl;
        this->IngridientView(*it);
    }
}

void View::listDishView()
{
    cout << "Dishes list: " << endl;
    vector<Dish *> list = this->restaurant.getDishList();
    int count = 0;
    for (vector<Dish *>::iterator it = list.begin(); it != list.end(); it++)
    {
        cout << ++count << "." << endl;
        this->DishView(*it);
    }
}

void View::listTableView()
{
    vector<Table *> list = this->restaurant.getTableList();
    vector<Table *>::iterator it = list.begin();
    int count = 0;
    cout << "table list: " << endl;
    for (it = it; it != list.end(); it++)
    {
        cout << ++count << "." << endl;
        this->TableView(*it);
    }
}

void View::listClientView()
{
    vector<Client *> list = this->restaurant.getClientList();
    vector<Client *>::iterator it = list.begin();
    int count = 0;
    cout << "Client list: " << endl;
    for (it = it; it != list.end(); it++)
    {
        cout << ++count << "." << endl;
        this->ClientView(*it);
    }
}

void View::listMealView()
{
    vector<Meal *> list = this->restaurant.getMealList();
    int count = 0;
    cout << "Meal list :" << endl;

    for (vector<Meal *>::iterator it = list.begin(); it != list.end(); it++)
    {
        cout << ++count << ".\n";
        this->MealView(*it);
    }
}

void View::listWaiterView()
{

    vector<Waiter *> list = this->restaurant.getWaiterList();
    vector<Waiter *>::iterator it = list.begin();
    int count = 0;
    cout << "Waiter list: " << endl;
    for (it = it; it != list.end(); it++)
    {
        cout << ++count << "." << endl;
        this->WaiterView(*it);
    }
}

void View::IngridientView(Ingridient *ptr)
{
    cout << setw(5) << "" << setw(10) << "name :" << ptr->getName() << endl;
    cout << setw(5) << "" << setw(10) << "Stock :" << ptr->getQuantity() << " "
         << "(" << ptr->getMeasureUnit() << ")" << endl;
}

void View::filterIngridientView()
{
    string name;
    Ingridient *ingridient_ptr;

    cout << "Seacrch a Ingridient" << endl;
    cout << "Ingridient name: ";
    // clearCin();
    getline(cin, name);
    ingridient_ptr = this->restaurant.filterIngridient(name);

    if (!ingridient_ptr)
        cout << setw(5) << "No result found";
    else
        this->IngridientView(ingridient_ptr);
}

void View::filterDishView()
{
    string name;
    Dish *dish_ptr;

    cout << "Seacrch a Dish" << endl;
    cout << "Dish name: ";
    // clearCin();
    getline(cin, name);
    dish_ptr = this->restaurant.filterDish(name);

    if (!dish_ptr)
        cout << setw(5) << "No result found";
    else
        this->DishView(dish_ptr);
}

void View::filterTableView()
{
    int id;
    Table *table_ptr;

    cout
        << "Search for a table: " << endl
        << "Input table id :";
    cin >> id;
    table_ptr = this->restaurant.filterTable(id);
    if (!table_ptr)
        cout << "no result found";
    else
        this->TableView(table_ptr);
}

void View::filterClientView()
{
    string name;
    Client *ptr;

    cout << "Seacrch a Client" << endl;
    cout << "Client name: ";
    // clearCin();
    getline(cin, name);
    cout << "Result :" << endl;
    ptr = this->restaurant.filterClient(name);

    if (!ptr)
        cout << setw(5) << "No result found";
    else
        this->ClientView(ptr);
}

void View::filterWaiterView()
{
    string name;
    Waiter *ptr;

    cout << "Seacrch a Waiter" << endl;
    cout << "Waiter name: ";
    // clearCin();
    getline(cin, name);
    cout << "Result :" << endl;
    ptr = this->restaurant.filterWaiter(name);

    if (!ptr)
        cout << setw(5) << "No result found";
    else
        this->WaiterView(ptr);
}

void View::DishView(Dish *ptr)
{
    cout << setw(5) << "" << setw(20) << "id :" << ptr->getId() << endl;
    cout << setw(5) << "" << setw(20) << "name :" << ptr->getName() << endl;
    cout << setw(5) << "" << setw(20) << "Ingridient needed :" << endl;
    vector<IngridientQuantity> ingriList = ptr->getIngriList();
    int count2 = 0;
    for (vector<IngridientQuantity>::iterator it2 = ingriList.begin(); it2 != ingriList.end(); it2++)
    {
        cout << setw(8) << "" << ++count2 << ". "
             << it2->getQuantity()
             << "(" << it2->getIngri()->getMeasureUnit() << ") "
             << it2->getIngri()->getName()
             << endl;
    }
}

void View::TableView(Table *ptr)
{
    cout << setw(5) << "" << setw(20) << "Table's id: " << ptr->getId() << endl;
    cout << setw(5) << "" << setw(20) << "Table's capcity: " << ptr->getMaxCapacity() << endl;
}

void View::ClientView(Client *ptr)
{
    cout << setw(5) << "" << setw(20) << "Client's name: " << ptr->getName() << endl;
    cout << setw(5) << "" << setw(20) << "Client's Address: " << ptr->getAddress() << endl;
    cout << setw(5) << "" << setw(20) << "Client's taxId: " << ptr->getTaxID() << endl;
}

void View::MealView(Meal *ptr)
{
    cout
        << setw(5) << ""
        << "Table's id : " << ptr->getTable()->getId() << endl
        << setw(5) << ""
        << "date : " << ptr->getDate() << endl
        << setw(5) << ""
        << "start : " << ptr->getStart() << endl
        << setw(5) << ""
        << "end : " << ptr->getEnd() << endl
        << setw(5) << ""
        << "waiter : " << ptr->getWaiter()->getName() << endl
        << setw(5) << ""
        << "client : " << ptr->getClient()->getName() << endl
        << setw(5) << ""
        << "Dishes : " << endl;

    int count2 = 0;
    vector<ServedDish> list2 = ptr->getDishes();
    vector<ServedDish>::iterator it2 = list2.begin();
    for (it2 = it2; it2 != list2.end(); it2++)
    {
        cout
            << setw(8) << "" << ++count2 << ". "
            << (it2)->getQuantity() << " "
            << (it2)->getDish()->getName()
            << endl;
    }
}

void View::WaiterView(Waiter *ptr)
{
    cout << setw(5) << "" << setw(20) << "Waiter's id: " << ptr->getId() << endl;
    cout << setw(5) << "" << setw(20) << "Waiter's name: " << ptr->getName() << endl;
    cout << setw(5) << "" << setw(20) << "Waiter's Address: " << ptr->getAddress() << endl;
    cout << setw(5) << "" << setw(20) << "Waiter's phone: " << ptr->getPhoneNumber() << endl;
}

void View::editIngridientView()
{
    Ingridient *ingridient;
    string name;
    string measureUnit;
    double stock;

    cout << "Ingridient 's name: ";
    cin >> name;
    ingridient = this->restaurant.filterIngridient(name);
    if (!ingridient)
    {
        cout << "ingridient doesn's exist.";
        return;
    }
    cout << "new name :";
    cin >> name;
    cout << "new measureUnit : ";
    cin >> measureUnit;
    cout << "new Stock : ";
    cin >> stock;
    int res = this->restaurant.editIngridient(ingridient, name, measureUnit, stock);
    cout << (res == this->restaurant.SUCCESS ? "SUCCESS" : "FAIL");
}

void View::deleteIngridientView()
{
    Ingridient *ingridient;
    string name;
    string confirm;

    cout << "Ingridient 's name: ";
    cin >> name;
    // ingridient = this->restaurant.filterIngridient(name);
    cout<<"Deleting confirmation?(Y/N)";
    cin >> confirm;
    if (confirm !="Y") return;
    else {
        this -> restaurant.deleteIngridient(name);
    }
}