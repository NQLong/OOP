#include "../Header/MemberView.h"

void MemberView::mainCommand()
{
    int count = 1;
    cout
        << count++ << ". Find a book by ISBN" << endl
        << count++ << ". Find a book by Name" << endl
        << count++ << ". Make book book request" << endl
        // << count++ << ". Find a book by Name" << endl

        << endl
        << endl
        << "Enter your choice: ";
}

void MemberView::mainView()
{

    bool loop = true;
    int option;
    string temp;
    while (loop)
    {
        system("clear");
        cout << "Library manager for Member\n\n";
        this->mainCommand();
        cin >> option;
        switch (option)
        {
        case 1:
            this->allBooksISBNView();
            break;
        case 2:
            this->allBooksNameView();
            break;
        case 3:
            this-> requestBookView();
            break;
        // case '1':
        // case '11':
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

void MemberView::requestBookView(){
    system("clear");
    cin.ignore(1000, '\n');

    int day;
    string ISBN;

    cout<<"Make borrow request for a book"<<endl<<endl;
    
    cout<<"Book's ISBN :";
    getline(cin,ISBN);
    
    cout<<"Borrowing's time(days && < 14): ";
    cin >> day;
    cin.ignore(1000, '\n');

    BookRequestController controller;
    

    descryptRes(controller.createBookRequest(this->member, ISBN, day));
    
}