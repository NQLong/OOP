#ifndef E610AF7F_9477_40F6_947A_4AA6CC3B5A50
#define E610AF7F_9477_40F6_947A_4AA6CC3B5A50

#include "../Constraint/Constraint.h"

class Account
{
private:
    string username;
    string password;
    Address address;
    AccountStatus status = A_ACTIVE;

public:
    Account() {}
    Account(string _username, string _password, Address _address, AccountStatus _status) : username(_username), password(_password), address(_address), status(_status) {}

    ~Account() {}

    static Account inputAccount();
    void modify_account();

    string getPassword();
    void setPassword(string password);

    Address getAddress();
    void setAddress(Address address);

    AccountStatus getStatus();
    void setStatus(AccountStatus status);

    string getUsername();
    void setUsername(string username);

    bool resetPassword();

    friend ostream &operator<<(ostream &os, const Account &);
};

#endif /* E610AF7F_9477_40F6_947A_4AA6CC3B5A50 */
