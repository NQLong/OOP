#include <bits/stdc++.h>

using namespace std;

class Person
{
private:
    string name;
    string address;

public:
    Person(string name, string address)
    {
        this->name = name;
        this->address = address;
    }
    string getName() { return name; }
    string getAddress()
    {
        return address;
    }
    void setName(string name) { this->name = name; }
    void setAddress(string address)
    {
        this->address = address;
    }
    string toString()
    {
        return "Person(name = " + name + ", address = " + address + ")";
    }
};
class Student : public Person
{
private:
    string program;
    int year;
    double fee;

public:
    Student(string name, string address, string program, int year, double fee) : Person(name, address)
    {
        this ->program = program;
        this ->year = year;
        this ->fee = fee;
    }
    void setYear(int year)
    {
        year = year;
    }
    void setFee(double fee)
    {

        fee = fee;
    }
    void setProgram(string program)
    {
        program = program;
    }
    string toString()
    {
        return "Student(" + Person::toString() + ",program= " + program + ",year= " + to_string(year) + ",fee= " + to_string(fee) + ")";
    }
};
class Staff : public Person
{
};

int main()
{
    Student test("Long", "BienHoa", "dai tra", 1, 1.0);
    cout << test.toString();
    return 0;
}