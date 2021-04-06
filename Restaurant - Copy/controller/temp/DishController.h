#ifndef DISHCONTROLLER_INCLUDED
#define DISHCONTROLLER_INCLUDED

#include "../model/Data.h"
#include "MealController.h"
#include "IngridientController.h"
#include "WaiterController.h"
#include "ClientController.h"
#include "TableController.h"

class DishController
{
private:
    Data *data;
    MealController *mealController;
    IngridientController *ingridientController;
    WaiterController *waiterController;
    ClientController *clientController;
    TableController *tableController;

public:
    DishController();
    DishController(Data *);
    void config(MealController *mealController,
                IngridientController *ingridientController,
                WaiterController *waiterController,
                ClientController *clientController,
                TableController *tableController);

    void addDish(Dish *newItem);
    int createDish(int, string, vector<string>, vector<double>, double);

    Dish *filterDish(int id);
    Dish *filterDish(string id);

    int deleteDish(string);
};

#endif