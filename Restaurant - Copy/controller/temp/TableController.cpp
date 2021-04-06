#include "TableController.h"

TableController::TableController() {}
TableController::TableController(Data *data)
{
    this->data = data;
}
void TableController::config(
    MealController *mealController,
    DishController *dishController,
    IngridientController *ingridientController,
    WaiterController *waiterController,
    ClientController *clientController)

{
    this->ingridientController = ingridientController;
    this->clientController = clientController;
    this->dishController = dishController;
    this->waiterController = waiterController;
    this->mealController = mealController;
}