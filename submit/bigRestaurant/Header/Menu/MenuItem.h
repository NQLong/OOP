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

    static int new_id;

public:
    static string class_name;
    friend bool operator==(const MenuItem &lhs, const MenuItem &rhs)
    {
        return (
            (lhs.menu_item_id == rhs.menu_item_id) &&
            (lhs.title == rhs.title) &&
            (lhs.description == rhs.description) &&
            (lhs.price == rhs.price) &&
            true

        );
    }
    MenuItem();
    ~MenuItem();
    MenuItem(string _title, string _description, double _price)
        : menu_item_id(new_id++), title(_title), description(_description), price(_price) {}

    static MenuItem input(int);
    void modify();
    friend ostream &operator<<(ostream &os, const list<MenuItem> lst);

    bool update_price(double);

    int getMenu_item_id();
    int get_id();
    void setMenu_item_id(int menu_item_id);
    string getTitle();
    void setTitle(string title);
    string getDescription();
    void setDescription(string description);
    double getPrice();
    void setPrice(double price);
    friend ostream &operator<<(ostream &, const MenuItem &);
};
#endif /* A10556A3_9DFD_426A_A053_89F632AF94C0 */
