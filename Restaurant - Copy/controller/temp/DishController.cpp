#include "DishController.h"

DishController::DishController() {}
DishController::DishController(Data *data)
{
    this->data = data;
}
void DishController::config(MealController *mealController,
                            IngridientController *ingridientController,
                            WaiterController *waiterController,
                            ClientController *clientController,
                            TableController *tableController)

{
    this->mealController = mealController;
    this->clientController = clientController;
    this->ingridientController = ingridientController;
    this->waiterController = waiterController;
    this->tableController = tableController;
}