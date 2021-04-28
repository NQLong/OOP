#ifndef book_h_included
#define book_h_included

#include <bits/stdc++.h>
#include "author.h"
using namespace std;

class Book
{
private:
    string ISBN;



    Author author;
    double price;
    string name;
    int qty = 0;

public:
    string getISBN();


    void setISBN(string ISBN);

    int getQty();

    void setQty(int qty);

    Author getAuthor();

    void setAuthor(Author author);

    double getPrice();

    void setPrice(double price);

    string getName();

    void setName(string name);

    string getAuthorName();

    Book();

    Book(string ,string, Author, double);

    Book(string,string, Author, double, int);

    string toString();

    friend ostream& operator<<(ostream& os, const Book& book);
 
};

#endif