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
};

#endif