#ifndef C16B5BE8_4B13_4E03_9810_EF6251C3F071
#define C16B5BE8_4B13_4E03_9810_EF6251C3F071

#include "User.h"
#include "Account.h"
#include "../Library/Library.h"
class Patron
    : public User
{
private:
    Account *account = NULL;

public:
    ~Patron();
    Patron() : User(PATRON) {}
    Patron(
        FullName _full_name,
        Address _address,
        string username,
        string password)
        : User(username, password, _full_name, _address, PATRON),
          account(Account::add_account(Account())) {}

    friend ostream &operator<<(ostream &os, const Patron &p);

    Account *get_account();
    void set_account(Account *);

    static Patron* input_patron();

    void view(Library *);
};

#endif /* C16B5BE8_4B13_4E03_9810_EF6251C3F071 */
