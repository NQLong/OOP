#include "../Header/Catalog.h"

Catalog::Catalog() {}

Catalog::Catalog(list<Book *> books)
{
    this->books = books;
}

void Catalog::setBooks(list<Book *> books)
{
    this->books = books;
}

void Catalog::addBook(Book *book)
{
    books.push_back(book);
}
list<Book *> Catalog::getBooks()
{
    return this->books;
}

Book *Catalog::getBook(string ISBN)
{
    int n = books.size();
    if (n > 0)
        for (auto it = books.begin(); it != books.end(); it++)
            if ((*it)->getISBN() == ISBN)
                return *it;

    return NULL;
    return NULL;
}

list<Book *> Catalog::getBooks(string title)
{
    list<Book *> res;
    for (auto it = books.cbegin(); it != books.cend(); it++)
        if ((*it)->getTitle() == title)
            res.push_back(*it);

    return res;
}

list<Book *> Catalog::getBooks(Author *author)
{
    list<Book *> res;
    for (auto it = books.cbegin(); it != books.cend(); it++)
        if ((*it)->consistOfAuthor(author))
            res.push_back(*it);

    return res;
}

void Catalog::removeBook(Book *book)
{
    books.remove(book);
}