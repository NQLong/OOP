#ifndef CLIENTCONTROLLER
#define CLIENTCONTROLLER

#include "../model/Data.h"
#include "MealController.h"
#include "DishController.h"
#include "IngridientController.h"
#include "WaiterController.h"
#include "TableController.h"

class ClientController
{
private:
    Data *data;
    MealController *mealController;
    DishController *dishController;
    IngridientController *ingridientController;
    WaiterController *waiterController;
    TableController *tableController;

public:
    ClientController();
    ClientController(Data *);
    void config(MealController *mealController,
                    DishController *dishController,
                        IngridientController *ingridientController,
                            WaiterController *waiterController,
                                TableController *tableController)
};

#endif