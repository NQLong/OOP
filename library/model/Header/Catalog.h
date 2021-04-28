/*
Catalog
-----------------------------------
-books: List<Book>


-----------------------------------
+setBooks(List<Book>):void
+addBook(Book):void
+getBooks():List<Book>
+getBooks(name:string):List<Book>
+getBooks(author:Author):List<Book>
+getBook(ISBN:string):Book

*/

#ifndef Catalog_included
#define Catalog_included

#include <string>
#include <istream>
#include <list>

#include "Book.h"
#include "Author.h"

using namespace std;

class Catalog
{
private:
    list<Book *> books;

public:
    Catalog();
    Catalog(list<Book *>);

    void setBooks(list<Book *>);
    void addBook(Book *);

    list<Book *> getBooks();
    list<Book *> getBooks(string);
    list<Book *> getBooks(Author *);
    
    Book *getBook(string);
    
    void removeBook(Book*);
    
};

#endif