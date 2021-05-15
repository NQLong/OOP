#ifndef B4411DEB_A76C_4A80_9E2E_8E7FD7D01A2E
#define B4411DEB_A76C_4A80_9E2E_8E7FD7D01A2E
#include <iostream>
#include <string>
using namespace std;

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

    friend ostream &operator<<(ostream &os, const Address &address);

    friend bool operator==(const Address &, const Address &address);

    static Address inputAddress();
};

#endif /* B4411DEB_A76C_4A80_9E2E_8E7FD7D01A2E */
