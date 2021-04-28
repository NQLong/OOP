#include <bits/stdc++.h>


using namespace std;

class A {
    private:int a = 1;
    public:
        string toString(){
            return "hello" + to_string(a);
        }
};

class B: public A {
    public:
        string toString(){
            return A::toString() + " hello again";
        }
};
int main(){
    B hello;
    cout<<hello.toString();
}