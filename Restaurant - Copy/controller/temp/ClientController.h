#ifndef CLIENTCONTROLLER
#define CLIENTCONTROLLER

#include "../model/Data.h"
#include "./GeneralController.h"
#include "MealController.h"
#include "DishController.h"
#include "IngridientController.h"
#include "WaiterController.h"
#include "TableController.h"

class ClientController: public GeneralController
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
                TableController *tableController);

    void addClient(Client *);
    
    int createClient(string, string, string);
    
    Client *filterClient(string);
    
    int deleteClient(string);

    void editClient(string, string, string);

};

#endif