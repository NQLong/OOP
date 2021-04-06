#ifndef WAITERVIEW_INCLUDED
#define WAITERVIEW_INCLUDED

#include "../controller/restaurant.h"
#include "./GeneralView.h"

class WaiterView : private GeneralView
{

public:
    WaiterView();

    WaiterView(Restaurant *);

    void editWaiterView();

    bool createWaiterView();

    void filterWaiterView();
    
    void listWaiterView();

    void deleteWaiterView();

    void DetailView(Waiter *);
};

#endif