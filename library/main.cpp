#include "./view/Header/MainView.h"


#include "./controller/Header/Controller.h"

void makeData()
{
    AuthorController authorcontroller;
    Data* data = authorcontroller.getData();
    BookController bookcontroller;
    UserController usercontroller;
    BookRequestController bookrequestcontroller;

    authorcontroller.createAuthor("Ben Parker", 'm');
    authorcontroller.createAuthor("Peter Parker", 'm');
    authorcontroller.createAuthor("Mary Jane", 'f');

    bookcontroller.createBook("1234", "Legend Of Zelda", "Sony", {"Ben Parker", "Mary Jane"}, 2010);
    bookcontroller.createBook("1235", "Legend Of Shibe", "Sony", {"Ben Parker"}, 2010);
    bookcontroller.createBook("1237", "Legend Of Shibe", "Sony", {"Ben Parker"}, 2010);
    bookcontroller.createBook("1236", "Black Panther", "Sony", {"Ben Parker", "Peter Parker"}, 2010);
    
    // authorcontroller.removeAuthor("Peter Parker");

    usercontroller.createUser("admin", "Long", "012345678", "Wakanda", 'a', 'l');
    usercontroller.createUser("tchaka", "King of Wakanda", "012345678", "Wakanda", 'a', 'l');
    usercontroller.createUser("tchala", "Prince of Wakanda", "012345678", "Wakanda", 'a', 'm');
    usercontroller.createUser("Mbaku", "King of sth", "012345678", "Wakanda", 'a', 'm');
    usercontroller.removeUser("Mbaku");


    bookrequestcontroller.createBookRequest(
        data->getMembers().back(),
        data->getCatalog()->getBooks().front()->getISBN(),
        12
    );
}

int main()
{
    makeData();
    MainView mainview;
    mainview.startApp();
}
