#include "EmployeeManager.h"

template <typename T>
EmployeeManager<T>::EmployeeManager(void * ptr)
{
    this->set_list((list<T>*)ptr);
}

    template <typename T>
    T *EmployeeManager<T>::get_employee(string username, string password)
{
    cout << ListManager<T>::lst;
    wait();
    auto it = ListManager<T>::lst->begin();
    int n = this->lst->size();
    for (int i = 0; i < n; i++)
    {
        if (
            it->getAccount()->getUsername() == username &&
            it->getAccount()->getPassword() == password &&
            true

        )
            return &*it;
        ++it;
    }
    return NULL;
}
