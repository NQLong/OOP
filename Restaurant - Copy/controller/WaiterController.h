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
};

#endif