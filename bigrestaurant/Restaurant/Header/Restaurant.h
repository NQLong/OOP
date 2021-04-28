#ifndef A128E549_0264_424E_9887_63A9EE01FC3D
#define A128E549_0264_424E_9887_63A9EE01FC3D
// class Restaurant:
//     def __init__(self, name):
//         self.__name = name
//         self.__branches = []

//     def add_branch(self, branch):
//         None
#include <iostream>
#include <list>

#include "Branch.h"

#include "../../Actor/Header/Employee.h"
#include "../../Actor/Header/Manager.h"
#include "../../Actor/Header/Waiter.h"
#include "../../Actor/Header/Chef.h"
#include "../../Actor/Header/Receptionist.h"

#include "../../Actor/Header/Customer.h"

class Restaurant
{
private:
    static string name;
    static list<Branch> branches;
    static list<Employee *> employees;

public:
    Restaurant() {}
    Restaurant(string _name);

    static bool addBranch();
    static bool addBranch(Branch);
    bool addEmployee();

    static bool addEmployee(Employee *);
    static bool addEmployee(EmployeeType);

    /*getter & setter*/
    static Employee *getEmployee(string username, string password, EmployeeType, AccountStatus);
    static Employee *getEmployee(string username, string password, EmployeeType);
    static Employee *getEmployee(string username);
    static Employee *getEmployee(int id);

    static Branch *getBranch(string name);
    static Branch *getBranch(int id);

    static string getName();
    static void setName(string name);

    static list<Branch> *getBranches();
    static void setBranches(list<Branch> branches);

    list<Employee *> getEmployees();
    void setEmployees(list<Employee *> employees);
};
#endif /* A128E549_0264_424E_9887_63A9EE01FC3D */
