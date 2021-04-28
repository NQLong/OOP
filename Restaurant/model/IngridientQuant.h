#ifndef ingriquant_h
#define ingriquant_h

#include <bits/stdc++.h>
#include "ingridient.h"

class IngridientQuantity
{
private:
    Ingridient* ingri;
    double quantity;

public:
    IngridientQuantity();
    IngridientQuantity(const IngridientQuantity &);
    IngridientQuantity(Ingridient*, double);

    IngridientQuantity& operator=(const IngridientQuantity &);

    Ingridient* getIngri();
    void setIngri(Ingridient* ingri);

    double getQuantity();
    void setQuantity(double quantity);


    string toString();
};

#endif