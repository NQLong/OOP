#ifndef CLIENTVIEW_INCLUDED
#define CLIENTVIEW_INCLUDED

#include "../controller/restaurant.h"
#include "./GeneralView.h"

class ClientView : private GeneralView
{

public:
    ClientView();
    ClientView(Restaurant *);

    bool createClientView();
    void filterClientView();
    void listClientView();

    void deleteClientView();

    void DetailView(Client *);
};

#endif