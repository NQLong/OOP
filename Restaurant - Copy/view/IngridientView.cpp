#include "IngridientView.h"

IngridientView::IngridientView() {}

IngridientView::IngridientView(Restaurant *controller) : GeneralView(controller) {}

bool IngridientView::createIngridientView()
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
        res = this->controller->createIngridient(name, mUnit, stock);
        if (res != this->controller->SUCCESS)
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

void IngridientView::listIngridientView()
{
    cout << "Ingridients list: " << endl;
    vector<Ingridient *> list = this->controller->getIngridientList();
    int count = 0;
    for (vector<Ingridient *>::iterator it = list.begin(); it != list.end(); it++)
    {
        cout << ++count << "." << endl;
        this->DetailView(*it);
    }
}

void IngridientView::DetailView(Ingridient *ptr)
{
    cout << setw(5) << "" << setw(10) << "name :" << ptr->getName() << endl;
    cout << setw(5) << "" << setw(10) << "Stock :" << ptr->getStock() << " "
         << "(" << ptr->getMeasureUnit() << ")" << endl;
}

void IngridientView::filterIngridientView()
{
    string name;
    Ingridient *ingridient_ptr;

    cout << "Seacrch a Ingridient" << endl;
    cout << "Ingridient name: ";
    // clearCin();
    getline(cin, name);
    ingridient_ptr = this->controller->filterIngridient(name);

    if (!ingridient_ptr)
        cout << setw(5) << "No result found";
    else
        this->DetailView(ingridient_ptr);
}

void IngridientView::editIngridientView()
{
    Ingridient *ingridient;
    string name;
    string measureUnit;
    double stock;

    cout << "Ingridient 's name: ";
    cin >> name;
    ingridient = this->controller->filterIngridient(name);
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
    int res = this->controller->editIngridient(ingridient, name, measureUnit, stock);
    cout << (res == this->controller->SUCCESS ? "SUCCESS" : "FAIL");
}

void IngridientView::deleteIngridientView()
{}
//     Ingridient *ingridient;
//     string name;
//     string confirm;

//     cout << "Ingridient 's name: ";
//     cin >> name;
//     // ingridient = this->controller->filterIngridient(name);
//     cout << "Deleting confirmation?(Y/N)";
//     cin >> confirm;
//     if (confirm != "Y")
//         return;
//     else
//     {
//         this->controller->deleteIngridient(name);
//     }
// }