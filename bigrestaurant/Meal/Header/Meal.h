#ifndef D5BD2673_9AAA_44A0_B476_15E88D2162FB
#define D5BD2673_9AAA_44A0_B476_15E88D2162FB
// class Meal:
//     def __init__(self, id, seat):
//         self.__meal_id = id
//         self.__seat = seat
//         self.__menu_items = []

//     def add_meal_item(self, meal_item):
//         None
#include "MealItem.h"
#include "../../Restaurant/Header/TableSeat.h"
#include <list>

class Meal
{
private:
    int meal_id;
    TableSeat seat;
    list<MealItem> menu_item;

public:
    bool add_meal_item(MealItem);
};

#endif /* D5BD2673_9AAA_44A0_B476_15E88D2162FB */
