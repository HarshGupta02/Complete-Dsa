#include <iostream>
using namespace std;

class X {
private:
    // static int a = 76;
    static int a;
public:
    static int getA() { return a; }
};

int X::a = 5;

int main() {
    cout << X::getA() << endl;
    return 0;
}
