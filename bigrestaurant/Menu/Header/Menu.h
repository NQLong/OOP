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

// using namespace std;

#include "MenuSection.h"
class Menu

{
private:

    int menu_id = 0;
    string title;
    string description;
    list<MenuSection> menu_sections;

public:
    Menu();
    ~Menu();
    Menu(int id, string _title, string _description):
    menu_id(id), title(_title),description(_description){}
    Menu(int id, string _title, string _description,list<MenuSection> lst):
    menu_id(id), title(_title),description(_description), menu_sections(lst){}

    bool add_menu_section(MenuSection);
    bool add_menu_section();
    void print();

    static Menu inputMenu();

    MenuSection* getMenu_section(int id);
    MenuSection* getMenu_section(string title);
    
    int getMenu_id();
    void setMenu_id(int menu_id);
    string getTitle();
    void setTitle(string title);
    string getDescription();
    void setDescription(string description);
    list<MenuSection>* getMenu_sections();
    void setMenu_sections(list<MenuSection> menu_sections);

};

#endif /* DA38F2A4_5023_4EDB_882C_057B736DD1B0 */
