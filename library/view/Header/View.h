#ifndef D959D317_BD98_4A06_985A_4FDACC66DF41
#define D959D317_BD98_4A06_985A_4FDACC66DF41

#include <bits/stdc++.h>

#include "../../controller/Header/Controller.h"

using namespace std;

class View
{
protected:
    BaseController *controller = NULL;
    
public:
    View();
    virtual ~View();
    
    virtual void mainView() = 0;

    void descryptRes(int);

    void allAuthorsView();
    void authorsView(list<Author *>);

    void allBooksView();
    void booksView(list<Book*>);

    void allBooksNameView();
    void allBooksISBNView();
};

#endif /* D959D317_BD98_4A06_985A_4FDACC66DF41 */
