#ifndef F85855CC_C9F8_4EBC_95CF_F877C6F132A6
#define F85855CC_C9F8_4EBC_95CF_F877C6F132A6

#include "../Catalog/Catalog.h"

class Library
{
private:
    Catalog catalog;
    list<BookItem *> books;


public:
    Library();
    ~Library();
    bool add_book(BookItem*);
    bool remove_book(BookItem*);
    bool has_book(BookItem*);

    list<BookItem *>* getBooks();
    void setBooks(list<BookItem *> books);

    Catalog *get_cactalog();
    void set_catalog(Catalog);
};

#endif /* F85855CC_C9F8_4EBC_95CF_F877C6F132A6 */
