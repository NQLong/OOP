#ifndef AC50C492_FCD2_4C61_942F_CBE443D3FCB7
#define AC50C492_FCD2_4C61_942F_CBE443D3FCB7

#include "Chef.h"

class ChefManage
{
    list<Chef> *cheves;

public:
    ChefManage();
    ~ChefManage();
    ChefManage(void *);

    int select_chef_id();

    list<Chef> *get_chefs();
    void set_chefs(list<Chef> *Chefs);

    bool add_chef(Chef);
    bool add_chef();
    bool remove_chef();
    bool remove_chef(Chef);
    Chef *pick_chef();
    Chef *get_chef(int id);
    bool select_chef();
    void chefs_list();
    void manage_chef();
};

#endif /* AC50C492_FCD2_4C61_942F_CBE443D3FCB7 */
