#include "../../Header/Manage/ReservationManager.h"

list<Reservation> ReservationManager::get_confirmed_reservations_for_table(int table)
{
    list<Reservation> temp;
    auto it = lst->begin();
    int n = lst->size();
    for (int i = 0; i < n; i++)
    {
        if (is_consist<int>(it->getTable_ids(), table) && it->getStatus() == R_CONFIRMED)
            temp.push_back(*it);
        it++;
    }
    return temp;
}