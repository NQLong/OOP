#ifndef CONTROLLER_INCLUDED
#define CONTROLLER_INCLUDED

#include "../model/Data.h"
#include "GeneralController.h"
#include "MealController.h"
#include "DishController.h"
#include "IngridientController.h"
#include "WaiterController.h"
#include "ClientController.h"
#include "TableController.h"

class Controller : public GeneralController
{
private:
    Data *data;
    MealController *mealController;
    DishController *dishController;
    IngridientController *ingridientController;
    WaiterController *waiterController;
    ClientController *clientController;
    TableController *tableController;

public:
    Controller();
    MealController *getMealController();
    void setMealController(MealController *mealController);

    DishController *getDishController();
    void setDishController(DishController *dishController);

    IngridientController *getIngridientController();
    void setIngridientController(IngridientController *ingridientController);

    WaiterController *getWaiterController();
    void setWaiterController(WaiterController *waiterController);

    ClientController *getClientController();
    void setClientController(ClientController *clientController);

    TableController *getTableController();
    void setTableController(TableController *tableController);
};

#endif