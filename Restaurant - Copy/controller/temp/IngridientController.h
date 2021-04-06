#ifndef INGRIDIENTCONTROLLER_INCLUDED
#define INGRIDIENTCONTROLLER_INCLUDED

#include "../model/Data.h"
#include "MealController.h"
#include "DishController.h"

#include "WaiterController.h"
#include "ClientController.h"
#include "TableController.h"

class IngridientController
{
private:
    Data *data;
    MealController *mealController;
    DishController *dishController;
    WaiterController *waiterController;
    ClientController *clientController;
    TableController *tableController;

public:
    IngridientController();
    IngridientController(Data *);
    void config(MealController *mealController,
                DishController *dishController,
                WaiterController *waiterController,
                ClientController *clientController,
                TableController *tableController);

    int createIngridient(string, string, double);

    void addIngridient(Ingridient *ingri);

    Ingridient *filterIngridient(string name);

    int editIngridient(Ingridient *, string, string, double);

    int deleteIngridient(string);
};

#endif