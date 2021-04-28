#ifndef A8B3A637_FC3F_4C83_99F0_08E354A27E5C
#define A8B3A637_FC3F_4C83_99F0_08E354A27E5C
// class MealItem:
//     def __init__(self, id, quantity, menu_item):
//         self.__meal_item_id = id
//         self.__quantity = quantity
//         self.__menu_item = menu_item

//     def update_quantity(self, quantity):
//         None
#include "../../Menu/Header/MenuItem.h"

class MealItem
{
private:
    int meal_item_id, quantity;
    MenuItem menu_item;

public:
    bool update_quantity(int);
};

#endif /* A8B3A637_FC3F_4C83_99F0_08E354A27E5C */
