#include "MealController.h"

MealController::MealController() {}
MealController::MealController(Data *data)
{
    this->data = data;
}
void MealController::config(DishController *dishController,
                            IngridientController *ingridientController,
                            WaiterController *waiterController,
                            ClientController *clientController,
                            TableController *tableController)

{
    this->ingridientController = ingridientController;
    this->clientController = clientController;
    this->dishController = dishController;
    this->waiterController = waiterController;
    this->tableController = tableController;
}