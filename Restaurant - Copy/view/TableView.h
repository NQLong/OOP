#ifndef TABLEVIEW_INCLUDED
#define TABLEVIEW_INCLUDED

#include "../controller/restaurant.h"
#include "./GeneralView.h"

class TableView : private GeneralView
{

public:
    TableView();

    TableView(Restaurant *);

    void editTableView();

    bool createTableView();

    void filterTableView();
    
    void listTableView();

    void deleteTableView();

    void DetailView(Table *);
};

#endif