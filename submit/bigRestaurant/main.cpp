#include "Header/Constraint/Constraint.h"
#include "Header/Actor/Chef.h"
#include "Header/Manage/EmployeeManager.h"
#include "Header/Menu/Menu.h"
#include "Header/Manage/ListManager.h"
#include "Header/Restaurant/Table.h"
#include "Header/Restaurant/Restaurant.h"
#include "Header/Meal/MealItem.h"
#include "Header/Meal/Meal.h"
#include "Header/Order/Order.h"
#include "Header/Reservation/Reservation.h"
#include "Header/Manage/ReservationManager.h"
#include "Header/View/View.h"
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

                 MenuSection("Heaven soup", "Soups from heaven",
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
        Table(1, 0, {

                        TableSeat(S_ACCESSIBLE),
                        TableSeat(S_ACCESSIBLE),
                        TableSeat(S_ACCESSIBLE),
                        TableSeat(S_ACCESSIBLE),
                        TableSeat(S_ACCESSIBLE),
                        TableSeat(S_ACCESSIBLE),
                        TableSeat(S_ACCESSIBLE),
                        TableSeat(S_ACCESSIBLE),
                        TableSeat(S_ACCESSIBLE),
                    }),

        Table(2, 0, {

                        TableSeat(S_ACCESSIBLE),
                        TableSeat(S_ACCESSIBLE),
                        TableSeat(S_ACCESSIBLE),
                        TableSeat(S_ACCESSIBLE),
                        TableSeat(S_ACCESSIBLE),
                        TableSeat(S_ACCESSIBLE),
                        TableSeat(S_ACCESSIBLE),
                        TableSeat(S_ACCESSIBLE),
                    }),

        Table(3, 0, {

                        TableSeat(S_ACCESSIBLE),
                        TableSeat(S_ACCESSIBLE),
                        TableSeat(S_ACCESSIBLE),
                        TableSeat(S_ACCESSIBLE),
                        TableSeat(S_ACCESSIBLE),
                        TableSeat(S_ACCESSIBLE),
                        TableSeat(S_ACCESSIBLE),
                    }),

        Table(4, 0, {

                        TableSeat(S_ACCESSIBLE),
                        TableSeat(S_ACCESSIBLE),
                        TableSeat(S_ACCESSIBLE),
                        TableSeat(S_ACCESSIBLE),
                        TableSeat(S_ACCESSIBLE),
                        TableSeat(S_ACCESSIBLE),
                    }),

        Table(5, 0, {

                        TableSeat(S_ACCESSIBLE),
                        TableSeat(S_ACCESSIBLE),
                        TableSeat(S_ACCESSIBLE),
                        TableSeat(S_ACCESSIBLE),
                        TableSeat(S_ACCESSIBLE),
                        TableSeat(S_ACCESSIBLE),
                        TableSeat(S_ACCESSIBLE),
                        TableSeat(S_ACCESSIBLE),
                        TableSeat(S_ACCESSIBLE),
                    }),

    };
    Storage::tables = &tables;

    list<Order> orders = {
        Order(
            0,          //creator
            -1,         // chef
            -1,         //checkid
            0,          //table_id
            O_RECEIVED, //Stattus
            0,          //branchid
            {
                Meal(0, {
                            MealItem(
                                1 /*phan*/,
                                /*tu menu*/ 1,
                                /*section*/ 1,
                                /*item*/ 3),
                            MealItem(
                                2 /*phan*/,
                                /*tu menu*/ 1,
                                /*section*/ 1,
                                /*item*/ 4),
                            MealItem(
                                3 /*phan*/,
                                /*tu menu*/ 1,
                                /*section*/ 1,
                                /*item*/ 5),
                        })}),
    };
    Storage::orders = &orders;
    list<Reservation> reservations =
        {
            Reservation(
                time(0) + SECOND_IN_HOUR / 2,
                10,
                R_CONFIRMED,
                "",
                0,
                -1,
                {0, 1, 2},
                {},
                0,
                3),
            Reservation(
                time(0) + 4 * SECOND_IN_DAY,
                10,
                R_PENDING,
                "",
                0,
                -1,
                {},
                {},
                0,
                3),
        };
    Storage::reservations = &reservations;

    list<Receptionist> receptionists = {
        Receptionist(
            "Receptionist",
            Account("3", "3", address, A_ACTIVE),
            "Receptionist", "0123456", 0),
    };
    Storage::recetionists = &receptionists;
    View view;
    view.startApp();
}