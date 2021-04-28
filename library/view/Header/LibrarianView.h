#ifndef D98EA085_D576_4F92_8784_891AF533C247
#define D98EA085_D576_4F92_8784_891AF533C247

#include "../Header/View.h"
class LibrarianView : public View
{
private:
    Librarian *librarian;

public:
    LibrarianView();
    LibrarianView(Librarian *);

    void mainCommand();
    void mainView();

    void addUser();
    void listAllUser();
    void removeUser();

    void addBook();
    void removeBook();
    void lendBook();
    void recieveBook();

    void addAuthor();
    void removeAuthor();

    void handlingRequestView();

    void allRequestView();
    void requestsView(list<BookRequest *>);

    void onHoldRequestsView();
    void requestsView();

    void userOfUsernameView();

    void userAccountModify(char);

    Librarian *getLibrarian()
    {
        return this->librarian;
    }

    void setLibrarian(Librarian *_librarian)
    {
        this->librarian = librarian;
    };
};

#endif /* D98EA085_D576_4F92_8784_891AF533C247 */
