#ifndef TABLE_H_INCLUDED
#define TABLE_H_INCLUDED
#include <bits/stdc++.h>

using namespace std;

class Table
{
private:
    int id;
    int maxCapacity;

public:
    Table();
    Table(int,int);
    void setId(int);
    void setMaxCapacity(int);
    int getId();  
    int getMaxCapacity();
    string toString();
};
#endif