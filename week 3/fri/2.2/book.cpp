#include "book.h"

int Book::getQty()
{
    return this->qty;
}

void Book::setQty(int qty)
{
    this->qty = qty;
}

vector<Author> Book::getAuthor()
{
    return this->authors;
}

void Book::setAuthors(vector<Author> author)
{
    this->authors = author;
}

double Book::getPrice()
{
    return this->price;
}

void Book::setPrice(double price)
{
    this->price = price;
}

string Book::getName()
{
    return this->name;
}

void Book::setName(string name)
{
    this->name = name;
}
Book::Book()
{
}

Book::Book(string name, vector<Author> author, double price)
{
    this->authors = author;
    this->name = name;
    this->price = price;
}

Book::Book(string name, vector<Author> author, double price, int qty)
{
    this->authors = author;
    this->name = name;
    this->price = price;
    this->qty = qty;
}
string Book::toString()
{
    string temp = "";
    for (vector<Author>::iterator it = this->authors.begin(); it != this->authors.end(); it++)
    {
        temp += it->toString();
        if (it + 1 != this->authors.end())
            temp += ",";
    }
    return "Book[name=" + this->name + ",authors={" + temp + "},price=" + to_string(this->price) + ",qty=" + to_string(this->qty) + "]";
}

string Book::getAuthorNames(){
    string temp = "";
    for (vector<Author>::iterator it = this->authors.begin(); it != this->authors.end(); it++)
    {
        temp += it->getName();
        if (it + 1 != this->authors.end())
            temp += ",";
    }
}