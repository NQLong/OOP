#include "../Header/BookController.h"

BookController::BookController() {}
BookController::~BookController() {}

int BookController::createBook(string ISBN, string title,
                               string publisher, list<string> authorsName, int year)
{
    Catalog *catalog = data->getCatalog();

    if (catalog->getBook(ISBN))
        return EXISTED_BOOK;
    list<Author *> lst;
    for (auto it = authorsName.cbegin(); it != authorsName.end(); it++)
    {
        Author *author_ptr = data->getAuthor(*it);
        if (!author_ptr)
            return NON_EXISTED_AUTHOR;
        lst.push_back(author_ptr);
    }
    data->getCatalog()->addBook(new Book(ISBN, title, publisher, lst, year, "a"));
    return SUCCESS;
}

list<Book *> BookController::allBooks()
{
    return data->getCatalog()->getBooks();
}

list<Book *> BookController::allBooksName(string name)
{
    return data->getCatalog()->getBooks(name);
}
Book *BookController::bookISBN(string ISBN)
{
    return data->getCatalog()->getBook(ISBN);
}


