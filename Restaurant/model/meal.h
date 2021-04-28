#ifndef MEAL_H_INCLUDED
#define MEAL_H_INCLUDED
#include <bits/stdc++.h>

#include "client.h"
#include "waiter.h"
#include "dish.h"
#include "table.h"
#include "servedDish.h"
#include "IngridientQuant.h"

// #include "stringOfVector.h"
using namespace std;

class Meal
{
private:
    Table *table;
    vector<ServedDish> dishes;
    int date;
    int start;
    int end;
    Waiter *waiter;
    Client *client;
    double price;

public:
    Meal();

    Meal(const Meal &);

    Meal(Table *, vector<ServedDish>, int, int, int, Waiter *, Client *);

    Meal &operator=(const Meal &);

    Table *getTable();
    vector<ServedDish> getDishes();
    int getDate();
    int getStart();
    int getEnd();
    Waiter *getWaiter();
    Client *getClient();
    string toString();
    double getPrice();

    void setPrice(double price);
    void setTable(Table *);
    void setDate(int);
    void setStart(int);
    void setEnd(int);
    void setDishes(vector<ServedDish>);
    void addDish(ServedDish);
    void setWaiter(Waiter *);
    void setClient(Client *);

    bool consistOfDish(Dish *);

    void removeDish(Dish *);
};

#endif