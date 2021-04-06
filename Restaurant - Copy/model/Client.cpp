#include <bits/stdc++.h>

#include "Client.h"

using namespace std;
Client::Client() {}
Client::Client(string _name, string _address, string _taxId) : Person(_name, _address)
{
    taxId = _taxId;
}

void Client::setTaxId(string _taxId)
{
    taxId = _taxId;
}
string Client::getTaxID()
{
    return taxId;
}
string Client::toString()
{
    return "Client(" + Person::toString() + ",taxId = " + taxId + ")";
}

Client::Client(const Client &_client) : Person(_client)
{
    this->taxId = _client.taxId;
}

Client& Client::operator=(const Client& _client){
    this->taxId = _client.taxId;
    return *this;
}