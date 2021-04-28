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
};

#endif