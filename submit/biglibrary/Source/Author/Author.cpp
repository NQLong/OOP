#include "../../Header/Author/Author.h"

list<Author> Author::authors;

Author::~Author(){}
Author::Author(){}

Author *Author::select_author()
{
    int count = 1;
    for (auto it = authors.begin(); it != authors.end(); it++)
    {
        cout << setw(3) << left << to_string(count++) + "." << it->getAuthor_name() << endl;
    }
    cout << endl;
    string name;
    cout << "Enter name: ";
    getline(cin, name);
    if (authors.size() != 0)
        return get_author(name);
    return NULL;
}

bool Author::add_author(Author a)
{
    if (get_author(a.author_name))
        return false;
    authors.push_back(a);
    return true;
}

Author *Author::get_author(string name)
{
    for (auto it = authors.begin(); it != authors.end(); it++)
        if (it->getAuthor_name() == name)
            return &*it;
    return NULL;
}

Author Author::input()
{
    Author temp;
    cout << "Author name: ";
    getline(cin, temp.author_name);
    cout << "Biography: ";
    getline(cin, temp.biography);
    cout << "Date of birth: " << endl;
    temp.birth_date = input_date();
    return temp;
}

void Author::modify()
{

    int option;
    bool loop = true;
    while (loop)
    {
        int count = 1;
        clear();

        cout
            << setw(3) << left << to_string(count++) + "."
            << "Modify name." << endl
            << setw(3) << left << to_string(count++) + "."
            << "Modify biography." << endl
            << setw(3) << left << to_string(count++) + "."
            << "Modify date of birth." << endl

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
            cout << "new name:";
            getline(cin, this->author_name);
            break;
        case 2:
            clear();
            cout << "new biography:";
            getline(cin, this->biography);
            break;
        case 3:
            clear();
            cout << "new date of birth:";
            this->birth_date = input_time();
            break;
        default:
            loop = false;
            break;
        }
    }

    return;
}

ostream &operator<<(ostream &os, const Author &a)
{
    os << "name : " << a.author_name << endl
       << "biography : " << a.biography << endl
       << "Date of birth : " << (char *)ctime(&a.birth_date);
    return os;
}

string Author::getAuthor_name()
{
    return this->author_name;
}

void Author::setAuthor_name(string author_name)
{
    this->author_name = author_name;
}

string Author::getBiography()
{
    return this->biography;
}

void Author::setBiography(string biography)
{
    this->biography = biography;
}

time_t Author::getBirth_date()
{
    return this->birth_date;
}

void Author::setBirth_date(time_t birth_date)
{
    this->birth_date = birth_date;
}

list<Author> *Author::get_authors()
{
    return &authors;
}

void Author::set_authors(list<Author> _authors)
{
    authors = _authors;
}
