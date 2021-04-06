#ifndef INGRIDIENT_H_INCLUDED
#define INGRIDIENT_H_INCLUDED
#include <bits/stdc++.h>

using namespace std;

class Ingridient
{
private:
    string name;
    string measureUnit;
    double stock;

public:
    Ingridient();
    Ingridient(string, string, double);
    Ingridient(const Ingridient &);
    Ingridient &operator=(const Ingridient &);

    string getName();
    string getMeasureUnit();
    double getStock();

    void setName(string);
    void setMeasureUnit(string);
    void setStock(double);

    string toString();
};
#endif