#include <bits/stdc++.h>
#include "Dish.h"

using namespace std;

Dish::Dish() {}

Dish::Dish(string _name, int _id, vector<IngridientQuantity> _ingriList, double price)
{
    name = _name;
    id = _id;
    ingridientList = _ingriList;
    this->price = price;
}

void Dish::setId(int _id)
{
    id = _id;
}

void Dish::setName(string _name)
{
    name = _name;
}

void Dish::setIngris(vector<IngridientQuantity> _ingriList)
{
    ingridientList = _ingriList;
}

void Dish::addIngri(IngridientQuantity _ingri)
{
    vector<IngridientQuantity>::iterator end = ingridientList.end();
    ingridientList.insert(end, _ingri);
}

int Dish::getId()
{
    return id;
}

string Dish::getName()
{
    return name;
}

vector<IngridientQuantity> Dish::getIngriList()
{
    return ingridientList;
}

string Dish::toString()
{
    string temp = "[";
    for (vector<IngridientQuantity>::iterator i = ingridientList.begin(); i != ingridientList.end(); i++)
    {
        temp += (*i).toString();
        if (i + 1 != ingridientList.end())
            temp += ",";
    }
    temp += "]";
    return "Dish(id = " + to_string(id) + ",name = " + name + ", IngridientList =" + temp + ")";
}

Dish::Dish(const Dish &_dish)
{
    this->id = _dish.id;
    this->name = _dish.name;
    this->ingridientList = _dish.ingridientList;
    this->price = _dish.price;
}

Dish &Dish::operator=(const Dish &_dish)
{
    this->price = _dish.price;
    this->id = _dish.id;
    this->name = _dish.name;
    this->ingridientList = _dish.ingridientList;
    return *this;
}

double Dish::getPrice()
{
    return this->price;
}

void Dish::setPrice(double price)
{
    this->price = price;
}

bool Dish::consistOfIngridient(Ingridient *ingridient)
{
    for (vector<IngridientQuantity>::iterator it = this->ingridientList.begin(); it != this->ingridientList.end(); it++)
    {
        if (it->getIngri() == ingridient)
            return true;
    }
    return false;
}