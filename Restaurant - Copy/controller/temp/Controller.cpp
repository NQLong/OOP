#include "Controller.h"

Controller::Controller()
{
    this->data = new Data();
    this->mealController = new MealController(data);

    this->dishController = new DishController(data);

    this->ingridientController = new IngridientController(data);

    this->waiterController = new WaiterController(data);

    this->clientController = new ClientController(data);

    this->tableController = new TableController(data);

    this->mealController->config(dishController, ingridientController,
                                 waiterController, clientController, tableController);

    this->dishController->config(mealController, ingridientController,
                                 waiterController, clientController, tableController);

    this->ingridientController->config(mealController, dishController,
                                       waiterController, clientController, tableController);

    this->waiterController->config(mealController, dishController,
                                   ingridientController, clientController, tableController);

    this->clientController->config(mealController, dishController,
                                   ingridientController, waiterController, tableController);

    this->tableController->config(mealController, dishController,
                                  ingridientController, waiterController, clientController);
}