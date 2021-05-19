#include "../../Header/Catalog/Catalog.h"
#include "../../Header/Library/Library.h"
#include "../../Header/Actor/User.h"
#include "../../Header/Actor/Account.h"
#include "../../Header/Actor/Patron.h"

bool Catalog::is_own(BookItem *book)
{
    return (((Library *)lib)->has_book(book));
}

list<BookItem *> Catalog::get_books(string pattern, char Typ)
{
    return {};
}
list<BookItem *> Catalog::get_books(int borrower)
{
    return {};
}

BookItem *get_book(string barcode)
{
    return NULL;
}

Catalog::Catalog() {}

Catalog::~Catalog() {}

void Catalog::brief_render(list<BookItem *> books)
{
    cout
        << setw(111) << setfill('*') << "" << endl
        << setfill(' ')
        << setw(10) << left << "| barcode " << '|'
        << setw(10) << left << "   ISBN   " << '|'
        << setw(15) << left << "   Format" << '|'
        << setw(10) << left << "is loaned" << '|'
        << setw(10) << left << " ref only" << '|'
        << setw(50) << left << "Title"
        // << setw(30) << right
        << "|"
        << endl
        << setw(111) << setfill('*') << "" << endl
        << setfill(' ');

    for (auto it = books.begin(); it != books.end(); it++)
    {
        if (!*it)
            continue;
        cout
            << setw(10) << left << "|" + (*it)->getBarcode() << '|'
            << setw(10) << left << (*it)->getISBN() << '|'
            << setw(15) << left << (Format)(*it)->getFormat() << '|'
            << setw(10) << left << ((*it)->getDue_date() <= 0 ? "False" : "True") << '|'
            << setw(10) << left << ((*it)->isIs_reference_only() ? "True" : "False") << '|'
            << setw(50) << left << (*it)->getTitle() << '|' << endl
            << setw(111) << setfill('*') << "" << endl
            << setfill(' ');
    }
}
/////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////Search///////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////
void Catalog::search_view()
{
    int option;
    bool loop = true;

    while (loop)
    {
        int count = 1;
        clear();

        cout
            << setw(3) << left << to_string(count++) + "."
            << "Search books by barcode" << endl
            << setw(3) << left << to_string(count++) + "."
            << "Search books by ISBN" << endl
            << setw(3) << left << to_string(count++) + "."
            << "Search books by title" << endl

            << endl
            << setw(3) << left << "0."
            << "Back." << endl;

        cout << endl
             << "Enter your choice: ";
        cin >> option;
        cin.ignore();
        switch (option)
        {
        case 1:
            clear();
            search_by_barcode();
            wait();
            break;
        case 2:
            clear();
            search_by_ISBN();
            wait();
            break;
        case 3:
            clear();
            search_by_title();
            wait();
            break;
        default:
            loop = false;
            break;
        }
    }

    return;
}

void Catalog::search_by_ISBN()
{
    string ISBN;
    list<BookItem *> items;
    cout << "Enter title: ";
    getline(cin, ISBN);
    ISBN = lower_string(ISBN);
    for (auto it = books_barcode.begin(); it != books_barcode.end(); it++)
    {
        BookItem *ptr = BookItem::get_book_item(*it);
        if (ptr && lower_string(ptr->getISBN()) == ISBN)
        {
            items.push_back(ptr);
        }
    }
    brief_render(items);
    return;
}

void Catalog::search_by_title()
{
    string title;
    list<BookItem *> items;
    cout << "Enter title: ";
    getline(cin, title);
    title = lower_string(title);
    for (auto it = books_barcode.begin(); it != books_barcode.end(); it++)
    {
        BookItem *ptr = BookItem::get_book_item(*it);
        if (ptr && lower_string(ptr->getTitle()) == title)
        {
            items.push_back(ptr);
        }
    }
    brief_render(items);
    return;
}

