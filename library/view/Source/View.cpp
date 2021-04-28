#include "../Header/View.h"

View::~View() {}
View::View() {}

void View::allAuthorsView()
{
    system("clear");
    cin.ignore(1000, '\n');
    cout << "All authors :\n\n";
    BaseController *controller = new AuthorController();
    this->authorsView(controller->getAuthorList());
}
void View::authorsView(list<Author *> authors)
{

    int count = 1;
    for (auto it = authors.cbegin(); it != authors.cend(); it++)
    {
        cout << count++ << ".\n"
             << **it << endl;
    }
}

void View::descryptRes(int res)
{
    BaseController *controller = new AuthorController;
    cout
        << (res == controller->SUCCESS ? "Sucess" : res == controller->FAIL             ? "Fail"
                                                : res == controller->EXISTED_AUTHOR     ? "existed author"
                                                : res == controller->NON_EXISTED_AUTHOR ? "author doesn't exist"
                                                                                        : ""

            )
        << endl;
}

void View::allBooksView()
{
    system("clear");
    cin.ignore(1000, '\n');
    cout << "All books :\n\n";
    BookController controller;
    this->booksView(controller.allBooks());
}
void View::booksView(list<Book *> books)
{
    int count = 1;
    for (auto it = books.cbegin(); it != books.cend(); it++)
    {
        cout << count++ << ".\n"
             << **it << endl;
    }
}

void View::allBooksNameView()
{
    system("clear");
    cin.ignore(1000,'\n');
    
    string name;
    cout << "Find Books" << endl
         << endl;
    
    cout<<"Book's name :";
    getline(cin,name);
    BookController controller;
    booksView(controller.allBooksName(name));
}

void View::allBooksISBNView()
{
    system("clear");
    cin.ignore(1000,'\n');
    
    
    string ISBN;
    cout << "Find Books" << endl
         << endl;
    
    cout<<"Book's ISBN :";
    getline(cin,ISBN);
    BookController controller;
    booksView({controller.bookISBN(ISBN)});
}