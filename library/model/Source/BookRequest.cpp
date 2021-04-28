
#include "../Header/BookRequest.h"

BookRequest::BookRequest() {}
BookRequest::BookRequest(int BLcode, string ISBN, int memberID, time_t dueDate)
{
    this->memberID = memberID;
    this->dueDate = dueDate;
    this->ISBN = ISBN;
    this->BLcode = BLcode;
    this->status = 'h';
}

int BookRequest::getBLcode()
{
    return this->BLcode;
}

void BookRequest::setBLcode(int BLcode)
{
    this->BLcode = BLcode;
}

string BookRequest::getISBN()
{
    return this->ISBN;
}

void BookRequest::setISBN(string ISBN)
{
    this->ISBN = ISBN;
}

int BookRequest::getMemberID()
{
    return this->memberID;
}

void BookRequest::setMemberID(int memberID)
{
    this->memberID = memberID;
}

time_t BookRequest::getDueDate()
{
    return this->dueDate;
}

void BookRequest::setDueDate(time_t dueDate)
{
    this->dueDate = dueDate;
}

time_t BookRequest::getReturnDate()
{
    return this->returnDate;
}

void BookRequest::setReturnDate(time_t returnDate)
{
    this->returnDate = returnDate;
}

char BookRequest::getStatus()
{
    return this->status;
}

void BookRequest::setStatus(const char *status)
{
    this->status = *status;
}

ostream &operator<<(ostream &os, const BookRequest &req)
{
    os
        << left << setw(15) << "BLcode"<<": "<<req.BLcode<<endl
        << left << setw(15) << "ISBN"<<": "<<req.ISBN<<endl
        << left << setw(15) << "Request owner"<<": "<<req.memberID<<endl
        << left << setw(15) << "status"<<": "<<req.status<<endl
        << left << setw(15) << "dueDate"<<": "<<(char*)ctime(&req.dueDate)
        << left << setw(15) << "returnDate"<<": "<<(req.returnDate==0?"Unknown":(char*)ctime(&req.returnDate))<<endl

        ;
    return os;
        // char* dt = ctime(&now);
}