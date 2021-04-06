#ifndef view_included
#define view_included

#include "../controller/restaurant.h"

#include "./MealView.h"
#include "./IngridientView.h"
#include "./ClientView.h"
#include "./WaiterView.h"
#include "./TableView.h"
#include "./DishView.h"

class View
{
private:
    Restaurant *controller;
    DishView *dishView;
    TableView *tableView;
    WaiterView *waiterView;
    ClientView *clientView;
    IngridientView *ingridientView;
    MealView *mealView;

public:
    View();
    ~View();

    void startApp();

    Restaurant *getRestaurant();

    bool mainView();

    void commandsView();
};

#endif