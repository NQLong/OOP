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

void ReservationManager::view_elements(int branch, int status)
{
    ReservationStatus stat;
    bool all = status > 4;
    if (!all)
    {
        stat = (ReservationStatus)status;
    }
    list<Reservation> r_lst;
    auto it = lst->begin();
    int n = lst->size();
    for (int i = 0; i < n; i++)
    {
        if (i != 0)
            it++;
        if (!all)
        {
            if (it->getStatus() != stat)
                continue;
        }
        r_lst.push_back(*it);
    }
}