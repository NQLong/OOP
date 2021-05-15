#ifndef C3656E71_2D3B_4DB0_B913_5C7CF13EB23E
#define C3656E71_2D3B_4DB0_B913_5C7CF13EB23E

#include "../Constraint/Constraint.h"
#include "../Library/Library.h"

class User
{
private:
    string username;
    string password;
    FullName name;
    Address address;
    UserType Typ;

    static list<User *> users;

public: 
    static list<User*> get_users();
    static User *getUser(string username);
    static User *getUser(string username, string password);
    static bool add_user(User *);
    static User* search_user();
    string toString() const;

    User();
    ~User();
    User(UserType _Typ) : Typ(_Typ) {}
    User(
        string _username,
        string _password,
        FullName _name,
        Address _address,
        UserType _Typ)
        : username(_username),
          password(_password),
          name(_name),
          address(_address), Typ(_Typ) {}

    void input_user_info();

    void modify_user_info();

    string getUsername();
    void setUsername(string username);
    string getPassword();
    void setPassword(string password);
    FullName getName();
    void setName(FullName name);
    Address getAddress();
    void setAddress(Address address);
    UserType getTyp();
    void setTyp(UserType Typ);

    virtual void view(Library*) = 0;
};

#endif /* C3656E71_2D3B_4DB0_B913_5C7CF13EB23E */
