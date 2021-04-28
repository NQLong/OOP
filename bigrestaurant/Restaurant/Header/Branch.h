#ifndef A339ABF1_A3D1_4BE9_B9CB_4AD67E24FF65
#define A339ABF1_A3D1_4BE9_B9CB_4AD67E24FF65
// class Branch:
//     def __init__(self, name, location, kitchen):
//         self.__name = name
//         self.__location = location
//         self.__kitchen = kitchen

//     def add_table_chart(self):
//         None
#include "Kitchen.h"
#include "../../Constraint/constraint.h"
#include "../../Menu/Header/Menu.h"

class Branch
{
private:
    int branch_id; 
    string name;
    Address location;
    Kitchen kitchen;
    Menu menu;


    

public:
    Branch();
    Branch(int _id,string _name, Address _location) 
    :branch_id(_id), name(_name), location(_location) {}
    Branch(int _id,string _name, Address _location, Kitchen _kitchen) 
    :branch_id(_id), name(_name), location(_location), kitchen(_kitchen) {}
    Branch(int _id,string _name, Address _location, Kitchen _kitchen, Menu _menu) 
    :branch_id(_id), name(_name), location(_location), kitchen(_kitchen), menu(_menu) {}
    
    ~Branch() {}

    static Branch inputBranch();

    bool add_table_chart();


    int getBranch_id();
    void setBranch_id(int branch_id);

    string getName();
    void setName(string name);

    Address* getLocation();

    void setLocation(Address location);

    Kitchen* getKitchen();
    void setKitchen(Kitchen kitchen);

    Menu* getMenu();
    void setMenu(Menu menu);
};

#endif /* A339ABF1_A3D1_4BE9_B9CB_4AD67E24FF65 */
