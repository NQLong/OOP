#include "../../Header/Actor/Account.h"
#include "../../Header/Book/BookItem.h"

int Account::new_numb = 0;
list<Account> Account::accounts;

Account::~Account() {}

bool Account::add_history(string code)
{
    this->History.push_back(code);
    return true;
}

bool Account::add_owed(string code)
{
    this->owed_book.push_back(code);
    return true;
}

bool Account::remove_owed(string code)
{
    this->owed_book.remove(code);
    return true;
}

bool Account::add_reserved(string code)
{
    this->reserved_book.push_back(code);
    return true;
}

bool Account::remove_reserved(string code)
{
    this->reserved_book.remove(code);
    return true;
}

void Account::check_state()
{
    this->state = ACTIVE;
    if (owed_book.size() == 12)
        this->state = FROZEN;
    else
    {
        for (auto it = owed_book.begin(); it != owed_book.end(); it++)
            if (BookItem::get_book_item(*it)->isIs_overdue())
            {
                this->state = FROZEN;
                return;
            }
    }
}
Account::Account()
{
    opened = time(0);
    this->number = new_numb++;
    state = ACTIVE;
}

Account *Account::add_account(Account new_acc)
{
    accounts.push_back(new_acc);
    return &accounts.back();
}

Account *Account::get_account(int number)
{
    for (auto it = accounts.begin(); it != accounts.end(); it++)
        if (it->getNumber() == number)
            return &*it;
    return NULL;
}

int Account::getNumber()
{
    return this->number;
}

void Account::setNumber(int number)
{
    this->number = number;
}

list<string> Account::getHistory()
{
    return this->History;
}

void Account::setHistory(list<string> History)
{
    this->History = History;
}

AccountState Account::getState()
{
    return this->state;
}

void Account::setState(AccountState state)
{
    this->state = state;
}

string Account::getUsername()
{
    return this->username;
}

void Account::setUsername(string username)
{
    this->username = username;
}

list<Account> *Account::getAccounts()
{
    return &accounts;
}

void Account::setAccounts(list<Account> _accounts)
{
    accounts = _accounts;
}

list<string> Account::getOwed_book()
{
    return owed_book;
}

void Account::setOwed_book(list<string> _owed_book)
{
    owed_book = _owed_book;
}

list<string> Account::getReserved_book()
{
    return reserved_book;
}

void Account::setReserved_book(list<string> _reserved_book)
{
    reserved_book = _reserved_book;
}
