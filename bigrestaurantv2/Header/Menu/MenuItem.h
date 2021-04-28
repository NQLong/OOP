#ifndef A10556A3_9DFD_426A_A053_89F632AF94C0
#define A10556A3_9DFD_426A_A053_89F632AF94C0
// class MenuItem:
//     def __init__(self, id, title, description, price):
//         self.__menu_item_id = id
//         self.__title = title
//         self.__description = description
//         self.__price = price

//     def update_price(self, price):
//         None

#include <iostream>
#include <iomanip>
#include <string>

#include "../Constraint/constraint.h"

using namespace std;
class MenuItem
{
private:
    int menu_item_id;
    string title;
    string description;
    double price;


    

public:
    MenuItem();
    ~MenuItem();
    MenuItem(int id,string _title, string _description,double _price):
    menu_item_id(id),title(_title), description(_description), price(_price){}

    static MenuItem input_menu_item();
    bool update_price(double);

    int getMenu_item_id();
    void setMenu_item_id(int menu_item_id);
    string getTitle();
    void setTitle(string title);
    string getDescription();
    void setDescription(string description);
    double getPrice();
    void setPrice(double price);
    friend ostream& operator <<(ostream&, const MenuItem&);
};
#endif /* A10556A3_9DFD_426A_A053_89F632AF94C0 */
