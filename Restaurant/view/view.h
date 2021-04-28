#ifndef view_included
#define view_included

#include "../controller/restaurant.h"

class View
{
private:
    Restaurant restaurant;

public:
    View();
    void startApp();

    Restaurant *getRestaurant();

    bool mainView();

    void commandsView();

    bool createIngridientView();
    bool createIngridientQuantityView();
    bool createDishView();
    bool createServedDishView();
    bool createTableView();
    bool createWaiterView();
    
    bool createMealView();

    void filterIngridientView();
    void filterDishView();
    void filterTableView();
    
    void filterMealView();
    void filterWaiterView();

    void IngridientView(Ingridient *);
    void DishView(Dish *);
    void TableView(Table *);
    void ClientView(Client *);
    void MealView(Meal *);
    void WaiterView(Waiter *);

    void listIngridientView();
    void listDishView();
    void listTableView();
    void listClientView();
    void listMealView();
    void listWaiterView();

    void editIngridientView();

    void deleteIngridientView();
    // void listDishView();
    // void listTableView();
    // void listClientView();
    // void listMealView();
    // void listWaiterView();
};

#endif