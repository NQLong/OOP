#ifndef B52D8915_49C2_42BA_8485_553572DE15CB
#define B52D8915_49C2_42BA_8485_553572DE15CB
#include "../Meal/Meal.h"
#include "ListManager.h"
class MealManager
    : public ListManager<Meal>
{
public:
    MealManager(void *ptr) : ListManager<Meal>(ptr) {}
    bool add_element(int menu, int table_id)
    {
        cout << "Add new " + Meal::class_name + ": \n";
        if (ListManager<Meal>::add_element(Meal::input(menu, table_id)))
        {
            clear();
            cout << "Success\n";
            return true;
        }
        clear();
        cout << "fail\n";
        return false;
    }
};

#endif /* B52D8915_49C2_42BA_8485_553572DE15CB */
