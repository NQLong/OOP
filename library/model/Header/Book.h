/*
Book
---------------------------
-ISBN: string
-name: string
-authors: List<Author>
-year: int
-publisher: string
-status: char
-----------------------------
+getISBN() :string
+getName() :string
+getPublisher() :string
+getYear() : int
+getAuthors() : List<Author>
+getStatus():char

+setISBN(string):void
+setName(string):void
+setPublisher(string):void
+setYear(int):void
+setAuthors(List<Author>):void
+getStatus:
*/
#ifndef Book_included
#define Book_included

#include <string>
#include <sstream>

#include <iomanip>
#include "Author.h"
#include <list>

using namespace std;

class Book
{
private:
    string ISBN;
    string title;
    string publisher;
    list<Author *> authors;
    int year;
    char status;

public:
    Book();
    Book(string, string, string, list<Author *>, int, const char *);

    string getISBN();
    string getName();
    string getPublisher();
    int getYear();
    list<Author *> getAuthors();

    char *getStatus();

    string getTitle();

    void setISBN(string);
    void setName(string);
    void setPublisher(string);
    void setYear(int);
    void setAuthors(list<Author *>);
    void setStatus(const char *);
    void setTitle(string);
    void addAuthor(Author *);

    bool consistOfAuthor(Author *);
    friend ostream &operator<<(ostream &os, const Book &);
};

#endif