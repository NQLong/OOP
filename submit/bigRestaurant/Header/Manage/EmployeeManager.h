#ifndef DB2EF093_35A2_446D_B71F_D84DAFBBBAB0
#define DB2EF093_35A2_446D_B71F_D84DAFBBBAB0
#include "ListManager.h"

template <typename T>
class EmployeeManager
    : public ListManager<T>
{
public:
    EmployeeManager(void* ptr);
    ~EmployeeManager(){}

    T* get_employee(string username, string password);
    
};
#include "EmployeeManager.cpp"

#endif /* DB2EF093_35A2_446D_B71F_D84DAFBBBAB0 */
