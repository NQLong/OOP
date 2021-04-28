#include "../Header/AuthorController.h"

AuthorController::AuthorController() : BaseController() {}
AuthorController::~AuthorController() {}

int AuthorController::createAuthor(string name, char gender)
{
    if (data->existAuthor(name))
        return this->EXISTED_AUTHOR;
    else
        data->addAuthor(new Author(name, &gender));
    return SUCCESS;
}

int AuthorController::removeAuthor(string name)
{
    Author *ptr = data->getAuthor(name);
    if (!ptr)
        return NON_EXISTED_AUTHOR;
    data->removeAuthor(ptr);
    // cout << *ptr;
    delete ptr;
    return SUCCESS;
}