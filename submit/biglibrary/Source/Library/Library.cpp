#include "../../Header/Library/Library.h"

Library::~Library() {}
Library::Library()
{
    catalog = Catalog((void*)this);
}

bool Library::has_book(BookItem *book)
{
    for (auto it = books.begin(); it != books.end(); it++)
        if (*it == book)
            return true;
    return false;
}

bool Library::remove_book(BookItem *book)
{
    books.remove(book);
    return true;
}

bool Library::add_book(BookItem *book)
{
    books.push_back(book);
    return true;
}

list<BookItem *>* Library::getBooks()
{
    return &books;
}
void Library::setBooks(list<BookItem *> books)
{
    this->books = books;
}

Catalog *Library::get_cactalog()
{
    return &this->catalog;
}

void Library::set_catalog(Catalog catalog)
{
    this->catalog = catalog;
}