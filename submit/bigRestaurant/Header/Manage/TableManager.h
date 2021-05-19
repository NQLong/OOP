#ifndef C8F022CC_A926_4D4C_AA43_496DD9836410
#define C8F022CC_A926_4D4C_AA43_496DD9836410
#include "ListManager.h"
#include "../Restaurant/Table.h"
#include "../Reservation/Reservation.h"

class TableManager
    : public ListManager<Table>
{
public:
    TableManager(void *ptr) : ListManager<Table>(ptr) {}

    int pick_free_table(int branch, DayTime _time, int duration, bool now)

        ;
    // {
    //     list<Table> lst2 = get_element_from_branch(branch);
    //     auto it = lst2.begin();
    //     int n = lst2.size();
    //     for (int i = 0; i < n; i++)
    //     {
    //         it->check(rev.get)
    //     }
    //     return NULL;
    // }
};

// int TableManager::pick_free_table(int branch, Reservation rev){

// }
#endif /* C8F022CC_A926_4D4C_AA43_496DD9836410 */
