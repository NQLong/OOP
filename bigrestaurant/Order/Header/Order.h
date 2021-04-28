#ifndef E416A686_C1CA_4FC9_B134_8432EA527B41
#define E416A686_C1CA_4FC9_B134_8432EA527B41
// class Order:
//     def __init__(self, id, status, table, waiter, chef):
//         self.__order_id = id
//         self.__OrderStatus = status
//         self.__creation_time = datetime.now()

//         self.__meals = []
//         self.__table = table
//         self.__waiter = waiter
//         self.__chef = chef
//         self.__check = Check()

//     def add_meal(self, meal):
//         None

//     def remove_meal(self, meal):
//         None

//     def get_status(self):
//         return self.__OrderStatus

//     def set_status(self, status):
//         None
#include "../../Contraint/constraint.h"

#include "../../Restaurant/Header/Table.h"

#include "../../Actor/Header/Waiter.h"
#include "../../Actor/Header/Chef.h"
#include "../../Meal/Header/Meal.h"

#include "Check.h"

#include <ctime>
class Order
{
private:
    int order_id;
    OrderStatus status;
    Table table;
    time_t creation_time;
    list<Meal> meals;
    Waiter waiter;
    Chef chef;
    Check check;

public:



    bool add_meal(Meal);

    bool remove_meal(Meal);

    OrderStatus get_status();

    void set_status(OrderStatus);
};

#endif /* E416A686_C1CA_4FC9_B134_8432EA527B41 */
