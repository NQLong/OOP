#include "../../Header/Manage/EmployeeManager.h"

template <typename T>
EmployeeManager<T>::EmployeeManager() {}

template <typename T>
EmployeeManager<T>::~EmployeeManager() {}

template <typename T>
EmployeeManager<T>::EmployeeManager(void *lst)
{
    this->employees = (list<T> *)lst;
}

template <typename T>
int EmployeeManager<T>::select_employee_id(int branch_id)
{
    employees_list(get_employee_branch(branch_id));
    cout << endl;
    T *ptr = pick_employee();
    if (!ptr || ptr->getBranch_id() != branch_id)
    {
        cout << "Invalid id";
        return -1;
    }
    return ptr->getEmployee_id();
}

template <typename T>
list<T> EmployeeManager<T>::get_employee_branch(int branch_id)
{
    list<T> lst;
    for (typename list<T>::iterator it = employees->begin(); it != employees->end(); it++)
    {
        if (it->getBranch_id() == branch_id)
            lst.push_back(*it);
    }
    return lst;
}

template <typename T>
list<T> *EmployeeManager<T>::get_employees()
{
    return employees;
}

template <typename T>
void EmployeeManager<T>::set_employees(list<T> *employees)
{
    this->employees = employees;
}

template <typename T>
bool EmployeeManager<T>::add_employee(T t)
{
    if (get_employee(t.getEmployee_id()) || get_employee(t.getAccount()->getUsername()))
    {
        return false;
    }
    this->employees->push_back(t);
    return true;
}

template <typename T>
bool EmployeeManager<T>::add_employee(int branch_id)
{
    cout << "Add new employee: \n";
    if (add_employee(T::input(branch_id)))
    {
        cout << "Success\n";
        return true;
    }
    cout << "fail\n";
    return false;
}

template <typename T>
bool EmployeeManager<T>::remove_employee(int branch_id)
{
    return true;
}

template <typename T>
bool EmployeeManager<T>::remove_employee(T)
{
    return true;
}

template <typename T>
T *EmployeeManager<T>::pick_employee()
{
    int id;
    cout << "Enter id: ";
    cin >> id;
    cin.ignore();
    return get_employee(id);
}

template <typename T>
T *EmployeeManager<T>::get_employee(int id)
{
    for (typename list<T>::iterator it = employees->begin(); it != employees->end(); it++)
    {
        if (it->getEmployee_id() == id)
            return &*it;
    }
    return NULL;
}

template <typename T>
T *EmployeeManager<T>::get_employee(string username, string password)
{
    T *ptr = get_employee(username);
    if (!ptr)
    {
        return ptr;
    }
    if ((ptr->getAccount()->getPassword() == password))
    {
        return ptr;
    }
    return NULL;
}

template <typename T>
T *EmployeeManager<T>::get_employee(string username)
{
    for (typename list<T>::iterator it = employees->begin(); it != employees->end(); it++)
    {
        if (it->getAccount()->getUsername() == username)
            return &*it;
    }
    return NULL;
}

template <typename T>
bool EmployeeManager<T>::select_employee()
{
    return true;
}

template <typename T>
void EmployeeManager<T>::employees_list(list<T> lst)
{
    cout
        << setw(80) << setfill('*') << "" << endl
        << setfill(' ')
        << setw(7) << left << "|  id " << '|'
        << setw(7) << left << "branch" << '|';
    Person::render_person_title();
    cout
        << endl
        << setw(80) << setfill('*') << "" << endl
        << setfill(' ');

    for (auto it = lst.begin(); it != lst.end(); it++)
    {
        if (!&*it)
            continue;
        cout
            << setw(7) << left << "|" + to_string(it->getEmployee_id()) << '|'
            << setw(7) << left <<  to_string(it->getBranch_id()) << '|';
        Person::render_person((Person)*it);
        cout
            << endl
            << setw(80) << setfill('*') << "" << endl
            << setfill(' ');
    }
}

template <typename T>
void EmployeeManager<T>::manage_employee(int branch_id)
{
    int option;
    bool loop = true;
    while (loop)
    {
        print_option({"add customer",
                      "remove cusomer",
                      "view customer",
                      "customers list"

        });

        cin >> option;
        cin.ignore();
        switch (option)
        {
        case 1:
            clear();
            add_employee();
            wait();
            break;
        case 2:
            clear();
            remove_employee();
            wait();
            break;

        case 3:
            clear();
            select_employee();
            wait();
            break;
        case 4:
            clear();
            employees_list();
            wait();
            break;

        default:
            loop = false;
            break;
        }
    }

    return;
}