#include <bits/stdc++.h>

#include "ingridient.h"

using namespace std;

Ingridient::Ingridient(){}

Ingridient::Ingridient(string name, string measure, double quantity)
{
    this->name = name;
    this->measureUnit = measure;
    this->quantity = quantity;
}

Ingridient::Ingridient(const Ingridient &ingri)
{
    this->name = ingri.name;
    this->quantity = ingri.quantity;
    this->measureUnit = ingri.measureUnit;
}

Ingridient &Ingridient::operator=(const Ingridient &ingri)
{
    this->name = ingri.name;
    this->quantity = ingri.quantity;
    this->measureUnit = ingri.measureUnit;
    return *this;
}

string Ingridient::getName()
{
    return name;
}

string Ingridient::getMeasureUnit()
{
    return measureUnit;
}

double Ingridient::getQuantity()
{
    return quantity;
}

void Ingridient::setName(string name)
{
    this->name = name;
}
void Ingridient::setMeasureUnit(string _measure)
{
    measureUnit = _measure;
}
void Ingridient::setQuantity(double q)
{
    quantity = q;
}

string Ingridient::toString()
{
    return "Ingridient(name = " + name + ",measureUnit = " + measureUnit + ",quantity = " + to_string(quantity) + ")";
}
