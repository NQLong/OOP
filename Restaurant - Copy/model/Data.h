#ifndef model_included
#define model_included

#include "Ingridient.h"
#include "Client.h"
#include "Waiter.h"
#include "Dish.h"
#include "Table.h"
#include "ServedDish.h"
#include "IngridientQuant.h"
#include "Meal.h"

class Data
{
private:
    vector<Ingridient *> ingridientList;
    vector<Dish *> dishList;
    vector<ServedDish *> servedDishesList;
    vector<Meal *> mealList;
    vector<Table *> tableList;
    vector<Waiter *> waiterList;
    vector<Client *> clientList;
    vector<IngridientQuantity *> ingriQuantList;

public:
    Data();
    vector<Ingridient *> getIngridientList();
    void setIngridientList(vector<Ingridient *> ingridientList);

    vector<Dish *> getDishList();
    void setDishList(vector<Dish *> dishList);

    vector<ServedDish *> getServedDishesList();
    void setServedDishesList(vector<ServedDish *> servedDishesList);

    vector<Meal *> getMealList();
    void setMealList(vector<Meal *> mealList);

    vector<Table *> getTableList();
    void setTableList(vector<Table *> tableList);

    vector<Waiter *> getWaiterList();
    void setWaiterList(vector<Waiter *> waiterList);

    vector<Client *> getClientList();
    void setClientList(vector<Client *> clientList);

    vector<IngridientQuantity *> getIngriQuantList();
    void setIngriQuantList(vector<IngridientQuantity *> ingriQuantList);
};
#endif