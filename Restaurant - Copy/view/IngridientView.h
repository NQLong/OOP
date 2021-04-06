#ifndef INGRIDIENTVIEW_INCLUDED
#define INGRIDIENTVIEW_INCLUDED

#include "../controller/restaurant.h"
#include "./GeneralView.h"

class IngridientView : private GeneralView
{

public:
    IngridientView();

    IngridientView(Restaurant *);

    void editIngridientView();

    bool createIngridientView();

    void filterIngridientView();
    
    void listIngridientView();

    void deleteIngridientView();

    void DetailView(Ingridient *);
};

#endif