BookItem *Catalog::search_by_barcode()
{
    string barcode;
    cout << "Enter barcode: ";
    getline(cin, barcode);
    for (auto it = books_barcode.begin(); it != books_barcode.end(); it++)
        if (*it == barcode)
        {
            BookItem *item = BookItem::get_book_item(barcode);
            if (item)
            {
                cout << endl
                     << *item;
                return item;
            }
        }
    cout << "Book not found";
    return NULL;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////Manage//////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////
void Catalog::manage_view()
{
    int option;
    bool loop = true;

    while (loop)
    {
        int count = 1;
        clear();

        cout
            << setw(3) << left << to_string(count++) + "."
            << "Loan book" << endl
            << setw(3) << left << to_string(count++) + "."
            << "return book" << endl
            << setw(3) << left << to_string(count++) + "."
            << "reserve book" << endl
            << setw(3) << left << to_string(count++) + "."
            << "Remove book from library" << endl
            << setw(3) << left << to_string(count++) + "."
            << "Modify book" << endl
            << setw(3) << left << to_string(count++) + "."
            << "Add new book" << endl
            << setw(3) << left << to_string(count++) + "."
            << "Import book to library" << endl

            << endl
            << setw(3) << left << "0."
            << "Back." << endl;

        cout << endl
             << "Enter your choice: ";
        cin >> option;
        cin.ignore();
        switch (option)
        {
        case 1:
            clear();
            loan_book();
            wait();
            break;
        case 2:
            clear();
            return_book();
            wait();
            break;
        case 3:
            clear();
            reserve_book();
            wait();
            break;
        case 4:
            clear();
            remove_book_lib();
            wait();
            break;
        case 5:
            clear();
            modify_book();
            wait();
            break;
        case 6:
            clear();
            add_book_view();
            wait();
            break;
        case 7:
            clear();
            import_book_view();
            wait();
        default:
            loop = false;
            break;
        }
    }

    return;
}

void Catalog::remove_book_lib()
{
    BookItem *book = search_by_barcode();

    if (!book)
        return;
    cout
        << endl
        << endl
        << "Is this your book?"
        << endl;
    if (!select_statement("False", "True"))
        return;
    book->return_book();

    ((Library *)lib)->remove_book(book);
    cout << "Done";
    return;
}

void Catalog::reserve_book()
{
    BookItem *book = search_by_barcode();

    if (!book)
        return;
    cout
        << endl
        << endl
        << "Is this your book?"
        << endl;
    if (!select_statement("False", "True"))
        return;

    clear();
    User *user = User::search_user();
    if (!user || user->getTyp() != PATRON)
    {
        cout << "Invalid useraname";
        return;
    }
    Account *acc = ((Patron *)user)->get_account();
    if (acc->getState() == FROZEN || acc->getState() == CLOSED)
    {
        cout << "Account has been disable";
        return;
    }
    else if (book->is_reserved() && book->getReserved_by() != acc->getNumber())
    {
        clear();
        cout << "this book is being reserved by other patron!\n";
        return;
    }
    else if (acc->getReserved_book().size() == 3)
    {
        cout << "account reach maximum reserved books";
        return;
    }
    else if (book->reserve(acc->getNumber()))
    {
        cout << "Done";
        return;
    }
    cout << "something went wrong";
    return;
}

void Catalog::return_book()
{
    BookItem *book = search_by_barcode();

    if (!book)
        return;
    cout
        << endl
        << endl
        << "Is this your book?"
        << endl;
    if (!select_statement("False", "True"))
        return;
    if (!book->return_book())
    {
        cout << "Invalid book";
        return;
    }
    cout << "done";
}

void Catalog::import_book_view()
{
    clear();
    BookItem *ptr = NULL;
    if (select_statement("Import existing book", "Import new book"))
        ptr = add_book_view();
    else
        ptr = search_by_barcode();
    if (!ptr)
        return;
    if (is_own(ptr))
    {
        cout << "library already have this book";
    }
    else
    {
        ((Library *)lib)->add_book(ptr);
    }
}

void Catalog::loan_book()
{
    BookItem *book = search_by_barcode();

    if (!book)
        return;
    cout
        << endl
        << endl
        << "Is this your book?"
        << endl;
    if (!select_statement("False", "True"))
        return;

    if (!is_own(book))
    {
        cout << "this book is not available now";
        return;
    }
    clear();
    User *user = User::search_user();
    if (!user || user->getTyp() != PATRON)
    {
        cout << "Invalid useraname";
        return;
    }
    Account *acc = ((Patron *)user)->get_account();
    if (acc->getState() == FROZEN || acc->getState() == CLOSED)
    {
        cout << "Account has been disable";
        return;
    }
    else if (book->is_reserved() && book->getReserved_by() != acc->getNumber())
    {
        clear();
        cout << "this book is being reserved by other patron!\nDo you stil want to clear reservation and lend this book??\n";
        if (select_statement("Yes", "No"))
            return;
    }
    if (book->loan(acc->getNumber()))
    {
        
        cout << "Done";
        return;
    }

    return;
}

void Catalog::modify_book()
{
    BookItem *ptr = search_by_barcode();

    if (!ptr)
        return;
    cout
        << endl
        << endl
        << "Is this THAT book?"
        << endl;
    if (!select_statement("False", "True"))
        return;
    clear();
    ptr->modify_book_items();
}

BookItem *Catalog::add_book_view()
{
    clear();
    cout << "New book:" << endl;
    // BookItem item= BookItem::input_book_items();
    BookItem *ptr = add_book(BookItem::input_book_items());
    if (ptr)
    {
        clear();
        cout << "Your book:\n\n"
             << *ptr;
    }
    wait();
    return ptr;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////

//getter & setter
list<string> Catalog::getBooks_barcode()
{
    return this->books_barcode;
}

void Catalog::setBooks_barcode(list<string> books_barcode)
{
    this->books_barcode = books_barcode;
}

BookItem *Catalog::add_book(BookItem item)
{
    BookItem *ptr = BookItem::add_book(item);
    if (!ptr)
    {
        clear();
        cout << "Invalid information";
        return NULL;
    }
    this->books_barcode.push_back(ptr->getBarcode());
    return ptr;
}