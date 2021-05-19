#ifndef DA38F2A4_5023_4EDB_882C_057B736DD1B0
#define DA38F2A4_5023_4EDB_882C_057B736DD1B0
// class Menu:
//     def __init__(self, id, title, description):
//         self.__menu_id = id
//         self.__title = title
//         self.__description = description
//         self.__menu_sections = []

//     def add_menu_section(self, menu_section):
//         None

//     def print(self):
//         None
#include <iostream>
#include <iomanip>
#include <list>
// using namespace std;

#include "MenuSection.h"
class Menu

{
private:
    int menu_id = -1;
    int branch_id = -1;

    string title;
    string description;
    list<MenuSection> menu_sections;
    static list<Menu *> menus;

public:
    Menu();
    ~Menu();
    Menu(int id, string _title, string _description) : menu_id(id), title(_title), description(_description) {}
    Menu(int id, string _title, string _description, list<MenuSection> lst) : menu_id(id), title(_title), description(_description), menu_sections(lst) {}

    void print(int);

    static void addMenu(Menu *);
    static Menu *getMenu(int id);
    static list<Menu *> getMenus();



    bool add_menu_section(MenuSection);
    bool add_menu_section();

    bool modify_menu();
    bool modify_menu_section();

    static Menu inputMenu();

    MenuSection *getMenu_section(int id);
    MenuSection *getMenu_section(string title);

    int getMenu_id();
    void setMenu_id(int menu_id);
    string getTitle();
    void setTitle(string title);
    string getDescription();
    void setDescription(string description);
    list<MenuSection> *getMenu_sections();
    void setMenu_sections(list<MenuSection> menu_sections);
    int getBranch_id();
    void setBranch_id(int branch_id);

    int sectionIdSeclection();
    friend ostream& operator <<(ostream&, const Menu&);
};

#endif /* DA38F2A4_5023_4EDB_882C_057B736DD1B0 */
