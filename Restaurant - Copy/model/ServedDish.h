#ifndef SERVEDDISH_H_INCLUDED
#define SERVEDDISH_H_INCLUDED

#include <bits/stdc++.h>
#include "Dish.h"
using namespace std;

class ServedDish
{
private:
    Dish* dish;
    int number;

public:
    ServedDish();
    ServedDish(Dish*, int);
    ServedDish(const ServedDish&);
    ServedDish& operator=(const ServedDish&);

    void setDish(Dish*);
    void setNumber(int);
    int getNumber();
    Dish* getDish();

    string toString();
};
#endif