#include <bits/stdc++.h>

#include "Ingridient.h"

using namespace std;

Ingridient::Ingridient() {}

Ingridient::Ingridient(string name, string measure, double quantity)
{
    this->name = name;
    this->measureUnit = measure;
    this->stock = quantity;
}

Ingridient::Ingridient(const Ingridient &ingri)
{
    this->name = ingri.name;
    this->stock = ingri.stock;
    this->measureUnit = ingri.measureUnit;
}

Ingridient &Ingridient::operator=(const Ingridient &ingri)
{
    this->name = ingri.name;
    this->stock = ingri.stock;
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

double Ingridient::getStock()
{
    return stock;
}

void Ingridient::setName(string name)
{
    this->name = name;
}
void Ingridient::setMeasureUnit(string _measure)
{
    measureUnit = _measure;
}
void Ingridient::setStock(double q)
{
    stock = q;
}

string Ingridient::toString()
{
    return "Ingridient(name = " + name + ",measureUnit = " + measureUnit + ",quantity = " + to_string(stock) + ")";
}

// void Ingridient::print(){

// }
