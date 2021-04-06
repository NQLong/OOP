#include "IngridientQuant.h"

using namespace std;
IngridientQuantity::IngridientQuantity(){}
IngridientQuantity::IngridientQuantity(Ingridient* ingri, double quantity){
    this->ingri = ingri;
    this->quantity = quantity;
}

IngridientQuantity::IngridientQuantity(const IngridientQuantity &ingriQuant)
{
    this->ingri = ingriQuant.ingri;
    this->quantity = ingriQuant.quantity;
}

IngridientQuantity &IngridientQuantity::operator=(const IngridientQuantity &ingriQuant)
{
    this->ingri = ingriQuant.ingri;
    this->quantity = ingriQuant.quantity;
    return *this;
}


Ingridient* IngridientQuantity::getIngri()
{
    return this->ingri;
}

void IngridientQuantity::setIngri(Ingridient* ingri)
{
    this->ingri = ingri;
}

double IngridientQuantity::getQuantity()
{
    return this->quantity;
}

void IngridientQuantity::setQuantity(double quantity)
{
    this->quantity = quantity;
}

string IngridientQuantity::toString()
{
    return "IngridientQuantity(ingridient = " + ingri->toString() + ", quantity = " + to_string(quantity) + ")";
}