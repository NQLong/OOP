#include "book.h"

int Book::getQty()
{
    return this->qty;
}

void Book::setQty(int qty)
{
    this->qty = qty;
}

Author Book::getAuthor()
{
    return this->author;
}

void Book::setAuthor(Author author)
{
    this->author = author;
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
Book::Book(){

}

Book::Book(string name, Author author, double price){
    this->author = author;
    this->name = name;
    this->price = price;
}


Book::Book(string name, Author author, double price, int qty){
    this->author = author;
    this->name = name;
    this->price = price;
    this -> qty = qty;

}
string Book::toString(){
    return "Book[name="+this->name+","+this->author.toString()+",price="+to_string(this->price)+",qty="+to_string(this->qty)+"]";
}