#ifndef DA52A8B7_672F_48AE_B0FF_F785C2575B69
#define DA52A8B7_672F_48AE_B0FF_F785C2575B69

using namespace std;

#include "../Constraint/Constraint.h"

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
    
    void input_person();

    string getName();
    void setName(string name);
    string getEmail();
    void setEmail(string email);
    string getPhone();
    void setPhone(string phone);
    friend ostream& operator << (ostream& os,const Person&);
    friend bool operator==(const Person& lhs, const Person& rhs);
    static void render_person(Person p);
    static void render_person_title();
};


#endif /* DA52A8B7_672F_48AE_B0FF_F785C2575B69 */
