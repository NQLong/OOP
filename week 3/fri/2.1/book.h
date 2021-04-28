#ifndef book_h_included
#define book_h_included

#include <bits/stdc++.h>
#include "author.h"
using namespace std;


class Book
{
private:
    Author author;
    double price;
    string name;
    int qty = 0;

public:
    int getQty();

    void setQty(int qty);

    Author getAuthor();

    void setAuthor(Author author);

    double getPrice();

    void setPrice(double price);

    string getName();

    void setName(string name);

    Book();

    Book(string, Author, double);

    Book(string, Author, double, int);

    string toString();
};

#endif