#ifndef D28ED796_B7FD_48FD_900B_B4F3363E466F
#define D28ED796_B7FD_48FD_900B_B4F3363E466F

#include "MenuItem.h"
#include "../../Header/Manage/ListManager.h"
#include <list>
class MenuSection
// : public ListManager<MenuItem>
{
private:
    int menu_section_id = -1;
    string title;
    string description;
    list<MenuItem> menu_items;

    static int new_id;

public:
    static string class_name;
    friend bool operator==(const MenuSection &lhs, const MenuSection &rhs)
    {
        return (
            (lhs.menu_section_id == rhs.menu_section_id) &&
            (lhs.title == rhs.title) &&
            (lhs.menu_items == rhs.menu_items) &&
            (lhs.description == rhs.description) &&
            true

        );
    }
    MenuSection();
    ~MenuSection();
    MenuSection(string _title, string _description);
    MenuSection(string _title, string _description, list<MenuItem> items);

    MenuItem *get_element(int id);
    bool add_element();

    bool add_menu_item(MenuItem);
    bool add_menu_item();
    bool remove_menu_item(MenuItem);
    bool remove_menu_item();
    MenuItem *pick_menu_item();
    MenuItem *get_menu_item(int id);
    void menu_items_list();
    bool select_menu_item();

    bool modify_menu_item();
    int itemIdSelection();
    bool modify_menu_section();

    static MenuSection input(int);

    int getMenu_section_id();
    int get_id();
    void setMenu_section_id(int menu_section_id);
    string getTitle();
    void setTitle(string title);
    string getDescription();
    void setDescription(string description);
    list<MenuItem> *getMenu_items();
    void setMenu_items(list<MenuItem> menu_items);

    friend ostream &operator<<(ostream &, const MenuSection &);
    friend ostream &operator<<(ostream &, const list<MenuSection> &);
};

#endif /* D28ED796_B7FD_48FD_900B_B4F3363E466F */
