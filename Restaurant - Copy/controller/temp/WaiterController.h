#ifndef WAITERCONTROLLER_INCLUDED
#define WAITERCONTROLLER_INCLUDED

#include "../model/Data.h"
#include "MealController.h"
#include "DishController.h"
#include "IngridientController.h"
#include "ClientController.h"
#include "TableController.h"

class WaiterController
{
private:
    Data *data;
    MealController *mealController;
    DishController *dishController;
    IngridientController *ingridientController;
    ClientController *clientController;
    TableController *tableController;

public:
    WaiterController();
    WaiterController(Data *);
    void config(
        MealController *mealController,
        DishController *dishController,
        IngridientController *ingridientController,
        ClientController *clientController,
        TableController *tableController);

    void addWaiter(Waiter *newItem);
    Waiter *filterWaiter(string);

    Waiter *filterWaiter(int);
};

#endif