#ifndef TABLECONTROLLER_INCLUDED
#define TABLECONTROLLER_INCLUDED

#include "../model/Data.h"
#include "MealController.h"
#include "DishController.h"
#include "IngridientController.h"
#include "WaiterController.h"
#include "ClientController.h"


class TableController
{
private:
    Data *data;
    MealController *mealController;
    DishController *dishController;
    IngridientController *ingridientController;
    WaiterController *waiterController;
    ClientController *clientController;
    

public:

};

#endif