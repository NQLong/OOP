#include <iostream>
#include <bits/stdc++.h>
#include <string>
using namespace std;

class A
{
};
class B
{
public:
    A *a;
    B() {}
    B(A *a)
    {
        this->a = a;
    }
};

class C : public A
{
public:
    int z = 0;
    B b;
    C()
    {
        this->b = B(this);
    }
};

int main()
{
    C c;
    cout<<c.b.a->z;

}