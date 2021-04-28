#ifndef INGRIDIENT_H_INCLUDED
#define INGRIDIENT_H_INCLUDED
#include <bits/stdc++.h>


using namespace std;

class Ingridient {
    private:
        string name;
        string measureUnit;
        double quantity;

    public:

        Ingridient();
        Ingridient(string,string,double);
        Ingridient(const Ingridient&);
        Ingridient& operator=(const Ingridient&);
        string getName();
        string getMeasureUnit();
        double getQuantity();
        void setName(string);
        void setMeasureUnit(string);
        void setQuantity(double);
        string toString();
};
#endif