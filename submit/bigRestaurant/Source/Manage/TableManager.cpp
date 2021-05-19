#include "../../Header/Manage/TableManager.h"

int TableManager::pick_free_table(int branch, DayTime _time, int duration, bool now)

{
    list<Table> lst2 = get_element_from_branch(branch);
    auto it = lst2.begin();
    int n = lst2.size();
    for (int i = 0; i < n; i++)
    {
        it->check(_time, duration, now);
    }
    Table *ptr = NULL;
    while (!ptr)
    {
        cout << lst2 << endl;
        ptr = TableManager(&lst2).pick_element(branch);
        if (!ptr || ptr->getStatus() != T_FREE)
        {
            clear();
            cout << "Invalid table id!,trye again";
            wait();
            clear();
        }
    }
    return ptr->get_id();
}