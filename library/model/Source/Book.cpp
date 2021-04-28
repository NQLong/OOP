#include "../Header/Book.h"

Book::Book() {}

Book::Book(string ISBN, string title, string publisher, list<Author *> authors, int year, const char *status)
{
    this->ISBN = ISBN;
    this->title = title;
    this->publisher = publisher;
    this->authors = authors;
    this->year = year;
    this->status = *status;
}

void Book::addAuthor(Author *author)
{
    this->authors.push_back(author);
}

bool Book::consistOfAuthor(Author *author)
{
    for (auto it = authors.cbegin(); it != authors.cend(); it++)
        if ((*it) == author)
            return true;
    return false;
}

ostream &operator<<(ostream &os, const Book &book)
{
    int count = 1;
    os
        << left << setw(11) << "ISBN"
        << ": " << book.ISBN << endl
        << left << setw(11) << "Title"
        << ": " << book.title << endl
        << left << setw(11) << "publisher"
        << ": " << book.publisher << endl
        << left << setw(11) << "Writed in"
        << ": " << book.year << endl
        << left << setw(11) << "status"
        << ": " << (book.status == 'l' ? "loaned" : "available") << endl
        << left << setw(11) << "Authors"
        << ": " << endl;
    ;
    string temp;
    for (auto it = book.authors.cbegin(); it != book.authors.cend(); it++)
    {
        os
            << setw(5)  << ""<< count++ << "." << endl;
        stringstream ss;
        ss << **it;
        while (getline(ss, temp))
            os << setw(5)  << "" << temp<<endl;
    }

    return os;
}

/*

Getter and setter
*/
string Book::getISBN()
{
    return this->ISBN;
}

void Book::setISBN(string ISBN)
{
    this->ISBN = ISBN;
}

string Book::getTitle()
{
    return this->title;
}

void Book::setTitle(string title)
{
    this->title = title;
}

string Book::getPublisher()
{
    return this->publisher;
}

void Book::setPublisher(string publisher)
{
    this->publisher = publisher;
}

list<Author *> Book::getAuthors()
{
    return this->authors;
}

void Book::setAuthors(list<Author *> authors)
{
    this->authors = authors;
}

int Book::getYear()
{
    return this->year;
}

void Book::setYear(int year)
{
    this->year = year;
}

char *Book::getStatus()
{
    return &this->status;
}

void Book::setStatus(const char *status)
{
    this->status = *status;
}
