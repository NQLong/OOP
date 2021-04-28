#include <bits/stdc++.h>

using namespace std;

// class abcAc
// {
// public:
//     virtual void view() = 0;
//     virtual void view2() = 0;
// };

// class TempAc: public abcAc
// {
// public:
//     void view() {}
//     void view2() {}
// };

// class A: public TempAc
// {
// public:
//     void view()
//     {
//         cout << "hello";
//     }
// };

class A
{
public:
    int a;
    A(int i) : a(i) {}
    static A newA()
    {
        return A(5);
    }
};

typename getType(){
    return A;
}

int main()
{
    getType() a = A::newA();
    cout << a.a;
}