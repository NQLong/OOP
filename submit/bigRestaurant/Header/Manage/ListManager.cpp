#include "ListManager.h"

template <typename T>
ListManager<T>::ListManager() {}

template <typename T>
ListManager<T>::~ListManager() {}

template <typename T>
ListManager<T>::ListManager(void *lst)
{
    this->lst = (list<T> *)lst;
}

template <typename T>
list<T> *ListManager<T>::get_list()
{
    return lst;
}

template <typename T>
void ListManager<T>::set_list(list<T> *employees)
{
    this->lst = employees;
}

template <typename T>
bool ListManager<T>::add_element(T t)
{
    if (get_element(t.get_id()))
    {
        return false;
    }
    this->lst->push_back(t);
    return true;
}

template <typename T>
bool ListManager<T>::add_element(int branch_id)
{
    cout << "Add new " + T::class_name + ": \n";
    if (add_element(T::input(branch_id)))
    {
        clear();
        cout << "Success\n";
        return true;
    }
    clear();
    cout << "fail\n";
    return false;
}

template <typename T>
bool ListManager<T>::remove_element()
{
    T *ptr = pick_element();
    if (!ptr || !remove_element(*ptr))
    {
        clear();
        cout << "fail\n";
        return false;
    }
    clear();
    cout << "Success\n";
    return true;
}
template <typename T>
list<T> ListManager<T>::get_element_from_branch(int branch)
{
    list<T> nlst;
    auto it = lst->begin();
    int n = lst->size();
    for (int i = 0; i < n; i++)
    {
        if (it->get_branch_id() == branch)
            nlst.push_back(*it);
        ++it;
    }
    return nlst;
}

template <typename T>
bool ListManager<T>::remove_element(T t)
{
    lst->remove(t);
    return true;
}

template <typename T>
void ListManager<T>::view_elements(int, int) {}

template <typename T>
T *ListManager<T>::pick_element()
{
    int id;
    cout << "Enter " + T::class_name + " id: ";
    cin >> id;
    cin.ignore();
    return get_element(id);
}

template <typename T>
T *ListManager<T>::get_last()
{
    if (this->lst->size() == 0)
        return NULL;
    return &this->lst->back();
}

template <typename T>
T *ListManager<T>::pick_element(int branch_id)
{
    T *ptr = pick_element();

    if (ptr && ptr->get_branch_id() == branch_id)
        return ptr;
    return NULL;
}

// template <class T>
// T *ListManager<T>::get_element(int id)
// {
//      auto it = lst->begin();
//     int n = lst->size();
//     for (int i = 0; i < n; i++)
//     {
//         if (it->get_id() == id)
//             return &*it;
//         it++;
//     }
//     return NULL;
// }

template <typename T>
void ListManager<T>::manage_elements(int branch)
{
    int option;
    bool loop = true;
    while (loop)
    {
        print_option({"add " + T::class_name,
                      "remove " + T::class_name,
                      "view " + T::class_name,
                      "customers " + T::class_name

        });

        cin >> option;
        cin.ignore();
        switch (option)
        {
        case 1:
            clear();
            add_element(branch);
            wait();
            break;
        case 2:
            clear();
            remove_element();
            wait();
            break;

        case 3:
            clear();
            // select_employee();
            wait();
            break;
        case 4:
            clear();
            view_elements(0,0);
            wait();
            break;

        default:
            loop = false;
            break;
        }
    }

    return;
}