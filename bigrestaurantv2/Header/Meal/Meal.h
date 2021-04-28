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
#include "../Restaurant/Table.h"
#include <list>

class Meal
{
private:
    int meal_id;
    int seat_id;
    list<MealItem> meal_items;


public:
    Meal();
    ~Meal();
    Meal(int _meal_id,int _seat_id):
    meal_id(_meal_id), seat_id(_seat_id){}
    Meal(int _meal_id,int _seat_id,list<MealItem> _meal_items):
    meal_id(_meal_id), seat_id(_seat_id), meal_items(_meal_items) {}

    double getPrice();

    bool add_meal_item(MealItem);
    bool add_meal_item(Menu*);

    static Meal inputMeal(Table*,int);

    int getMeal_id();
    void setMeal_id(int meal_id);
    list<MealItem>* getMeal_items();
    void setMeal_items(list<MealItem> meal_items);
    int getSeat_id();
    void setSeat_id(int seat_id);

    friend ostream& operator<<(ostream& os, const Meal&);
};

#endif /* D5BD2673_9AAA_44A0_B476_15E88D2162FB */
