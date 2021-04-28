#include "../Header/MainView.h"

void MainView::welcomeView(User *user)
{
    system("clear");
    cout << "Welcomeback to the Wakandian's Library, " << user->getName();
    cout << endl
         << endl
         << "Press Enter to start";
    string temp;
    getline(cin, temp);
}
void MainView::startApp()
{
    bool loop = true;
    while (loop)
    {
        system("clear");
        View *view;
        User *user = login();
        if (!user)
        {
            cout << "username doesn't exist";
            continue;
        }
        else if (user->getType() == 'l')
        {
            view = new LibrarianView((Librarian *)user);
        }
        else
        {
            view = new MemberView((Member *)user);
        }
        welcomeView(user);
        view->mainView();
    }
}

User *MainView::login()
{
    string username;
    cout << "your username: ";
    getline(cin, username);
    UserController usercontroller;
    return usercontroller.userOfUsername(username);
}