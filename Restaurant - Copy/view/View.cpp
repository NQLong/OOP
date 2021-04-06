#include "View.h"

using namespace std;

View::View()
{
    this->controller = new Restaurant();
    this->dishView = new DishView(this->controller);
    this->tableView = new TableView(this->controller);
    this->waiterView = new WaiterView(this->controller);
    this->clientView = new ClientView(this->controller);
    this->ingridientView = new IngridientView(this->controller);
    this->mealView = new MealView(this->controller);
}
View::~View()
{
    delete this->controller;
    delete this->dishView;
    delete this->tableView;
    delete this->waiterView;
    delete this->clientView;
    delete this->ingridientView;
    delete this->mealView;
}
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
    // clearCin();
    getline(cin, wait);
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
    return controller;
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
        return this->ingridientView->createIngridientView();
    case 2:
        return this->dishView->createDishView();
    case 3:
        return this->tableView->createTableView();
    case 4:
        return this->waiterView->createWaiterView();
    case 5:
        return this->clientView->createClientView();
    case 6:
        return this->mealView->createMealView();
    case 7:
        this->ingridientView->listIngridientView();
        return true;
    case 8:
        this->dishView->listDishView();
        return true;
    case 9:
        this->tableView->listTableView();
        return true;
    case 10:
        this->waiterView->listWaiterView();
        return true;
    case 11:
        this->clientView->listClientView();
        return true;
    case 12:
        this->mealView->listMealView();
        return true;
    case 13:
        this->ingridientView->filterIngridientView();
        return true;
    case 14:
        this->dishView->filterDishView();
        return true;
    case 15:
        this->tableView->filterTableView();
        return true;
    case 16:
        this->waiterView->filterWaiterView();
        return true;
    case 17:
        this->clientView->filterClientView();
        return true;
    case 18:
        this->mealView->filterMealView();
        return true;

    case 19:
        this->ingridientView->deleteIngridientView();

    case 24:
        this->mealView->deleteMealView();
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
        << "\t17: Search a client"
        << "18: Search a meal" << endl;

    cout
        << endl
        << "Delete commands group:" << endl
        << setw(40) << left
        << "\t19: delete an ingridient"
        << "20: delete a dish" << endl
        << setw(40) << left
        << "\t21: delete a table"
        << "22: delete a waiter" << endl
        << setw(40) << left
        << "\t23: delete a client"
        << "24: delete a meal" << endl;

    cout
        << endl
        << "show commands panel: 0" << endl;
}
