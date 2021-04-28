#ifndef restaurant_included
#define restaurant_included

#include <bits/stdc++.h>
#include "../model/model.h"

class Restaurant
{
private:
    //list work as a database for the app, it will store most of all instances created
    vector<Ingridient *> ingridientList;
    vector<Dish *> dishList;
    vector<ServedDish *> servedDishesList;
    vector<Meal *> mealList;
    vector<Table *> tableList;
    vector<Waiter *> waiterList;
    vector<Client *> clientList;
    vector<IngridientQuantity *> ingriQuantList;

public:
    //response signal
    int
        SUCCESS = 1,
        FAIL = 0,
        EXISTING_OBJECT = -1,
        EXISTING_DEPENDENCIES = -2,
        NON_EXISTING_DEPENDENCIES = -3,
        NON_EXISTING_OBJECT = -4;

public:
    

    void addIngriQuant(IngridientQuantity *newItem);

    void addIngridient(Ingridient *ingri);

    void addDish(Dish *newItem);

    void addTable(Table *newItem);

    void addWaiter(Waiter *newItem);

    void addClient(Client *newItem);

    void addServedDish(ServedDish *newItem);

    void addMeal(Meal *newItem);

    int createIngridient(string, string, double);

    int createDish(int, string, vector<string>, vector<double>,double);

    int createMeal(int, int, string, int, int, int, vector<string>, vector<int>);

    Dish *filterDish(int id);
    Dish *filterDish(string id);

    Ingridient *filterIngridient(string name);

    Meal *filterMeal(int);

    Waiter *filterWaiter(string);

    Waiter *filterWaiter(int);

    Client *filterClient(string);

    Table *filterTable(int);

    int editIngridient(Ingridient *, string, string, double);

    int deleteIngridient(string);

    int deleteDish(string);
};

#endif