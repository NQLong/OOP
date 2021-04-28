#include "restaurant.h"

using namespace std;

vector<Ingridient *> Restaurant::getIngridientList()
{
    return this->ingridientList;
}

void Restaurant::setIngridientList(vector<Ingridient *> ingridientList)
{
    this->ingridientList = ingridientList;
}

vector<Dish *> Restaurant::getDishList()
{
    return this->dishList;
}

void Restaurant::setDishList(vector<Dish *> dishList)
{
    this->dishList = dishList;
}

vector<ServedDish *> Restaurant::getServedDishesList()
{
    return this->servedDishesList;
}

void Restaurant::setServedDishesList(vector<ServedDish *> servedDishesList)
{
    this->servedDishesList = servedDishesList;
}

vector<Meal *> Restaurant::getMealList()
{
    return this->mealList;
}

void Restaurant::setMealList(vector<Meal *> mealList)
{
    this->mealList = mealList;
}

vector<Table *> Restaurant::getTableList()
{
    return this->tableList;
}

void Restaurant::setTableList(vector<Table *> tableList)
{
    this->tableList = tableList;
}

vector<Waiter *> Restaurant::getWaiterList()
{
    return this->waiterList;
}

void Restaurant::setWaiterList(vector<Waiter *> waiterList)
{
    this->waiterList = waiterList;
}

vector<Client *> Restaurant::getClientList()
{
    return this->clientList;
}

void Restaurant::setClientList(vector<Client *> clientList)
{
    this->clientList = clientList;
}

vector<IngridientQuantity *> Restaurant::getIngriQuantList()
{
    return this->ingriQuantList;
}

void Restaurant::setIngriQuantList(vector<IngridientQuantity *> ingriQuantList)
{
    this->ingriQuantList = ingriQuantList;
}

void Restaurant::addIngriQuant(IngridientQuantity *newItem)
{
    vector<IngridientQuantity *>::iterator tail = this->ingriQuantList.end();
    tail = this->ingriQuantList.insert(tail, newItem);
}

void Restaurant::addIngridient(Ingridient *ingri)
{
    vector<Ingridient *>::iterator tail = this->ingridientList.end();
    tail = this->ingridientList.insert(tail, ingri);
}

void Restaurant::addDish(Dish *newItem)
{
    vector<Dish *>::iterator tail = this->dishList.end();
    tail = this->dishList.insert(tail, newItem);
}

void Restaurant::addTable(Table *newItem)
{
    vector<Table *>::iterator tail = this->tableList.end();
    tail = this->tableList.insert(tail, newItem);
}

void Restaurant::addWaiter(Waiter *newItem)
{
    vector<Waiter *>::iterator tail = this->waiterList.end();
    tail = this->waiterList.insert(tail, newItem);
}

void Restaurant::addClient(Client *newItem)
{
    vector<Client *>::iterator tail = this->clientList.end();
    tail = this->clientList.insert(tail, newItem);
}

void Restaurant::addServedDish(ServedDish *newItem)
{
    vector<ServedDish *>::iterator tail = this->servedDishesList.end();
    tail = this->servedDishesList.insert(tail, newItem);
}

void Restaurant::addMeal(Meal *newItem)
{
    vector<Meal *>::iterator tail = this->mealList.end();
    tail = this->mealList.insert(tail, newItem);
}

Dish *Restaurant::filterDish(int id)
{
    for (vector<Dish *>::iterator i = dishList.begin(); i != dishList.end(); i++)
    {
        if ((*i)->getId() == id)
            return *i;
    }
    return NULL;
}

Dish *Restaurant::filterDish(string name)
{
    for (vector<Dish *>::iterator i = dishList.begin(); i != dishList.end(); i++)
    {
        if ((*i)->getName() == name)
            return *i;
    }
    return NULL;
}

Ingridient *Restaurant::filterIngridient(string name)
{
    for (vector<Ingridient *>::iterator i = ingridientList.begin(); i != ingridientList.end(); i++)
    {
        if ((*i)->getName() == name)
            return *i;
    }
    return NULL;
}

Waiter *Restaurant::filterWaiter(string name)
{
    for (vector<Waiter *>::iterator i = waiterList.begin(); i != waiterList.end(); i++)
    {
        if ((*i)->getName() == name)
            return *i;
    }
    return NULL;
}

Waiter *Restaurant::filterWaiter(int id)
{
    for (vector<Waiter *>::iterator i = waiterList.begin(); i != waiterList.end(); i++)
    {
        if ((*i)->getId() == id)
            return *i;
    }
    return NULL;
}

