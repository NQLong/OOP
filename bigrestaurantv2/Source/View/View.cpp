#include "../../Header/View/View.h"

void View::startApp()
{
    bool loop = true;
    string wait;
    Actor *user = NULL;
    while (loop)
    {
        int count = 1, option;
        system("clear");
        cout
            << "Login option: \n\n"
            << count++ << ". Manager" << endl
            << count++ << ". Chef" << endl
            << count++ << ". Receptionist" << endl
            << count++ << ". waiter" << endl
            << count++ << ". admin" << endl
            <<endl
            << 0 << ". exit" << endl;
        cout << endl
             << "enter your choice: ";
        cin >> option;
        cin.ignore(100, '\n');
        switch (option)
        {
        case 1:
            user = login(MANAGER);
            if (user)
                user = (Manager *)user;
            break;
        case 2:
            user = login(CHEF);
            if (user)
                user = (Chef *)user;
            break;
        case 3:
            user = login(RECEPTIONIST);
            if (user)
                user = (Receptionist *)user;
            break;
        case 4:
            user = login(WAITER);
            if (user)
                user = (Waiter *)user;
            break;
        case 5:
            user = login(ADMIN);
            if (user)
                user = (Admin *)user;
            break;

        

        default:
            return;
            break;
        }
        if (option < 6 && option > 0)
        {
            if (!user)
            {
                cout << "account does not exist or disabled";
                getline(cin, wait);
            }
            else
            {
                (user)->view();
            }
        }
    }
}

Employee *View::login(EmployeeType Typ)
{
    system("clear");
    string username, password;
    cout << "your username: ";
    getline(cin, username);
    cout << "your password: ";
    getline(cin, password);
    system("clear");
    return Restaurant::getEmployee(username, password, Typ, A_ACTIVE);
}