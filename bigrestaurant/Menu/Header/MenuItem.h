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

#include <string>
using namespace std;
class MenuItem
{
private:
    int menu_item_id;
    string title;
    string description;
    double price;

public:
    bool update_price(double);
};
#endif /* A10556A3_9DFD_426A_A053_89F632AF94C0 */
