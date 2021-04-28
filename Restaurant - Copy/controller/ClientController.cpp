#include "ClientController.h"

ClientController::ClientController();
ClientController::ClientController(Data *);
void ClientController::config(MealController *mealController,
                                  DishController *dishController,
                                      IngridientController *ingridientController,
                                          WaiterController *waiterController,
                                              TableController *tableController)

{
    this->mealController = mealController;
    this->dishController = dishController;
    this->ingridientController = ingridientController;
    this->waiterController = waiterController;
    this->tableController = tableController;
}