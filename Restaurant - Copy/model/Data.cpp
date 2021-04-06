#include "Data.h"

Data::Data() {}

vector<Ingridient *> Data::getIngridientList()
{
    return this->ingridientList;
}

void Data::setIngridientList(vector<Ingridient *> ingridientList)
{
    this->ingridientList = ingridientList;
}

vector<Dish *> Data::getDishList()
{
    return this->dishList;
}

void Data::setDishList(vector<Dish *> dishList)
{
    this->dishList = dishList;
}

vector<ServedDish *> Data::getServedDishesList()
{
    return this->servedDishesList;
}

void Data::setServedDishesList(vector<ServedDish *> servedDishesList)
{
    this->servedDishesList = servedDishesList;
}

vector<Meal *> Data::getMealList()
{
    return this->mealList;
}

void Data::setMealList(vector<Meal *> mealList)
{
    this->mealList = mealList;
}

vector<Table *> Data::getTableList()
{
    return this->tableList;
}

void Data::setTableList(vector<Table *> tableList)
{
    this->tableList = tableList;
}

vector<Waiter *> Data::getWaiterList()
{
    return this->waiterList;
}

void Data::setWaiterList(vector<Waiter *> waiterList)
{
    this->waiterList = waiterList;
}

vector<Client *> Data::getClientList()
{
    return this->clientList;
}

void Data::setClientList(vector<Client *> clientList)
{
    this->clientList = clientList;
}

vector<IngridientQuantity *> Data::getIngriQuantList()
{
    return this->ingriQuantList;
}

void Data::setIngriQuantList(vector<IngridientQuantity *> ingriQuantList)
{
    this->ingriQuantList = ingriQuantList;
}
