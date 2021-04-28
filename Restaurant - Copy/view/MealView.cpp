#include "MealView.h"

MealView::MealView() {}

MealView::MealView(Restaurant *controller) : GeneralView(controller) {}

bool MealView::createMealView()
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
        res = this->controller->createMeal(tableId, waiterId, clientName, date,
                                           start, end, listOfName, listOfQuantity);

        //process response
        if (res == this->controller->SUCCESS)
            success = true;
        // else if (res == this->controller->EXISTING_OBJECT)
        // {
        //     cout << "id or name existed" << endl;
        // }
        else if (res == this->controller->NON_EXISTING_DEPENDENCIES)
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

void MealView::listMealView()
{
    vector<Meal *> list = this->controller->getMealList();
    int count = 0;
    cout << "Meal list :" << endl;

    for (vector<Meal *>::iterator it = list.begin(); it != list.end(); it++)
    {
        cout << ++count << ".\n";
        this->DetailView(*it);
    }
}

void MealView::DetailView(Meal *ptr)
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
