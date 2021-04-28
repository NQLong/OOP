#include <bits/stdc++.h>

#include "ServedDish.h"

ServedDish::ServedDish(const ServedDish &other)
{
    this->dish = other.dish;
    this->quantity = other.quantity;
}
ServedDish &ServedDish::operator=(const ServedDish &other)
{
    this->dish = other.dish;
    this->quantity = other.quantity;
    return *this;
}

Dish *ServedDish::getDish() { return dish; }

int ServedDish::getQuantity() { return quantity; }

void ServedDish::setDish(Dish *_dish)
{
    dish = _dish;
}

void ServedDish::setQuantity(int n)
{
    quantity = n;
}

ServedDish::ServedDish(Dish *_dish, int n)
{
    dish = _dish;
    quantity = n;
}

string ServedDish::toString()
{
    return "ServedDish(dish = " + dish->toString() + ", quantity = " + to_string(quantity) + ")";
}