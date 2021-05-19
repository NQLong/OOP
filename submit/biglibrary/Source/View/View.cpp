#include "../../Header/View/View.h"
#include "../../Header/Actor/Patron.h"
void View::startApp(Library *lib)
{
    bool loop = true;
    string wait;
    User *user = NULL;
    while (loop)
    {
        int count = 1, option;
        clear();
        cout
            << "Login option: \n\n"
            << count++ << ". Librarian" << endl
            << count++ << ". Patron" << endl
            << endl
            << 0 << ". exit" << endl;
        cout << endl
             << "enter your choice: ";
        cin >> option;
        cin.ignore(100, '\n');
        switch (option)
        {
        case 1:
            user = login(LIBRARIAN);
            if (user)
                user = (Librarian *)user;
            break;
        case 2:
            user = login(PATRON);
            if (user)
                user = (Patron *)user;
            break;

        default:
            return;
            break;
        }
        if (option < 3 && option > 0)
        {
            if (!user)
            {
                cout << "account does not exist or disabled";
                getline(cin, wait);
            }
            else
            {
                (user)->view(lib);
            }
        }
    }
}

User *View::login(UserType Typ)
{
    clear();
    string username, password;
    cout << "your username: ";
    getline(cin, username);
    cout << "your password: ";
    getline(cin, password);
    clear();
    User *user = User::getUser(username, password);
    if (user && user->getTyp() != Typ)
        return NULL;

    return user;
}