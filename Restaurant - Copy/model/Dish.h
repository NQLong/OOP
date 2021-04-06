#ifndef DISH_H_INCLUDED
#define DISH_H_INCLUDED
#include <bits/stdc++.h>
#include "Ingridient.h"
#include "IngridientQuant.h"

using namespace std;

class Dish
{
private:
    string name;
    int id;
    vector<IngridientQuantity> ingridientList;
    double price;

public:
    Dish();
    Dish(string, int, vector<IngridientQuantity>, double);
    Dish(const Dish &);

    Dish &operator=(const Dish &);

    void setName(string);
    void setId(int);
    void setIngris(vector<IngridientQuantity>);

    void addIngri(IngridientQuantity);
    
    double getPrice();
    void setPrice(double price);

    string getName();
    int getId();
    vector<IngridientQuantity> getIngriList();

    string toString();

    bool consistOfIngridient(Ingridient *);

};
#endif