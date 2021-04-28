#include "../Header/LibrarianView.h"

LibrarianView::LibrarianView() {}
LibrarianView::LibrarianView(Librarian *lib) : View()
{
    this->librarian = lib;
}

void LibrarianView::mainCommand()
{
    int count = 1;
    cout
        << count++ << ". Add an author" << endl
        << count++ << ". List all authors" << endl
        << count++ << ". Remove an author" << endl
        << count++ << ". Add an user" << endl
        << count++ << ". list all user" << endl
        << count++ << ". remove an user" << endl
        << count++ << ". Add a book" << endl
        << count++ << ". List all books" << endl
        << count++ << ". Find a book by Title" << endl //stop here
        << count++ << ". Find a book by ISBN" << endl
        << count++ << ". Find an User by username" << endl
        << count++ << ". Closed an User account" << endl
        << count++ << ". Activate an User account" << endl
        << count++ << ". list of held request" << endl
        << count++ << ". Handling a book Request" << endl
        << count++ << ". Recieve a returned book " << endl

        << endl
        << endl
        << "0. Exit"
        << endl
        << endl
        << "Enter your choice: ";
}

void LibrarianView::mainView()
{
    system("clear");
    bool loop = true;
    int option;
    string temp;
    while (loop)
    {
        cout << "Librarian manager\n\n";
        this->mainCommand();
        cin >> option;
        switch (option)
        {
        case 1:
            this->addAuthor();
            break;
        case 2:
            this->allAuthorsView();
            break;
        case 3:
            this->removeAuthor();
            break;
        case 4:
            addUser();
            break;
        case 5:
            this->listAllUser();
            break;
        case 6:
            this->removeUser();
            break;
        case 7:
            this->addBook();
            break;
        case 8:
            allBooksView();
            break;
        case 9:
            allBooksNameView();
            break;
        case 10:
            allBooksISBNView();
            break;

        case 11:
            userOfUsernameView();
            break;
        case 12:
            userAccountModify('c');
            break;
        case 13:
            userAccountModify('a');
            break;
        case 14:
            onHoldRequestsView();
            break;
        case 15:
            handlingRequestView();
            break;
        case 16:
            recieveBook();
            break;
        default:
            loop = false;
            break;
        }

        cout << endl
             << endl
             << "Press Enter to Continue";
        getline(cin, temp);
    }
}

void LibrarianView::userAccountModify(char status){
    system("clear");
    cin.ignore(1000, '\n');

    UserController controller;
    string username;

    cout << "Modify account" << endl;
    cout << "Account 's username : ";
    getline(cin, username);
    
    descryptRes(controller.setAccountStatus(username,status));
}
void LibrarianView::userOfUsernameView()
{
    system("clear");
    cin.ignore(1000, '\n');

    UserController controller;
    string username;

    cout << "Find a user with username" << endl;
    cout << "Account 's username : ";
    getline(cin, username);

    User *user = controller.userOfUsername(username);
    if (!user)
        cout << "User doesn't exist" << endl;

    else
        cout << *user;
}

void LibrarianView::recieveBook()
{
    system("clear");
    cin.ignore(1000, '\n');

    int code;
    string ISBN;
    cout << "receive a returned book\n\n";

    cout << "Book Request 's BLcode:";
    cin >> code;
    cin.ignore(1000, '\n');

    cout << "Borrowed book 's ISBN:";
    getline(cin, ISBN);

    BookRequestController controller;
    descryptRes(controller.receiveBook(code, ISBN));
}
void LibrarianView::onHoldRequestsView()
{

    system("clear");
    cin.ignore(1000, '\n');

    BookRequestController controller;
    cout << " On Held requests:" << endl;

    requestsView(controller.requests('h'));
}

void LibrarianView::requestsView(list<BookRequest *> reqs)
{

    int n = reqs.size();
    auto it = reqs.cbegin();
    for (int i = 0; i < n; i++)
    {
        cout
            << i + 1 << "." << endl
            << **it << endl;
        it++;
    }
}
void LibrarianView::handlingRequestView()
{
    system("clear");
    cin.ignore(1000, '\n');

    BookRequestController controller;

    int code;
    char decission;

    cout << "Handle a request" << endl
         << endl;

    cout << "Request code : ";
    cin >> code;

    int temp = controller.checkRequest(code);
    if (temp != controller.SUCCESS)
        descryptRes(temp);
    else
    {
        cout << "the request sastifies all term." << endl;

        cout << "Your permission : ";
        cin >> decission;

        cin.ignore(1000, '\n');

        descryptRes(controller.handlingBookRequest(code, decission));
    }
}

void LibrarianView::removeUser()
{
    system("clear");
    cin.ignore(1000, '\n');

    string username;
    int res;

    cout << "Remove an user" << endl
         << endl;
    cout << "Account's username : ";
    getline(cin, username);
    UserController controller;
    descryptRes(controller.removeUser(username));
}

void LibrarianView::listAllUser()
{
    system("clear");
    cin.ignore(1000, '\n');

    controller = new UserController;
    list<User *> lst = ((UserController *)controller)->allUsers();
    // cout<<"hello";
    int count = 1;
    for (auto it = lst.cbegin(); it != lst.cend(); it++)
    {
        cout << count++ << "." << endl
             << **it << endl;
    }
    delete controller;
}

void LibrarianView::addAuthor()
{
    system("clear");
    cin.ignore(1000, '\n');

    char gender;
    string name;

    cout << "Add an author" << endl
         << endl;

    cout << "Author name: ";
    getline(cin, name);

    cout << "Gender (m:Male, f: Female) :";
    gender = getchar();
    cin.ignore(1000, '\n');

    //call API from controller
    controller = new AuthorController;
    descryptRes(((AuthorController *)controller)->createAuthor(name, gender));
    delete controller;
}

void LibrarianView::removeAuthor()
{
    system("clear");
    cin.ignore(1000, '\n');

    string name;
    int res;

    cout << "Remove an author" << endl
         << endl;
    cout << "Author's name : ";
    getline(cin, name);
    controller = new AuthorController;
    descryptRes(((AuthorController *)controller)->removeAuthor(name));
}
void LibrarianView::addBook()
{
    system("clear");
    cin.ignore(1000, '\n');

    char status;
    string ISBN, title, publisher;
    list<string> authorNames;
    int authorN, year;

    cout
        << "Add a book" << endl;

    cout << "ISBN: ";
    getline(cin, ISBN);
    cout << "Tilte: ";
    getline(cin, title);
    cout << "publisher";
    getline(cin, publisher);
    cout << "Writed in: ";
    cin >> year;
    cout << "Number of Authors :";
    cin >> authorN;
    cin.ignore(1000, '\n');
    for (int i = 0; i < authorN; i++)
    {
        cout << setw(5) << ""
             << "Author no." << i + 1 << " 's name: ";
        authorNames.push_back("");
        getline(cin, authorNames.back());
    }

    BookController controller;
    descryptRes(controller.createBook(ISBN, title, publisher, authorNames, year));
}

void LibrarianView::addUser()
{
    system("clear");
    cin.ignore(1000, '\n');

    UserController controller;
    string userName, name, phone, address;
    char Typ;

    cout << "Add a user" << endl
         << endl;

    cout << "Account's username :";
    getline(cin, userName);

    cout << "Full name :";
    getline(cin, name);

    cout << "Phone number :";
    getline(cin, phone);

    cout << "Address :";
    getline(cin, address);

    cout << "Account type:";
    Typ = getchar();
    cin.ignore(1000, '\n');

    descryptRes(controller.createUser(userName, name, phone, address, 'a', Typ));
}