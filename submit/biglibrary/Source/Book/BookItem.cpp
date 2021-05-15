#include "../../Header/Book/BookItem.h"
#include "../../Header/Actor/Account.h"
list<BookItem> BookItem::books;

BookItem::~BookItem() {}
BookItem::BookItem() {}

bool BookItem::reserve(int acc)
{
    if (this->reserved_by != -1)
        return false;
    this->setReserved_by(acc);
    Account::get_account(acc)->add_reserved(this->barcode);
    return true;
}

bool BookItem::is_reserved()
{
    return (this->reserved_by >= 0);
}
bool BookItem::return_book()
{
    if (this->borrowed > 0)
    {
        this->setBorrowed(-1);
        this->setDue_date(-1);
        this->setBorrowed_by(-1);
        Account *acc = Account::get_account(this->getBorrowed_by());
        if (acc)
        {
            acc->getOwed_book().remove(this->barcode);
            acc->check_state();
        }

        this->setBorrowed_by(-1);
        return true;
    }
    return false;
}

void BookItem::book_list()
{
    int count = 1;
    for (auto it = books.begin(); it != books.end(); it++)
    {
        cout
            << setw(3) << left << to_string(count++) + "."
            << "ISBN: " << it->getISBN() << endl
            << setw(3) << left << ""
            << "title: " << it->getTitle() << endl;
    }
    return;
}

BookItem *BookItem::select_book_item()
{
    book_list();
    cout << endl
         << "your book ISBN: ";
    string ISBN;
    getline(cin, ISBN);
    BookItem *ptr = get_book_item(ISBN);
    if (books.size() != 0 && !ptr)
    {
        cout << "Invalid ISBN" << endl;
        wait();
        clear();
        return select_book_item();
    }
    return ptr;
}

BookItem *BookItem::add_book(BookItem b)
{
    if (!get_book_item(b.getBarcode()))
    {
        books.push_back(b);
        return &books.back();
    }
    return NULL;
}

BookItem *BookItem::get_book_item(string barcode)
{
    for (auto it = books.begin(); it != books.end(); it++)
    {
        if (it->getBarcode() == barcode)
        {
            it->check();
            return &*it;
        }
    }
    return NULL;
}

list<BookItem> *BookItem::get_book_items()
{
    return &books;
}

void BookItem::set_authors(list<BookItem> _books)
{
    books = _books;
}

bool BookItem::loan(int account_id)
{
    if (this->isIs_reference_only())
    {
        cout << "this book is reference only";
        return false;
    }
    else if (this->is_loaned())
    {
        cout << "this book is loaned";
        return false;
    }
    this->setBorrowed_by(account_id);
    this->setBorrowed(time(0));
    this->setDue_date(time(0) + this->loan_period * SECOND_IN_DAY);
    Account *acc = Account::get_account(this->getBorrowed_by());
    acc->add_history(this->getBarcode());
    acc->add_owed(this->getBarcode());
    acc->check_state();
    return true;
}

BookItem BookItem::input_book_items()
{
    BookItem item;
    BookItem *temp = &item;

    cout << "Book barcode: ";
    getline(cin, temp->barcode);
    cout << "tag: ";
    getline(cin, temp->tag);
    cout << "Number of pages: ";
    cin >> temp->number_of_pages;
    cout << "loan period: ";
    cin >> temp->loan_period;
    cin.ignore();
    clear();
    cout << "Is reference only:" << endl;
    temp->is_reference_only = select_statement("True", "False");
    clear();
    temp->format = select_format();
    clear();
    temp->borrowed = 1;
    temp->is_overdue = 0;
    temp->due_date = -1;
    temp->intput();
    return item;
}

void BookItem::modify_book_items()
{
    int option;
    bool loop = true;

    while (loop)
    {
        int count = 1;
        clear();

        cout
            << setw(3) << left << to_string(count++) + "."
            << "modify barcode." << endl
            << setw(3) << left << to_string(count++) + "."
            << "modify tag." << endl
            << setw(3) << left << to_string(count++) + "."
            << "modify reference only." << endl
            << setw(3) << left << to_string(count++) + "."
            << "modify number of pages." << endl
            << setw(3) << left << to_string(count++) + "."
            << "modify format." << endl
            << setw(3) << left << to_string(count++) + "."
            << "modify loan information." << endl
            << setw(3) << left << to_string(count++) + "."
            << "more modify option." << endl

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
            cout << "Book barcode: ";
            getline(cin, this->barcode);
            break;
        case 2:
            clear();
            cout << "tag: ";
            getline(cin, this->tag);
            break;
        case 3:
            clear();
            cout << "Is reference only:" << endl;
            this->is_reference_only = select_statement("False", "True");
            break;
        case 4:
            clear();
            cout << "Number of pages: ";
            cin >> this->number_of_pages;
            cin.ignore();
            break;
        case 5:
            clear();
            cout << "new format: " << endl;
            this->format = select_format();
            break;
        case 6:
            clear();
            this->modify_loan_information();
            break;
        // case 6:
        //     clear();
        //     cout << "Borrowed date" << endl;
        //     this->borrowed = input_time();
        //     while (this->borrowed > time(0) || this->borrowed >= this->due_date)
        //     {
        //         cout << "invalid value, try again" << endl;
        //         wait();
        //         clear();
        //         cout << "Borrowed date" << endl;
        //         this->borrowed = input_time();
        //     }
        //     this->loan_period = (this->due_date - this->borrowed) / SECOND_IN_DAY;
        //     break;
        // case 7:
        //     clear();
        //     cout << "loan period: ";
        //     cin >> this->loan_period;
        //     this->due_date = this->loan_period * SECOND_IN_DAY + this->borrowed;
        //     cin.ignore();
        //     break;
        // case 8:
        //     clear();
        //     cout << "due date:" << endl;
        //     this->due_date = input_time();
        //     while (this->borrowed >= this->due_date)
        //     {
        //         cout << "invalid value, try again" << endl;
        //         wait();
        //         clear();
        //         cout << "due date:" << endl;
        //         this->due_date = input_time();
        //     }
        //     this->loan_period = (this->due_date - this->borrowed) / SECOND_IN_DAY;
        //     if (this->due_date > time(0))
        //         this->is_overdue = true;
        //     break;
        case 7:
            clear();
            this->modify();
            break;
        default:
            loop = false;
            clear();
            cout << *this;
            break;
        }
    }

    return;
}

