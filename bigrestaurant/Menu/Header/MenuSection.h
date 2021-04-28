#ifndef D28ED796_B7FD_48FD_900B_B4F3363E466F
#define D28ED796_B7FD_48FD_900B_B4F3363E466F
// class MenuSection:
//     def __init__(self, id, title, description):
//         self.__menu_section_id = id
//         self.__title = title
//         self.__description = description
//         self.__menu_items = []

//     def add_menu_item(self, menu_item):
//         None

#include "MenuItem.h"
#include <list>
class MenuSection
{
private:
    int menu_section_id;
    string title;
    string description;
    list<MenuItem> menu_items;

public:
    bool add_menu_item(MenuItem);
};

#endif /* D28ED796_B7FD_48FD_900B_B4F3363E466F */
