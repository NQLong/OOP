#ifndef A8B3A637_FC3F_4C83_99F0_08E354A27E5C
#define A8B3A637_FC3F_4C83_99F0_08E354A27E5C
// class MealItem:
//     def __init__(self, id, quantity, menu_item):
//         self.__meal_item_id = id
//         self.__quantity = quantity
//         self.__menu_item = menu_item

//     def update_quantity(self, quantity):
//         None
#include "../Menu/Menu.h"

class MealItem
{
private:
    int meal_item_id,
        quantity,
        menu_id,
        menu_section_id,
        menu_item_id;

    static int new_id;

public:
    static string class_name;
    MealItem();
    ~MealItem();
    MealItem(
        int _quantity,
        int _menu_id,
        int _menu_section_id,
        int _menu_item_id)
        : meal_item_id(new_id++),
          quantity(_quantity),
          menu_id(_menu_id),
          menu_section_id(_menu_section_id),
          menu_item_id(_menu_item_id)
    {
    }

    double getPrice();
    bool pick_item(Menu *);

    static MealItem input(int);
    MenuItem *get_menu_item();

    bool update_quantity(int);

    int getMeal_item_id();
    void setMeal_item_id(int meal_item_id);
    int getQuantity();
    void setQuantity(int quantity);
    int getMenu_id();
    void setMenu_id(int menu_id);
    int getMenu_section_id();
    void setMenu_section_id(int menu_section_id);
    int getMenu_item_id();
    void setMenu_item_id(int menu_item_id);

    friend ostream &operator<<(ostream &os, const MealItem &);
    friend ostream &operator<<(ostream &os, const list<MealItem> &);
};

#endif /* A8B3A637_FC3F_4C83_99F0_08E354A27E5C */
