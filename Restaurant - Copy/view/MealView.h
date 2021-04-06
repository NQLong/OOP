#ifndef MEALVIEW_INCLUDED
#define MEALVIEW_INCLUDED

#include "../controller/restaurant.h"
#include "./GeneralView.h"

class MealView : private GeneralView
{

public:
    MealView();

    MealView(Restaurant *);

    void editMealView();

    bool createMealView();

    void filterMealView();
    
    void listMealView();

    void deleteMealView();

    void DetailView(Meal *);

    void cancleMealView();

    void confirmMealView();
};

#endif