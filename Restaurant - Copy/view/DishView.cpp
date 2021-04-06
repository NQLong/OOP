#include "./DishView.h"

DishView::DishView() {}
DishView::DishView(Restaurant *controller) : GeneralView(controller) {}

bool DishView::createDishView()
{
    bool success = false;
    string name, ingriName, choice;
    int id, nIngridient;
    double quantity, price;
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
        cout << "numer of ingridient :";
        cin >> nIngridient;
        clearCin();
        for (int i = 0; i < nIngridient; i++)
        {
            cout << "Ingridient 's name :";
            getline(cin, ingriName);
            cout << "needed quantity : ";
            cin >> quantity;
            clearCin();
            ingridients.insert(ingridients.end(), ingriName);
            neededQuantity.insert(neededQuantity.end(), quantity);
        }
        cout << "price :";
        cin >> price;
        clearCin();
        res = this->controller->createDish(id, name, ingridients, neededQuantity, price);
        if (res == this->controller->SUCCESS)
            success = true;
        else if (res == this->controller->EXISTING_OBJECT)
        {
            cout << "id or name existed" << endl;
        }
        else if (res == this->controller->NON_EXISTING_DEPENDENCIES)
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

void DishView::listDishView()
{
    cout << "Dishes list: " << endl;
    vector<Dish *> list = this->controller->getDishList();
    int count = 0;
    for (vector<Dish *>::iterator it = list.begin(); it != list.end(); it++)
    {
        cout << ++count << "." << endl;
        this->DetailView(*it);
    }
}

void DishView::filterDishView()
{
    string name;
    Dish *dish_ptr;

    cout << "Seacrch a Dish" << endl;
    cout << "Dish name: ";
    // clearCin();
    getline(cin, name);
    dish_ptr = this->controller->filterDish(name);

    if (!dish_ptr)
        cout << setw(5) << "No result found";
    else
        this->DetailView(dish_ptr);
}

void DishView::DetailView(Dish *ptr)
{
    cout << setw(5) << "" << setw(20) << "id :" << ptr->getId() << endl;
    cout << setw(5) << "" << setw(20) << "name :" << ptr->getName() << endl;
    cout << setw(5) << "" << setw(20) << "price :" << ptr->getPrice() << endl;
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
