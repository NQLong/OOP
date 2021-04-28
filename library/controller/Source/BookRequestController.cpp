#include "../Header/BookRequestController.h"

int BookRequestController::createBookRequest(Member *member, string ISBN, int day)
{
    Book *book_ptr = data->getCatalog()->getBook(ISBN);

    if (!book_ptr)
        return NON_EXISTED_BOOK;
    else if (*book_ptr->getStatus() != 'a')
        return NON_AVAILABLE_BOOK;
    else if (member->getStatus() != 'a')
        return NON_ACTIVE_ACCOUNT;
    else if (day > 14)
        return BORROW_TIME_EXEEDED;

    time_t dueDate = time(0);
    dueDate += day * 3600 * 24;
    int Blcode = data->getRequests().back() ? data->getRequests().back()->getBLcode() + 1 : 0;
    BookRequest *request = member->makeBookRequest(Blcode, book_ptr, dueDate);
    if (request)
    {
        data->addBookRequest(request);
        return SUCCESS;
    }
    return FAIL;
}

BookRequest *BookRequestController::bookRequestCode(int code)
{
    return data->getRequest(code);
}

int BookRequestController::checkRequest(int code)
{
    BookRequest *request = data->getRequest(code);
    if (!request)
        return NON_EXISTED_REQUEST;
    Member *member = data->getMember(request->getMemberID());
    Book *book = data->getCatalog()->getBook(request->getISBN());

    if (member->getStatus() != 'a')
        return NON_ACTIVE_ACCOUNT;
    else if (*book->getStatus() != 'a')
        return NON_AVAILABLE_BOOK;
    else if (request->getStatus() != 'h')
        return ALREADY_HANDLED_REQ;

    return SUCCESS;
}

int BookRequestController::handlingBookRequest(int code, char decission)
{
    BookRequest *request = data->getRequest(code);
    if (decission == 'd')
    {
        request->setStatus("d");
        return SUCCESS;
    }
    Member *member = data->getMember(request->getMemberID());
    Book *book = data->getCatalog()->getBook(request->getISBN());

    book->setStatus("l");
    member->setStatus("s");

    return SUCCESS;
}

list<BookRequest*> BookRequestController::requests(char status){
    return data->getRequests(status);
}

int BookRequestController::receiveBook(int code, string ISBN){
    BookRequest *request = data->getRequest(code);
    
    if (request-> getISBN() != ISBN) return NO_MATCH_BOOK_AND_REQUEST;
    else if (request->getStatus() == 'c') return ALREADY_RETURNED;
    

    Member *member = data->getMember(request->getMemberID());
    Book *book = data->getCatalog()->getBook(request->getISBN());
    
    

    request->setReturnDate(time(0));
    request->setStatus("c");
    
    if (!member->getStatus()=='c') member->setStatus("a");
    book->setStatus("a");

    return SUCCESS;
}