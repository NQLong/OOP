#include "IngridientController.h"

IngridientController::IngridientController() {}
IngridientController::IngridientController(Data *data)
{
    this->data = data;
}
void IngridientController::config(MealController *mealController,
                                  DishController *dishController,
                                  WaiterController *waiterController,
                                  ClientController *clientController,
                                  TableController *tableController)

{
    this->mealController = mealController;
    this->clientController = clientController;
    this->dishController = dishController;
    this->waiterController = waiterController;
    this->tableController = tableController;
}