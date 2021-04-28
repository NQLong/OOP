/*
Librarian
----------------------

----------------------
-grantedBookRequest(request:BookRequest):void
-receiveReturnBook(request:BookRequest):void
*/
#ifndef Librarian_included
#define Librarian_included

#include "BookRequest.h"
#include "User.h"

class Librarian : public User
{
public:
    Librarian();
    Librarian(int, string, string, string, string, const char *,const char *);

    void acceptBookRequest(BookRequest *);
    void declineBookRequest(BookRequest *);

    void receiveReturnBook(BookRequest *);
};

#endif