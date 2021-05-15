#include "../../Header/Actor/User.h"
#include <sstream>
list<User *> User::users;
User::~User() {}
User *User::getUser(string username)
{
    for (auto it = users.begin(); it != users.end(); it++)
        if ((*it)->username == username)
            return *it;
    return NULL;
}

User *User::getUser(string username, string password)
{
    for (auto it = users.begin(); it != users.end(); it++)
        if ((*it)->username == username && (*it)->password == password)
            return *it;
    return NULL;
}

bool User::add_user(User *u)
{
    if (!getUser(u->username))
    {
        users.push_back(u);

        return true;
    }

    return false;
}

void User::input_user_info()
{
    cout << "Username: ";
    getline(cin, username);
    cout << "Password: ";
    getline(cin, password);
    clear();
    cout << "Full name: " << endl;
    this->name = FullName::input();
    clear();
    cout << "Address: " << endl;
    this->address = Address::inputAddress();
    cout << "done";
    wait();
    clear();
    return;
}

void User::modify_user_info()
{
    int option;
    bool loop = true;
    string temp;
    while (loop)
    {
        int count = 1;
        clear();

        cout
            << setw(3) << left << to_string(count++) + "."
            << "modify username." << endl
            << setw(3) << left << to_string(count++) + "."
            << "modify password." << endl
            << setw(3) << left << to_string(count++) + "."
            << "modify name." << endl
            << setw(3) << left << to_string(count++) + "."
            << "modify address." << endl

            << endl
            << setw(3) << left << "0."
            << "Back." << endl;

        cout << endl
             << "Enter your choice: ";
        cin >> option;
        cin.ignore();
        switch (option)
        {
        case 1:
            clear();
            cout << "Username: ";
            getline(cin, temp);
            if (!getUser(temp))
            {
                username = temp;
                clear();
                cout << "success";
                wait();
            }
            break;
        case 2:
            clear();
            cout << "password: ";
            getline(cin, password);
            break;
        case 3:
            clear();
            cout << "new name: " << endl;
            this->name = FullName ::input();
            break;
        case 4:
            clear();
            cout << "new address: " << endl;
            this->address = Address::inputAddress();
            break;

        default:
            loop = false;
            break;
        }
    }

    return;
}

string User::toString() const
{
    stringstream ss;
    ss
        << setw(15)<<left << "Username "<<": " << this->username << endl
        << setw(15)<<left << "Full name "<<": " << this->name << endl
        << setw(15)<<left << "Address "<<": " << this->address

        ;

    string res = "";
    getline(ss,res,'\0');
    return res;
}

User* User::search_user(){
    string username;
    cout<<"Enter username: ";
    getline(cin,username);
    return getUser(username);
}

//getter setter

 list<User*> User::get_users(){
    return users;
}

FullName User::getName()
{
    return this->name;
}

void User::setName(FullName name)
{
    this->name = name;
}

Address User::getAddress()
{
    return this->address;
}

void User::setAddress(Address address)
{
    this->address = address;
}

string User::getUsername()
{
    return this->username;
}

void User::setUsername(string username)
{
    this->username = username;
}

string User::getPassword()
{
    return this->password;
}

void User::setPassword(string password)
{
    this->password = password;
}

UserType User::getTyp()
{
    return this->Typ;
}

void User::setTyp(UserType Typ)
{
    this->Typ = Typ;
}
