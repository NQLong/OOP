#ifndef book_h_included
#define book_h_included

#include <bits/stdc++.h>
#include "author.h"
using namespace std;

class Book
{
private:
    vector<Author> authors;
    double price;
    string name;
    int qty = 0;

public:
    int getQty();

    void setQty(int qty);

    vector<Author> getAuthor();

    void setAuthors(vector<Author> author);

    double getPrice();

    void setPrice(double price);

    string getName();

    void setName(string name);

    Book();

    Book(string, vector<Author>, double);

    Book(string, vector<Author>, double, int);

    string toString();

    string getAuthorNames();
};

#endif