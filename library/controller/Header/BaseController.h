#ifndef BaseController_included
#define BaseController_included

#include "../../model/Header/Data.h"

class BaseController
{
public:
    int SUCCESS = 1, FAIL = 2,
        EXISTED_AUTHOR = 3, NON_EXISTED_AUTHOR = 4,
        EXISTED_USERNAME = 5, INVALID_ACCOUNT_TYP = 6,
        NON_EXISTED_USER = 7, NON_ACTIVE_ACCOUNT = 11,
        EXISTED_BOOK = 8, NON_EXISTED_BOOK = 9, NON_AVAILABLE_BOOK = 10,
        BORROW_TIME_EXEEDED = 12,
        NON_EXISTED_REQUEST = 13, ALREADY_HANDLED_REQ = 14, NO_MATCH_BOOK_AND_REQUEST = 15,
        ALREADY_RETURNED = 16;

protected:
    static Data *data;

public:
    BaseController();
    virtual ~BaseController();

    void setData(Data *data);
    Data *getData();

    list<Author *> getAuthorList();
};

#endif