

// class Member: public User
// {
// private:
// public:
//     Member();
//     Member(int, string, string, string, const char *);
//     void makeBookRequest(Book, time_t, time_t);
// };

// #endif

#include "../Header/Member.h"

Member::Member(int id, string username, string name, string phone, string address, const char *status,const char *Typ)
    : User(id, username, name, phone, address, status,Typ) {}

BookRequest* Member::makeBookRequest(int BLcode, Book *book, time_t dueDate)
{
    return new BookRequest(BLcode,book->getISBN(),this->getId(),dueDate);    
}