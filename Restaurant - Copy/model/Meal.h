#ifndef MEAL_H_INCLUDED
#define MEAL_H_INCLUDED
#include <bits/stdc++.h>

#include "Client.h"
#include "Waiter.h"
#include "Dish.h"
#include "Table.h"
#include "ServedDish.h"
#include "IngridientQuant.h"

// #include "stringOfVector.h"
using namespace std;

class Meal
{
private:
    int id;
    bool confirmed;
    Table *table;
    vector<ServedDish> dishes;
    int date;
    int start;
    int end;
    Waiter *waiter;
    Client *client;
    double price = 0;

public:
    Meal();

    Meal(const Meal &);

    Meal(Table *, vector<ServedDish>, int, int, int, Waiter *, Client *, int);

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
    int getId();
    bool isConfirmed();

    void setConfirmed(bool confirmed);
    void setId(int id);
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