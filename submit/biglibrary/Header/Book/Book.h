#ifndef C9EC5CC0_3AB6_4179_9439_FDDA354B7EAB
#define C9EC5CC0_3AB6_4179_9439_FDDA354B7EAB

#include "../Constraint/Constraint.h"

class Book
{
private:
    string ISBN;
    list<string> author_names;
    string title;
    string subject;
    string overview;
    string publisher;
    time_t publication_date;
    Language lang;

public:
    Book();
    ~Book();
    Book(
        string _ISBN,
        list<string> _author_name,
        string _name,
        string _subject,
        string _overview,
        string _publisher,
        time_t _publication_date,
        Language _lang)
        : ISBN(_ISBN),
          author_names(_author_name),
          title(_name),
          subject(_subject),
          overview(_overview),
          publisher(_publisher),
          publication_date(_publication_date),
          lang(_lang) {}

    void intput();

    void add_author();

    void modify();

    friend ostream &operator<<(ostream &os, const Book &a);

    string getISBN();
    void setISBN(string ISBN);
    list<string> getAuthor_name();
    void setAuthor_name(list<string> author_name);
    string getTitle();
    void setTitle(string title);
    string getSubject();
    void setSubject(string subject);
    string getOverview();
    void setOverview(string overview);
    string getPublisher();
    void setPublisher(string publisher);
    time_t getPublication_date();
    void setPublication_date(time_t publication_date);
    Language getLang();
    void setLang(Language lang);
};

#endif /* C9EC5CC0_3AB6_4179_9439_FDDA354B7EAB */
