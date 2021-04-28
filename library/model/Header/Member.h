/*
Member extend User
--------------------------

--------------------------
+makeBookRequest(book:Book,dueDate:int,returnDate:int):void
+
*/

#ifndef Member_included
#define Member_included

#include "ctime"
#include "User.h"
#include "Book.h"
#include "BookRequest.h"

class Member : public User
{
private:
public:
    Member();
    Member(int, string, string, string, string, const char *,const char *);

    BookRequest* makeBookRequest(int ,Book *, time_t);
};

#endif