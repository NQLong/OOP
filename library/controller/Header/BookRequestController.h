#ifndef AA6F1BCF_EAA4_4CE2_8C52_E6C684599547
#define AA6F1BCF_EAA4_4CE2_8C52_E6C684599547
#include "BaseController.h"

class BookRequestController : public BaseController
{
public:
    BookRequestController() {}
    ~BookRequestController() {}

    int createBookRequest(Member* member, string ISBN, int);

    BookRequest *bookRequestCode(int code);
    int handlingBookRequest(int code, char);
    int checkRequest(int code);

    int receiveBook(int code, string ISBN);

    list<BookRequest*> requests(char status);
};

#endif /* AA6F1BCF_EAA4_4CE2_8C52_E6C684599547 */
