#ifndef DA52A8B7_672F_48AE_B0FF_F785C2575B69
#define DA52A8B7_672F_48AE_B0FF_F785C2575B69

using namespace std;
#include <iostream>
#include <string>


class Person
{
private:
    string name;
    string email;
    string phone;

public:
    Person(){}
    Person(string _name, string _email, string _phone):
        name(_name), email(_email), phone(_phone){}
    ~Person();
    
    string getName();
    void setName(string name);
    string getEmail();
    void setEmail(string email);
    string getPhone();
    void setPhone(string phone);
    friend ostream& operator << (ostream& os,const Person&);
};
// class Person(ABC):
//     def __init__(self, name, email, phone):
//         self.__name = name
//         self.__email = email
//         self.__phone = phone

#endif /* DA52A8B7_672F_48AE_B0FF_F785C2575B69 */
