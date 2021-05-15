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
#include "../../Header/Manage/MSmanager.h"

class Menu
// : public ListManager<MenuSection>
{
private:
    int menu_id = -1;
    int branch_id = -1;

    string title;
    string description;
    list<MenuSection> menu_sections;

    static int new_id;

public:
    static string class_name;
    friend bool operator==(const Menu &lhs, const Menu &rhs)
    {
        return (
            (lhs.menu_id == rhs.menu_id) &&
            (lhs.branch_id == rhs.branch_id) &&
            (lhs.title == rhs.title) &&
            (lhs.description == rhs.description) &&
            (lhs.menu_sections == rhs.menu_sections) &&
            true

        );
    }
    Menu();
    ~Menu();
    Menu(string _title, string _description, int);
    Menu(string _title, string _description, list<MenuSection> lst, int);

    bool add_element();
    MenuSection* pick_element();
    MenuSection *get_element(int id);


    void print(int);
    void modify();

    static Menu input(int);

    int section_id_seclection();

    int getMenu_id();
    int get_id();
    void setMenu_id(int menu_id);
    string getTitle();
    void setTitle(string title);
    string getDescription();
    void setDescription(string description);
    list<MenuSection> *getMenu_sections();
    void setMenu_sections(list<MenuSection> menu_sections);
    int getBranch_id();
    void setBranch_id(int branch_id);

    friend ostream &operator<<(ostream &, const Menu &);
    friend ostream &operator<<(ostream &, const list<Menu> &);
};

#endif /* DA38F2A4_5023_4EDB_882C_057B736DD1B0 */
