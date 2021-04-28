#ifndef Customer_h_included
#define Customer_h_included

#include <bits/stdc++.h>
using namespace std;

class Customer
{
private:
    int id;
    string name;
    int discount;

public:
    Customer();
    
    Customer(int, string, int);

    int getId();

    void setId(int id);

    string getName();

    void setName(string name);

    int getDiscount();

    void setDiscount(int discount);

    friend ostream &operator<<(ostream &, const Customer &);
};

#endif