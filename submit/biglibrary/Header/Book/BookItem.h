#ifndef A731B8F0_F84A_4705_8456_36D32C71F47F
#define A731B8F0_F84A_4705_8456_36D32C71F47F

#include "Book.h"

class BookItem : public Book
{
private:
    string barcode;
    string tag;
    bool is_reference_only;
    int number_of_pages;
    Format format;
    time_t borrowed;
    int loan_period;
    time_t due_date;
    bool is_overdue;
    int borrowed_by = -1;
    int reserved_by = -1;

    static list<BookItem> books;

public:
    static void book_list();

    static BookItem *select_book_item();

    static BookItem *add_book(BookItem);

    static BookItem *get_book_item(string ISBN);

    static list<BookItem> *get_book_items();

    static void set_authors(list<BookItem> authors);

    static BookItem input_book_items();

    bool reserve(int acc);

    bool is_reserved();

    bool return_book();

    bool loan(int);

    bool is_loaned();

    void modify_book_items();

    void check();

    void modify_loan_information();

    friend ostream &operator<<(ostream &os, const BookItem &b);

    string getBarcode();
    void setBarcode(string barcode);
    string getTag();
    void setTag(string tag);
    bool isIs_reference_only();
    void setIs_reference_only(bool is_reference_on);
    int getNumber_of_pages();
    void setNumber_of_pages(int number_of_pages);
    Format getFormat();
    void setFormat(Format format);
    time_t getBorrowed();
    void setBorrowed(time_t borrowed);
    int getLoan_period();
    void setLoan_period(int loan_period);
    time_t getDue_date();
    void setDue_date(time_t due_date);
    bool isIs_overdue();
    void setIs_overdue(bool is_overdue);
    int getBorrowed_by();
    void setBorrowed_by(int borrowed_by);
    int getReserved_by();
    void setReserved_by(int reserved_by);

    BookItem();
    ~BookItem();
    BookItem(
        string _ISBN,
        list<string> _author_name,
        string _name,
        string _subject,
        string _overview,
        string _publisher,
        time_t _publication_date,
        Language _lang,
        string _barcode,
        string _tag,
        bool _is_reference_on,
        int _number_of_pages,
        Format _format,
        time_t _borrowed,
        int _loanPeriod,
        time_t _due_date,
        bool _is_overdue)
        : Book(
              _ISBN, _author_name,
              _name, _subject,
              _overview, _publisher,
              _publication_date, _lang),
          barcode(_barcode),
          tag(_tag),
          is_reference_only(_is_reference_on),
          number_of_pages(_number_of_pages),
          format(_format),
          borrowed(_borrowed),
          loan_period(_loanPeriod),
          due_date(_due_date),
          is_overdue(_is_overdue) {}
};

#endif /* A731B8F0_F84A_4705_8456_36D32C71F47F */