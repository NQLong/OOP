#ifndef GENERALVIEW_INCLUDED
#define GENERALVIEW_INCLUDED

#include "../controller/restaurant.h"

void clearCin();

class GeneralView
{
protected:
    Restaurant *controller;

public:
    GeneralView();
    GeneralView(const GeneralView &);
    GeneralView(Restaurant *);

    Restaurant *getController();

    void setController(Restaurant *controller);
};

#endif