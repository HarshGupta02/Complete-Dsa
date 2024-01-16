#include<bits/stdc++.h>
using namespace std;

class base{
public:
    int x;
    virtual void f() {
        cout << "this is the base class\n";
    }
};

class derived : public base{
public:
    int x;
    void f() {
        cout << "this is the derived class\n";
    }
};

int main(){
    base *b;
    derived d;
    b = &d;
    b -> f();
    return 0;
}