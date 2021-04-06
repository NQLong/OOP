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
    TableController();
    TableController(Data *);
    void config(
        MealController *mealController,
        DishController *dishController,
        IngridientController *ingridientController,
        WaiterController *waiterController,
        ClientController *clientController);

    void addTable(Table *newItem);
    int createTable(int);
    void editTable(int);
    Table *filterTable(int);
};

#endif