#include "../../Header/Actor/Account.h"

Account Account::inputAccount()
{
    Account temp;
    temp.status = A_ACTIVE;
    cout << "Username(must be uniq) :";
    getline(cin, temp.username);
    cout << "Password :";
    getline(cin, temp.password);
    temp.address = Address::inputAddress();
    return temp;
}

string Account::getUsername()
{
    return this->username;
}

void Account::setUsername(string username)
{
    this->username = username;
}

string Account::getPassword()
{
    return this->password;
}

void Account::setPassword(string password)
{
    this->password = password;
}

Address Account::getAddress()
{
    return this->address;
}

void Account::setAddress(Address address)
{
    this->address = address;
}

AccountStatus Account::getStatus()
{
    return this->status;
}

void Account::setStatus(AccountStatus status)
{
    this->status = status;
}

bool Account::resetPassword()
{
    string old_password, new_password, temp_password;
    cout << "Setting new password " << endl
         << endl;

    cout << "Old password :";
    getline(cin, old_password);
    if (old_password != this->password)
    {
        cout << "Wrong password";
        return false;
    }
    cout << "New password: ";
    getline(cin, new_password);
    cout << "Renter new password:";
    getline(cin, temp_password);
    if (new_password != temp_password)
    {
        cout << "password confirm mation wrong";
        return false;
    }
    else if (new_password == old_password)
    {
        cout << "new pass word must be different from old password";
        return false;
    }
    this->setPassword(new_password);
    return true;
}

ostream &operator<<(ostream &os, const Account &a)
{
    os
        << "username: " << a.username << endl
        << "password: " << a.password << endl
        << "status: "<< a.status << endl
        << "address: "<< a.address;
    return os;
}