#include "../../Header/Constraint/Address.h"

Address Address::inputAddress()
{
    Address temp;
    cout << "Street: ";
    getline(cin, temp.street);
    cout << "State: ";
    getline(cin, temp.city);
    cout << "State: ";
    getline(cin, temp.state);
    cout << "zip-code: ";
    getline(cin, temp.zip_code);
    cout << "Country: ";
    getline(cin, temp.country);
    return temp;
}

Address::Address() {}
Address::~Address() {}

bool operator==(const Address &rhs, const Address &lhs)
{
    return (
        (lhs.city == rhs.city) &&
        (lhs.state == rhs.state) &&
        (lhs.street == rhs.street) &&
        (lhs.zip_code == rhs.zip_code) &&
        (lhs.country == rhs.country)

    );
}

ostream &operator<<(ostream &os, const Address &address)
{
    return os
           << address.street << " street, "
           << address.city << " city, "
           << address.state << " state, "
           << address.country
           << ", zipcode: " << address.zip_code;
}
