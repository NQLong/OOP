#include "WaiterController.h"

WaiterController::WaiterController() {}
WaiterController::WaiterController(Data *data)
{
    this->data = data;
}
void WaiterController::config(MealController *mealController,
                              DishController *dishController,
                              IngridientController *ingridientController,
                              ClientController *clientController,
                              TableController *tableController)

{
    this->ingridientController = ingridientController;
    this->clientController = clientController;
    this->dishController = dishController;
    this->mealController = mealController;
    this->tableController = tableController;
}