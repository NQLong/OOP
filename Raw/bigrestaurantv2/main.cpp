#include "Header/Restaurant/Restaurant.h"
#include "Header/Restaurant/Branch.h"
#include "Header/Constraint/constraint.h"
#include "Header/View/View.h"
#include "Header/Actor/Manager.h"

void initData()
{
    Restaurant restaurant("Dracula");

    restaurant.addBranch(
        Branch(0, "Turkish", Address("Bleeker", "New York", "New York", "10000", "United States of America"), Kitchen("Hell kitchen")));

    restaurant.addBranch(
        Branch(1, "Hungary", Address("Bleeker", "New York", "New York", "10000", "United States of America"), Kitchen("Hell kitchen")));

    Admin *a = new Admin(
        0, "Vlad III Dracula",
        Account(
            "0", "0",
            Address("Bleeker", "New York", "New York", "10000", "United States of America"),
            A_ACTIVE),
        "Dracula@gmail.com", "0785788177");

    restaurant.addEmployee(a);

    restaurant.addEmployee(new Manager(
        1,
        "Van Helsing",
        Account(
            "1", "1",
            Address("Bleeker", "New York", "New York", "10000", "United States of America"),
            A_ACTIVE),
        "Helsing@gmail.com",
        "0785788177",
        0));

    restaurant.addEmployee(new Chef(
        2, "Dracula jr",
        Account(
            "2", "2",
            Address("Bleeker", "New York", "New York", "10000", "United States of America"),
            A_ACTIVE),
        "Draculajr@gmail.com", "0785788177", 0));
    restaurant.addEmployee(new Receptionist(
        3, "3",
        Account(
            "3", "3",
            Address("Bleeker", "New York", "New York", "10000", "United States of America"),
            A_ACTIVE),
        "Dracula@gmail.com", "0785788177", 0));
    restaurant.addEmployee(new Receptionist(
        4, "4",
        Account(
            "4", "4",
            Address("Bleeker", "New York", "New York", "10000", "United States of America"),
            A_ACTIVE),
        "Dracula@gmail.com", "0785788177", 0));

    Menu *menu = new Menu(0, "Hell menu", "Food from hell");

    MenuSection section(0, "Fried", "fries of Satan");

    section.add_menu_item(
        MenuItem(0, "chiken fry", "fry on the hell fire", 10.5));

    section.add_menu_item(
        MenuItem(1, "fish fry", "fry on the hell fire", 5.5));

    menu->add_menu_section(section);
    MenuSection section2(1, "Boil", "fries of Satan");

    section2.add_menu_item(
        MenuItem(0, "Potato Boil", "boil on the hell fire", 10.5));

    section2.add_menu_item(
        MenuItem(1, "Carrot Boil", "boil on the hell fire", 5.5));

    menu->add_menu_section(section2);

    Menu::addMenu(menu);
    Restaurant::getBranches()->front().setMenu_id(menu->getMenu_id());

    Table table(0, 2, 3, 0);
    table.add_seat(TableSeat(0, S_KID, 0, 0));
    table.add_seat(TableSeat(1, S_REGULAR, 0, 0));
    Table::addTable(table);

    Table table2(1, 2, 4, 0);
    table2.add_seat(TableSeat(0, S_KID, 0, 1));
    table2.add_seat(TableSeat(1, S_REGULAR, 0, 1));
    Table::addTable(table2);

    Order::add_order(
        Order(
            0, 3, -1, -1, 0, O_RECEIVED, 0,
            {
                Meal(
                    0, 0, 
                    {
                        MealItem(0, 2, 0, 1, 0),
                        MealItem(1, 2, 0, 1, 1)
                    }
                ),
                Meal(
                    1, 1, 
                    {
                        MealItem(0, 2, 0, 1, 0),
                        MealItem(1, 2, 0, 1, 1)
                    }
                )
            }
        )
    );
}
int main()
{
    initData();
    View view;
    view.startApp();
}