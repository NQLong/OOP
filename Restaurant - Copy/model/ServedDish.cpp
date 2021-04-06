#include <bits/stdc++.h>

#include "ServedDish.h"

ServedDish::ServedDish(const ServedDish &other)
{
    this->dish = other.dish;
    this->number = other.number;
}
ServedDish &ServedDish::operator=(const ServedDish &other)
{
    this->dish = other.dish;
    this->number = other.number;
    return *this;
}

Dish *ServedDish::getDish() { return dish; }

int ServedDish::getNumber() { return number; }

void ServedDish::setDish(Dish *_dish)
{
    dish = _dish;
}

void ServedDish::setNumber(int n)
{
    number = n;
}

ServedDish::ServedDish(Dish *_dish, int n)
{
    dish = _dish;
    number = n;
}

string ServedDish::toString()
{
    return "ServedDish(dish = " + dish->toString() + ", quantity = " + to_string(number) + ")";
}