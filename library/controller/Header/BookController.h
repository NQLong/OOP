#ifndef AB90FEF8_0019_4008_8EBE_E76CE37E657D
#define AB90FEF8_0019_4008_8EBE_E76CE37E657D
#include "BaseController.h"

class BookController : public BaseController
{
private:
public:
    BookController();
    ~BookController();
    int createBook(string, string, string, list<string>, int);
    int removeBook(string);
    int lendBook();

    list<Book *> allBooksName(string name);
    Book *bookISBN(string name);
    list<Book *> allBooks();
};
#endif /* AB90FEF8_0019_4008_8EBE_E76CE37E657D */
