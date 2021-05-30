#ifndef D4E451A2_8310_4521_A963_575CDCAA0B3F
#define D4E451A2_8310_4521_A963_575CDCAA0B3F

#include "../../Header/Constraint/Constraint.h"

template <typename T>
class ListManager
{
public:
    list<T> *lst;
    ListManager();
    ~ListManager();
    ListManager(void *);

    list<T> *get_list();
    void set_list(list<T> *employees);

    list<T> get_element_from_branch(int branch);
    bool add_element(T);
    bool add_element(int branch_id);
    bool remove_element();
    bool remove_element(T);
    T *pick_element();
    T *pick_element(int branch);
    T *get_element(int id)
    {
        auto it = lst->begin();
        int n = lst->size();
        for (int i = 0; i < n; i++)
        {
            if (it->get_id() == id)
                return &*it;
            ++it;
        }
        return NULL;
    }
    T *get_last();
    void view_elements(int, int);
    void manage_elements(int);
};

#include "ListManager.cpp"

#endif /* D4E451A2_8310_4521_A963_575CDCAA0B3F */
