#include "../../Header/Book/Book.h"
#include "../../Header/Author/Author.h"
Book::~Book() {}
Book::Book() {}

void Book::intput()
{
    cout << "Book ISBN: ";
    getline(cin, this->ISBN);
    cout << "Title: ";
    getline(cin, this->title);
    cout << "Subject: ";
    getline(cin, this->subject);
    cout << "Overview: ";
    getline(cin, this->overview);
    cout << "Publisher: ";
    getline(cin, this->publisher);
    clear();
    cout << "Publication date" << endl;
    publication_date = input_date();
    clear();
    cout << " Language: " << endl;
    lang = select_language();
    add_author();
    return;
}

void Book::add_author()
{
    while (true)
    {
        clear();
        cout << "Do you want to add more author to this book??\n\n";
        if (select_statement("Yes", "No"))
            return;
        clear();
        cout << "Author name: ";
        string author;
        getline(cin, author);
        if (!Author::get_author(author))
        {
            cout << endl
                 << "Author doesn't exist.Add new author" << endl;
            if (select_statement("Yes", "No"))
                continue;
            clear();
            Author new_author = Author::input();
            clear();
            if (!Author::add_author(new_author))
            {
                clear();
                cout << "invalid author name";
                wait();
                continue;
            }
            this->author_names.push_back(new_author.getAuthor_name());
            cout << "Ok";
            wait();
        }
        for (auto it = author_names.begin(); it != author_names.end(); it++)
        {
            if (*it == author)
            {
                clear();
                cout << "Author already added" << endl;
                wait();
                continue;
            }
        }
        this->author_names.push_back(author);
    }
}

void Book::modify()
{
    int option;
    bool loop = true;

    while (loop)
    {
        int count = 1;
        clear();

        cout
            << setw(3) << left << to_string(count++) + "."
            << "modify ISBN." << endl
            << setw(3) << left << to_string(count++) + "."
            << "modify title." << endl
            << setw(3) << left << to_string(count++) + "."
            << "modify subject." << endl
            << setw(3) << left << to_string(count++) + "."
            << "modify overview." << endl
            << setw(3) << left << to_string(count++) + "."
            << "modify publisher." << endl
            << setw(3) << left << to_string(count++) + "."
            << "modify publishcation date." << endl
            << setw(3) << left << to_string(count++) + "."
            << "modify lang." << endl

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
            cout << "new Book ISBN: ";
            getline(cin, this->ISBN);
            break;
        case 2:
            clear();
            cout << "new Title: ";
            getline(cin, this->title);
            break;
        case 3:
            clear();
            cout << "new Subject: ";
            getline(cin, this->subject);
            break;
        case 4:
            clear();
            cout << "new Overview: ";
            getline(cin, this->overview);
            break;
        case 5:
            clear();
            cout << "publisher: ";
            getline(cin, this->publisher);
            break;
        case 6:
            clear();
            cout << "Publication date";
            publication_date = input_date();
            break;
        case 7:
            clear();
            cout << "new Language: ";
            lang = select_language();
            break;

        default:
            loop = false;
            break;
        }
    }

    return;
}

ostream &operator<<(ostream &os, const Book &a)
{
    os << setw(20) << left << "Book ISBN: " << a.ISBN << endl;

    os << setw(20) << left << "Title: " << a.title << endl;

    os << setw(20) << left << "Subject: " << a.subject << endl;

    os << setw(20) << left << "Overview: " << a.overview << endl;

    os << setw(20) << left << "Publisher: " << a.publisher << endl;

    os << setw(20) << left << "Publication date: " << (char *)ctime(&a.publication_date);

    os << setw(20) << left << "Language: " << (Language)a.lang << endl;

    os << setw(20) << left << "Authors: " << endl;

    int count = 1;
    for (auto it = a.author_names.begin(); it != a.author_names.end(); it++)
    {
        os << setw(5) << "" << setw(3) << left << to_string(count++) + "." << *it << endl;
    }
    return os;
}

//get & set
string Book::getISBN()
{
    return this->ISBN;
}

void Book::setISBN(string ISBN)
{
    this->ISBN = ISBN;
}

list<string> Book::getAuthor_name()
{
    return this->author_names;
}

void Book::setAuthor_name(list<string> author_name)
{
    this->author_names = author_name;
}

string Book::getTitle()
{
    return this->title;
}

void Book::setTitle(string title)
{
    this->title = title;
}

string Book::getSubject()
{
    return this->subject;
}

void Book::setSubject(string subject)
{
    this->subject = subject;
}

string Book::getOverview()
{
    return this->overview;
}

void Book::setOverview(string overview)
{
    this->overview = overview;
}

string Book::getPublisher()
{
    return this->publisher;
}

void Book::setPublisher(string publisher)
{
    this->publisher = publisher;
}

time_t Book::getPublication_date()
{
    return this->publication_date;
}

void Book::setPublication_date(time_t ation_date)
{
    this->publication_date = ation_date;
}

Language Book::getLang()
{
    return this->lang;
}

void Book::setLang(Language lang)
{
    this->lang = lang;
}
