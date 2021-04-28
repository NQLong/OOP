#include "../Header/UserController.h"

UserController::UserController() {}
UserController::~UserController() {}

int UserController::createUser(string userName, string name, string phone, string address, char status, char Typ)
{
    if (data->existLibrarian(userName) || data->existMember(userName))
        return EXISTED_USERNAME;
    int id = data->getUsers().back() ? data->getUsers().back()->getId() + 1 : 0;
    if (Typ == 'l')
    {
        data->addLibrarian(new Librarian(
            id,
            userName,
            name,
            phone,
            address,
            &status, &Typ));
    }
    else if (Typ == 'm')
    {

        data->addMember(new Member(
            id,
            userName,
            name,
            phone,
            address,
            &status, &Typ));
    }
    else
        return INVALID_ACCOUNT_TYP;
    return SUCCESS;
}

list<User *> UserController::allUsers()
{
    return data->getUsers();
}

int UserController::removeUser(string userName)
{
    User *ptr = data->getUser(userName);
    if (!ptr)
        return NON_EXISTED_USER;
    if (data->removeUser(ptr))
    {
        delete ptr;
        return SUCCESS;
    }
    return FAIL;
}


User* UserController::userOfUsername(string username){
    return data->getUser(username);
}


int UserController::setAccountStatus(string username,char status){
    User* user = data->getUser(username);
    if (!user) return NON_EXISTED_USER;

    user->setStatus(&status);
    return SUCCESS;

}


