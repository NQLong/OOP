#include "ClientController.h"

ClientController::ClientController() {}
ClientController::ClientController(Data *data)
{
    this->data = data;
}
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

void ClientController::addClient(Client *newItem)
{
    vector<Client *>::iterator tail = this->data->getClientList().end();
    tail = data->getClientList().insert(tail, newItem);
}

Client *ClientController::filterClient(string name)
{
    for (vector<Client *>::iterator i = this->data->getClientList().begin();
         i != this->data->getClientList().end();
         i++)
    {
        if ((*i)->getName() == name)
            return *i;
    }
    return NULL;
}