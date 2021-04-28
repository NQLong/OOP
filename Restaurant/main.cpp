

#include "view/view.h"

void makeTestData(Restaurant *restaurant)
{
    Ingridient *ingridient_ptr;
    Dish *dish_ptr;
    Table *table_ptr;
    Client *client_ptr;
    Waiter *waiter_ptr;
    Meal *meal_ptr;
    vector<IngridientQuantity> testList;
    vector<ServedDish> testList2;

    ingridient_ptr = new Ingridient("gao", "kg", 10);
    restaurant->addIngridient(ingridient_ptr);
    ingridient_ptr = new Ingridient("nam linh chi", "kg", 12);
    restaurant->addIngridient(ingridient_ptr);

    testList.insert(testList.end(), IngridientQuantity(ingridient_ptr, 10));
    dish_ptr = new Dish("chao nam", 1, testList);
    restaurant->addDish(dish_ptr);

    table_ptr = new Table(1, 10);
    restaurant->addTable(table_ptr);
    table_ptr = new Table(2, 12);
    restaurant->addTable(table_ptr);

    waiter_ptr = new Waiter(1, "Ben", "Bien Hoa", "01231293");
    restaurant->addWaiter(waiter_ptr);
    waiter_ptr = new Waiter(2, "Brian", "Bien Hoa", "012312932");
    restaurant->addWaiter(waiter_ptr);

    client_ptr = new Client("Peter", "HCMC", "aq23123");
    restaurant->addClient(client_ptr);
    client_ptr = new Client("Tony", "HCMC", "aq231232");
    restaurant->addClient(client_ptr);

    (testList2).insert((testList2).end(), ServedDish(dish_ptr, 5));
    meal_ptr = new Meal(table_ptr, testList2, 1, 12, 13, waiter_ptr, client_ptr);
    restaurant->addMeal(meal_ptr);
    
}
int main()
{
    View *app = new View();
    makeTestData(app->getRestaurant());
    app->startApp();
    return 0;
}
