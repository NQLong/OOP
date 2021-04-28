#include "table.h"
#include <bits/stdc++.h>

using namespace std;

void Table::setId(int _id) {
    id=_id;
}
void Table::setMaxCapacity(int max) {
    maxCapacity = max;
}

int Table::getId(){
    return id;
}

int Table::getMaxCapacity(){
    return maxCapacity;
}

Table::Table(int id, int _capacity) {
    this -> id = id;
    maxCapacity = _capacity;
}

string Table::toString(){
    return "Table(id = "+ to_string(id) + ", max capacity =" + to_string(maxCapacity)+")";
}

Table::Table(){}