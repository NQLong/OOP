#ifndef DISHVIEW_INCLUDED
#define DISHVIEW_INCLUDED

#include "./GeneralView.h"

class DishView : private GeneralView
{
public:
    DishView();
    DishView(Restaurant *);
    bool createDishView();
    void filterDishView();
    void DetailView(Dish *);
    void listDishView();
    void deleteDishView();
};

#endif