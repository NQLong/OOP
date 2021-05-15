#include "../../Header/Actor/Librarian.h"
#include "../../Header/Actor/Patron.h"
#include "../../Header/CatalogInterFace/Search.h"
#include "../../Header/CatalogInterFace/Manage.h"

Librarian::~Librarian() {}

void Librarian::view(Library *lib)
{
    int option;
    bool loop = true;
    Search *search;
    Manage *manage;
    while (loop)
    {
        int count = 1;
        clear();

        cout
            << setw(3) << left << to_string(count++) + "."
            << "Search Book." << endl
            << setw(3) << left << to_string(count++) + "."
            << "Manage Book." << endl
            << setw(3) << left << to_string(count++) + "."
            << "Modify your infmation ." << endl
            << setw(3) << left << to_string(count++) + "."
            << "Add user." << endl

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
            search = lib->get_cactalog();
            search->search_view();
            break;
        case 2:
            clear();
            manage = lib->get_cactalog();
            manage->manage_view();
            break;
        case 3:
            clear();
            this->modify_user_info();

            break;
        case 4:
            clear();
            add_user();
            break;
        default:
            loop = false;
            break;
        }
    }

    return;
}

void Librarian::add_user()
{
    if (!select_statement("Add a patron", "Add a librarian"))
    {
        Patron *patron = Patron::input_patron();
        if (!User::add_user(patron))
        {
            if (patron)
                delete[] patron;
        }
        else
        {
            cout << "done";
            return;
        }
    }
    else
    {
        if (this->getPosition() != "admin")
        {
            cout << "Only admin librarian can add another librarian";
            return;
        }
        Librarian *librarian = Librarian::input_librarian();
        if (!User::add_user(librarian))
        {
            if (librarian)
                delete[] librarian;
        }
        else
        {
            cout << "done";
            return;
        }
    }
    cout << "Invalid user";
    return;
}

Librarian *Librarian::input_librarian(){
    Librarian *temp = new Librarian();
    cout<<"Enter position :";
    getline(cin,temp->position);
    temp->input_user_info();
    return temp;
}
//getter setter
string Librarian::getPosition()
{
    return this->position;
}

void Librarian::setPosition(string position)
{
    this->position = position;
}
