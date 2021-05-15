#ifndef A52CBA7F_FD55_4884_8781_5D26A1386F79
#define A52CBA7F_FD55_4884_8781_5D26A1386F79

#include "../Constraint/Constraint.h"
#include "../Book/BookItem.h"
#include "../CatalogInterFace/Search.h"
#include "../CatalogInterFace/Manage.h"
class Catalog
    : public Search,
      public Manage
{
private:
    list<string> books_barcode;
    void *lib;

public:
    Catalog();
    Catalog(void *_lib)
        : lib(_lib) {}
    Catalog(list<string> _books_barcode, void *_lib)
        : books_barcode(_books_barcode), lib(_lib) {}
    ~Catalog();

    bool is_own(BookItem *);

    BookItem *add_book(BookItem);

    void search_view();
    BookItem *search_by_barcode();
    void search_by_title();
    void search_by_ISBN();

    void manage_view();
    void loan_book();
    void modify_book();
    BookItem *add_book_view();
    void import_book_view();
    void return_book();
    void reserve_book();
    void remove_book_lib();

    list<string> getBooks_barcode();
    void setBooks_barcode(list<string> books_isbn);

    void brief_render(list<BookItem *>);
    void render(BookItem *);

    BookItem *get_book(string barcode);
    list<BookItem *> get_books(string title, char Typ);
    list<BookItem *> get_books(int borrower);
};

#endif /* A52CBA7F_FD55_4884_8781_5D26A1386F79 */
