#ifndef A727F149_B296_4C7D_952D_E016C577471C
#define A727F149_B296_4C7D_952D_E016C577471C
// class Kitchen:
//     def __init__(self, name):
//         self.__name = name
//         self.__chefs = []

//     def assign_chef(self, chef):
//         None
#include <iostream>
#include <list>
#include "../Actor/Chef.h"
using namespace std;

class Kitchen
{
private:
    string name;

public:
    Kitchen(){}
    ~Kitchen();
    Kitchen(string _name) : name(_name) {}

    bool assign_chef(Chef);
    
    string getName();
    void setName(string name);
    // list<Chef> getChefs();
    // void setChefs(list<Chef> chefs);

    static Kitchen inputKitchen();
};

#endif /* A727F149_B296_4C7D_952D_E016C577471C */
