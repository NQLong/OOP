/*
User
----------------
-Id:int
-name: string
-phone: string
-address: string
-status: char
-----------------
+setId(int): void
+setName(string): void
+setPhone(string): void
-setAddress(string): void
-setStatus(char): void

+getId():int
+getName(): string
+getPhone(): string
-getAddress(): string
-getStatus(): char
*/

#ifndef User_included
#define User_included

#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

class User
{
private:
    int Id;
    string name;
    string phone;
    string address;
    char status;
    char Typ;
    string userName;

public:
    User();
    User(int,string, string, string, string, const char *,const char *);

    int getId();
    void setId(int Id);

    string getUserName();
    void setUserName(string userName);

    string getName();
    void setName(string name);

    string getPhone();
    void setPhone(string phone);

    string getAddress();
    void setAddress(string address);

    char getStatus();
    void setStatus(const char *status);
    
    char getType();
    void setType(const char *status);

    friend ostream &operator<<(ostream &os, const User &author);
};

#endif