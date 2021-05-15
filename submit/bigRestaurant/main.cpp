#include "Header/Constraint/Constraint.h"
#include "Header/Actor/Chef.h"
#include "Header/Manage/EmployeeManager.h"
#include "Header/Menu/Menu.h"
#include "Header/Manage/ListManager.h"
#include "Header/Restaurant/Table.h"
#include "Header/Restaurant/Restaurant.h"
#include "Header/Meal/MealItem.h"

int main()
{

    Address address("Bleeker", "New York", "New York", "123456", "USA");
    // list<Chef> cheves;

    // Storage::cheves = &cheves;
    Restaurant restaurant("Hell");
    Storage::Restaurant = &restaurant;
    restaurant.set_branches({
        Branch("Hell", address, Kitchen("Hell Kitchen"), 1),
    });
    list<Menu> menus = {
        Menu("Hell menu", "Menu from hell",
             {
                 MenuSection("Hell fries", "Fries from hell",
                             {
                                 MenuItem("Hell chiken fry", "Fry you wana try", 15),
                                 MenuItem("Hell fish fry", "Fry you wana try", 16),
                                 MenuItem("Hell pork fry", "Fry you wana try", 17),
                             }),
             },
             0),

        Menu("Heaven menu", "Menu from heaven",
             {
                 MenuSection("Heaven fries", "Fries from heaven",
                             {
                                 MenuItem("Heaven chiken fry", "Fry you wana try", 15),
                                 MenuItem("Heaven fish fry", "Fry you wana try", 16),
                                 MenuItem("Heaven pork fry", "Fry you wana try", 17),
                             }),

                 MenuSection("Heaven soup", "Fries from heaven",
                             {
                                 MenuItem("Heaven chiken soup", "Fry you wana try", 15),
                                 MenuItem("Heaven fish soup", "Fry you wana try", 16),
                                 MenuItem("Heaven pork soup", "Fry you wana try", 17),
                             }),
             },
             0),
    };

    Storage::menus = &menus;
    list<Table> tables = {
        Table(1, 2, {

                        TableSeat(S_ACCESSIBLE),
                        TableSeat(S_ACCESSIBLE),
                        TableSeat(S_ACCESSIBLE),
                        TableSeat(S_ACCESSIBLE),
                        TableSeat(S_ACCESSIBLE),
                        TableSeat(S_ACCESSIBLE),
                    })};
    Storage::tables = &tables;

    ListManager<Menu> menus_manager(Storage::menus);
    
    // cout << *menu;
    // cout << menu->get_element(3);

    // EmployeeManager<Chef> test(Storage::cheves);
    // test.add_employee(-1);
    // test.employees_list(cheves);
}