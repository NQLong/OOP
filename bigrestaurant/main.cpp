#include "Restaurant/Header/Restaurant.h"
#include "Restaurant/Header/Branch.h"
#include "Constraint/constraint.h"
#include "View/Header/View.h"
#include "Actor/Header/Manager.h"

void initData()
{
    Restaurant restaurant("Dracula");
    
    restaurant.addBranch(
        Branch(0, "Turkish", Address("Bleeker", "New York", "New York", "10000", "United States of America"),Kitchen("Hell kitchen")));
    
    restaurant.addBranch(
        Branch(1, "Hungary", Address("Bleeker", "New York", "New York", "10000", "United States of America"),Kitchen("Hell kitchen")));
    
    Admin *a = new Admin(
        0, "Vlad III Dracula",
        Account(
            "0", "0",
            Address("Bleeker", "New York", "New York", "10000", "United States of America"),
            A_ACTIVE),
        "Dracula@gmail.com", "0785788177");

    restaurant.addEmployee(a);

    restaurant.addEmployee(new Manager(
        1, "Van Helsing",
        Account(
            "1", "1",
            Address("Bleeker", "New York", "New York", "10000", "United States of America"),
            A_ACTIVE),
        "Helsing@gmail.com", "0785788177"));
    restaurant.addEmployee(new Chef(
        2, "Dracula jr",
        Account(
            "2", "2",
            Address("Bleeker", "New York", "New York", "10000", "United States of America"),
            A_ACTIVE),
        "Draculajr@gmail.com", "0785788177"));
    restaurant.addEmployee(new Chef(
        3, "3",
        Account(
            "3", "3",
            Address("Bleeker", "New York", "New York", "10000", "United States of America"),
            A_ACTIVE),
        "Dracula@gmail.com", "0785788177"));


}
int main()
{
    initData();
    wait();
    View view;
    view.startApp();
}