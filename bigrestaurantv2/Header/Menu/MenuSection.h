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
    int menu_section_id = -1;
    string title;
    string description;
    list<MenuItem> menu_items;

public:
    MenuSection();
    ~MenuSection();
    MenuSection(int _menu_section_id,string _title,string _description):
    menu_section_id(_menu_section_id), title(_title), description(_description){}

    bool add_menu_item(MenuItem);
    bool modify_menu_item();
    bool add_menu_item();

    int itemIdSelection();
    
    bool modify_menu_section();
    
    static MenuSection input_menu_section();

    int getMenu_section_id();
    void setMenu_section_id(int menu_section_id);
    string getTitle();
    void setTitle(string title);
    string getDescription();
    void setDescription(string description);
    list<MenuItem>* getMenu_items();
    void setMenu_items(list<MenuItem> menu_items);
    
    MenuItem* getMenu_item(int id);

    friend ostream& operator <<(ostream&, const MenuSection&);
};

#endif /* D28ED796_B7FD_48FD_900B_B4F3363E466F */