bool BookItem::is_loaned()
{
    if (this->borrowed > 0)
        return true;
    return false;
}

void BookItem::modify_loan_information()
{
    clear();
    cout << "Is this book loaned: " << endl;
    if (!select_statement("False", "True"))
    {
        this->borrowed = -1;
        this->loan_period = -1;
        this->is_overdue = 0;
        this->due_date = -1;
    }
    else
    {
        int option;
        bool loop = true;

        while (loop)
        {
            int count = 1;
            clear();

            cout
                << setw(3) << left << to_string(count++) + "."
                << "modify borrowed date." << endl
                << setw(3) << left << to_string(count++) + "."
                << "modify loan period." << endl
                << setw(3) << left << to_string(count++) + "."
                << "modify due date." << endl

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
                if (this->loan_period <= 0)
                {
                    cout << "The loan period hasn't been set, please set loan period first" << endl;
                    wait();
                    break;
                }
                cout << "Borrowed date" << endl;
                this->borrowed = input_time();
                while (this->borrowed > time(0))
                {
                    cout << "invalid value, try again" << endl;
                    wait();
                    clear();
                    cout << "Borrowed date" << endl;
                    this->borrowed = input_time();
                }
                this->due_date = (this->borrowed + this->loan_period * SECOND_IN_DAY);
                break;
            case 2:
                clear();
                cout << "loan period: ";
                cin >> this->loan_period;
                cin.ignore();
                break;
            case 3:
                clear();
                if (this->loan_period <= 0)
                {
                    cout << "The loan period hasn't been set, please set loan period first" << endl;
                    wait();
                    break;
                }
                cout << "due date:" << endl;
                this->due_date = input_time();
                while (this->borrowed >= this->due_date)
                {
                    cout << "invalid value, try again" << endl;
                    wait();
                    clear();
                    cout << "due date:" << endl;
                    this->due_date = input_time();
                }
                this->borrowed = (this->due_date - this->loan_period * SECOND_IN_DAY);
                break;
            default:
                loop = false;
                break;
            }
            this->check();
        }

        return;
    }
}
void BookItem::check()
{
    this->is_overdue = false;
    if ((this->due_date > 0) && (time(0) > this->due_date))
        this->is_overdue = true;
}

ostream &operator<<(ostream &os, const BookItem &b)
{
    os
        << Book(b) << endl
        << setw(20) << left << "Bar code: " << b.barcode << endl
        << setw(20) << left << "Tag: " << b.tag << endl
        << setw(20) << left << "Format: " << (Format)b.format << endl
        << setw(20) << left << "Is reference only: " << b.is_reference_only << endl
        << setw(20) << left << "Number of pages: " << b.number_of_pages << endl
        << setw(20) << left << "Borrowed date: " << (b.borrowed <= 0 ? "None" : (char *)ctime(&b.borrowed)) << endl
        << setw(20) << left << "Loan period: " << (b.loan_period <= 0 ? "None" : to_string(b.loan_period)) << " day" << endl
        << setw(20) << left << "Due date: " << (b.due_date <= 0 ? "None" : (char *)ctime(&b.due_date)) << endl
        << setw(20) << left << "is overdue: " << (b.is_overdue ? "True" : "False");
    return os;
}

//getter setter

int BookItem::getBorrowed_by()
{
    return borrowed_by;
}

void BookItem::setBorrowed_by(int borrowed_by)
{
    this->borrowed_by = borrowed_by;
}

int BookItem::getReserved_by()
{
    return reserved_by;
}

void BookItem::setReserved_by(int reserved_by)
{
    this->reserved_by = reserved_by;
}

string BookItem::getBarcode()
{
    return this->barcode;
}

void BookItem::setBarcode(string barcode)
{
    this->barcode = barcode;
}

string BookItem::getTag()
{
    return this->tag;
}

void BookItem::setTag(string tag)
{
    this->tag = tag;
}

bool BookItem::isIs_reference_only()
{
    return this->is_reference_only;
}

void BookItem::setIs_reference_only(bool is_reference_on)
{
    this->is_reference_only = is_reference_on;
}

int BookItem::getNumber_of_pages()
{
    return this->number_of_pages;
}

void BookItem::setNumber_of_pages(int number_of_pages)
{
    this->number_of_pages = number_of_pages;
}

Format BookItem::getFormat()
{
    return this->format;
}

void BookItem::setFormat(Format format)
{
    this->format = format;
}

time_t BookItem::getBorrowed()
{
    return this->borrowed;
}

void BookItem::setBorrowed(time_t borrowed)
{
    this->borrowed = borrowed;
}

int BookItem::getLoan_period()
{
    return this->loan_period;
}

void BookItem::setLoan_period(int loan_period)
{
    this->loan_period = loan_period;
}

time_t BookItem::getDue_date()
{
    return this->due_date;
}

void BookItem::setDue_date(time_t due_date)
{
    this->due_date = due_date;
}

bool BookItem::isIs_overdue()
{
    return this->is_overdue;
}

void BookItem::setIs_overdue(bool is_overdue)
{
    this->is_overdue = is_overdue;
}
