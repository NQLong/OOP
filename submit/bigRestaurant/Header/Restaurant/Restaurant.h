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

#include "../Manage/ListManager.h"

class Restaurant
    : public ListManager<Branch>
{
private:
    string name;
    list<Branch> branches;

public:
    Restaurant() ;
    ~Restaurant() ;
    Restaurant(string _name);
    Restaurant(string _name, list<Branch> branches);

    string get_name();
    void set_name(string name);

    list<Branch> *get_branches();
    void set_branches(list<Branch>);
};
#endif /* A128E549_0264_424E_9887_63A9EE01FC3D */
