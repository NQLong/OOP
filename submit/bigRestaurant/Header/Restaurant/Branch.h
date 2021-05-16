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
#include "../../Header/Constraint/constraint.h"
#include "../Menu/Menu.h"

class Branch
{
private:
    int branch_id; 
    string name;
    Address location;
    Kitchen kitchen;
    
    int menu_id = -1;


    static int new_id;
public:
    Branch();
    Branch(string _name, Address _location) 
    :branch_id(new_id++), name(_name), location(_location) {}
    Branch(string _name, Address _location, Kitchen _kitchen) 
    :branch_id(new_id++), name(_name), location(_location), kitchen(_kitchen) {}
    Branch(string _name, Address _location, Kitchen _kitchen, int _menu_id) 
    :branch_id(new_id++), name(_name), location(_location), kitchen(_kitchen), menu_id(_menu_id) {}
    
    ~Branch() {}

    static Branch inputBranch();

    bool add_table_chart();

    bool modify_menu();
    bool add_menu();
    Menu* get_menu();

    int getBranch_id();
    int get_id();
    void setBranch_id(int branch_id);

    string getName();
    void setName(string name);

    Address* getLocation();

    void setLocation(Address location);

    Kitchen* getKitchen();
    void setKitchen(Kitchen kitchen);

    int getMenu_id();
    void setMenu_id(int menu_id);

    
};

#endif /* A339ABF1_A3D1_4BE9_B9CB_4AD67E24FF65 */
