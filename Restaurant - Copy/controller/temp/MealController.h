#ifndef MEALCONTROLLER_INCLUDED
#define MEALCONTROLLER_INCLUDED

#include "../model/Data.h"
#include "DishController.h"
#include "IngridientController.h"
#include "WaiterController.h"
#include "ClientController.h"
#include "TableController.h"

class MealController
{
private:
    Data *data;
    DishController *dishController;
    IngridientController *ingridientController;
    WaiterController *waiterController;
    ClientController *clientController;
    TableController *tableController;

public:
    MealController();
    MealController(Data *);
    void config(
        DishController *dishController,
        IngridientController *ingridientController,
        WaiterController *waiterController,
        ClientController *clientController,
        TableController *tableController);

    void addMeal(Meal *newItem);

    int createMeal(int, int, string, int, int, int, vector<string>, vector<int>);

    Meal *filterMeal(int);
};

#endif