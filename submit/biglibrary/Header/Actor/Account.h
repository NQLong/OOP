#ifndef B9580843_AB1C_4641_A53C_5C52BC90AA41
#define B9580843_AB1C_4641_A53C_5C52BC90AA41
#include "../Constraint/Constraint.h"

class Account
{
private:
    int number;
    list<string> History;
    AccountState state;
    string username;
    list<string> owed_book;
    list<string> reserved_book;
    time_t opened;
    static int new_numb;
    static list<Account> accounts;

public:
    Account();
    ~Account();

    static Account *add_account(Account);

    static Account *get_account(int number);
    static list<Account> *getAccounts();
    static void setAccounts(list<Account> accounts);

    bool add_history(string);
    bool add_owed(string);
    bool remove_owed(string);
    bool add_reserved(string);
    bool remove_reserved(string);


    void check_state();

    int getNumber();
    void setNumber(int number);
    list<string> getHistory();
    void setHistory(list<string> History);
    AccountState getState();
    void setState(AccountState state);
    string getUsername();
    void setUsername(string username);
    list<string> getOwed_book();
    void setOwed_book(list<string> owed_book);
    list<string> getReserved_book();
    void setReserved_book(list<string> reserved_book);
};

#endif /* B9580843_AB1C_4641_A53C_5C52BC90AA41 */
