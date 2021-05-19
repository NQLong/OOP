#ifndef B70CB826_F6A3_438C_8CE5_8631A2E940D7
#define B70CB826_F6A3_438C_8CE5_8631A2E940D7

#include <string>
#include <iostream>
#include <iomanip>
#include <ctime>
#include <list>

using namespace std;


#define SECOND_IN_DAY 86400

enum Language
{
    ENGLISH,
    FRENCH,
    GERMAN,
    SPANISH,
    ITALIAN
};
ostream &operator<<(ostream &os, const Language &a);
Language select_language();

enum AccountState
{
    ACTIVE,
    FROZEN,
    CLOSED
};
ostream &operator<<(ostream &os, const AccountState &a);
AccountState select_account_state();

enum Format
{
    PAPERBACK,
    HARDCOVER,
    AUDIOBOOK,
    AUDIO_CD,
    MP3_CD,
    PDF
};
ostream &operator<<(ostream &os, const Format &a);
Format select_format();

enum UserType
{
    LIBRARIAN,
    PATRON
};
ostream &operator<<(ostream &os, const UserType &u);
UserType select_user_type();

class FullName
{
public:
    string first_name;
    string last_name;
    FullName();
    FullName(
        string _first_name,
        string _last_name)
        : first_name(_first_name),
          last_name(_last_name) {}
    ~FullName();

    static FullName input();

    friend ostream &operator<<(ostream &os, const FullName &f);

    void modify();
};

class Address
{
public:
    string
        street,
        city,
        state,
        zip_code,
        country;
    Address();
    ~Address();
    Address(string _street, string _city, string _state, string _zip_code, string _country)
        : street(_street), city(_city), state(_state), zip_code(_zip_code), country(_country) {}

    friend ostream &operator<<(ostream &os, const Address &address)
    {
        return os << address.street << " street, " << address.city << " city, " << address.state << " state, " << address.country << ", zipcode: " << address.zip_code;
    }

    static Address inputAddress();
};

bool is_consist(list<int>, int);

bool is_valid_date(time_t);

time_t input_time();

time_t input_date();
void wait();

void clear();

bool select_statement(string false_stmt, string true_stmt);

string lower_string(string in);
#endif /* B70CB826_F6A3_438C_8CE5_8631A2E940D7 */