Client *Restaurant::filterClient(string name)
{
    for (vector<Client *>::iterator i = clientList.begin(); i != clientList.end(); i++)
    {
        if ((*i)->getName() == name)
            return *i;
    }
    return NULL;
}

Table *Restaurant::filterTable(int id)
{
    for (vector<Table *>::iterator i = tableList.begin(); i != tableList.end(); i++)
    {
        if ((*i)->getId() == id)
            return *i;
    }
    return NULL;
}

int Restaurant::createIngridient(string name, string measureUnit, double stock)
{
    Ingridient *ptr = this->filterIngridient(name);
    if (ptr)
        return EXISTING_OBJECT;
    else
    {
        ptr = new Ingridient(name, measureUnit, stock);
        this->addIngridient(ptr);
    }
    return this->SUCCESS;
}

int Restaurant::createDish(int id, string name, vector<string> ingridient, vector<double> needQuantity, double price)
{
    bool existed = false;
    Dish *ptr;
    vector<IngridientQuantity> list;
    Ingridient *ingridient_ptr;

    existed = this->filterDish(id) ? true : this->filterDish(name) ? true
                                                                   : false;
    if (existed)
        return this->EXISTING_OBJECT;

    for (long unsigned int i = 0; i < ingridient.size(); i++)
    {
        ingridient_ptr = this->filterIngridient(ingridient[i]);
        if (!ingridient_ptr)
            return this->NON_EXISTING_DEPENDENCIES;

        list.insert(list.begin(), IngridientQuantity(ingridient_ptr, needQuantity[i]));
    }

    ptr = new Dish(name, id, list, price);
    this->addDish(ptr);
    return this->SUCCESS;
}

int Restaurant::createMeal(int tableId, int waiterId, string clientName,
                           int date, int start, int end,
                           vector<string> dishNames,
                           vector<int> dishQuant)
{

    Table *table_ptr;
    Waiter *waiter_ptr;
    Client *client_ptr;
    Dish *dish_ptr;
    Meal *meal_ptr;
    vector<ServedDish> list;
    table_ptr = this->filterTable(tableId);
    waiter_ptr = this->filterWaiter(waiterId);
    client_ptr = this->filterClient(clientName);
    if (!(table_ptr && waiter_ptr && client_ptr))
    {
        return this->NON_EXISTING_DEPENDENCIES;
    }
    for (long unsigned int i = 0; i < dishNames.size(); i++)
    {
        dish_ptr = this->filterDish(dishNames[i]);

        if (!dish_ptr)
            return this->NON_EXISTING_DEPENDENCIES;
        list.insert(list.end(), ServedDish(dish_ptr, dishQuant[i]));
    }

    meal_ptr = new Meal(table_ptr, list, date, start, end, waiter_ptr, client_ptr);
    return this->SUCCESS;
}

int Restaurant::editIngridient(Ingridient *ingridient, string name, string measureUnit, double stock)
{
    Ingridient *ptr = this->filterIngridient(name);

    if (ptr && ptr != ingridient)
        return this->FAIL;

    ingridient->setName(name);
    ingridient->setMeasureUnit(measureUnit);
    ingridient->setQuantity(stock);
    return this->SUCCESS;
}

int Restaurant::deleteIngridient(string name)
{
    Ingridient *ingridient_ptr = this->filterIngridient(name);
    if (!ingridient_ptr)
        return this->NON_EXISTING_OBJECT;
    // vector<Dish*> dishes = this->dishList;
    for (vector<Dish *>::iterator dish = this->dishList.begin(); dish != this->dishList.end(); dish++)
    {
        if ((*dish)->consistOfIngridient(ingridient_ptr))
            this->deleteDish((*dish)->getName());
    }
    delete ingridient_ptr;
    return this->SUCCESS;
}

int Restaurant::deleteDish(string name)
{
    Dish *dish_ptr = this->filterDish(name);
    if (!dish_ptr)
        return this->NON_EXISTING_OBJECT;
    // vector<Dish*> dishes = this->dishList;
    for (vector<Meal *>::iterator meal = this->mealList.begin(); meal != this->mealList.end(); meal++)
    {
        if ((*meal)->consistOfDish(dish_ptr))
        {
            (*meal)->removeDish(dish_ptr);
            if ((*meal)->getDishes().size() == 0)
                this->deleteMeal((*meal)->getId());
        }
    }
    delete dish_ptr;
    return this->SUCCESS;
}

int Restaurant::removeDishFromMeal(Dish *dish, Meal *meal)
{
}