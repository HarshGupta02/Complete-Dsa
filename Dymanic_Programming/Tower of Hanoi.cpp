/*
f(n, a, b, c) = return the sequence of moves to move n tiles from a to
c via b.
*/

#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using ll = long long int;

ll fast_exp(ll a, ll b){
    ll res = 1;
    while(b > 0){
        if(b & 1) res = (res * a);
        b >>= 1;
        a = (a * a);
    }
    return res;
}

void f(int n, int a, int b, int c){
    if(n == 1) {
        cout << a << " " << c << "\n";
        return;
    }
    f(n - 1, a, c, b);
    cout << a << " " << c << "\n";
    f(n - 1, b, a, c);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll n;
    cin >> n;
    cout << fast_exp(2, n) - 1 << "\n";
    f(n, 1, 2, 3);
    return 0;
}