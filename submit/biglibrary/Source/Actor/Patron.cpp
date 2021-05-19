#include "../../Header/Actor/Patron.h"

Patron::~Patron() {}

ostream &operator<<(ostream &os, const Patron &p)
{
    // cout<<User(p);k
    os << p.toString() << endl
       << "Account number "<<": " << p.account->getNumber();

    ;
    return os;
}

Account *Patron::get_account()
{
    return account;
}
void Patron::set_account(Account *acc)
{
    this->account = acc;
}

Patron* Patron::input_patron()
{
    Patron *temp = new Patron();
    temp->account = Account::add_account(Account());
    temp->input_user_info();
    return temp;
}

void Patron::view(Library *lib)
{
    int option;
    bool loop = true;
    Search *search;
    while (loop)
    {
        int count = 1;
        clear();

        cout
            << setw(3) << left << to_string(count++) + "."
            << "Search Book." << endl
            << setw(3) << left << to_string(count++) + "."
            << "Modify your infmation ." << endl

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
            this->modify_user_info();

            break;
        case 4:
            clear();
        default:
            loop = false;
            break;
        }
    }

    return;
}