#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
const ll MOD = 1e9+7;

#define nline endl
#define all(a) (a).begin(),(a).end()
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

#define debug(x) cout<< #x <<" = "; _print(x); cout <<endl
void _print(ll t) {cout << t;}
void _print(int t) {cout << t;}
void _print(string t) {cout << t;}
void _print(char t) {cout << t;}
void _print(ld t) {cout << t;}
void _print(double t) {cout << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cout << "{"; _print(p.first); cout << ","; _print(p.second); cout << "}"; cout << endl;}
template <class T> void _print(vector <T> v) {cout << "[ "; for (T i : v) {_print(i); cout << " ";} cout << "]"; cout << endl;}
template <class T> void _print(set <T> v) {cout << "[ "; for (T i : v) {_print(i); cout << " ";} cout << "]"; cout << endl;}
template <class T> void _print(multiset <T> v) {cout << "[ "; for (T i : v) {_print(i); cout << " ";} cout << "]"; cout << endl;}
template <class T, class V> void _print(map <T, V> v) {cout << "[ "; for (auto i : v) {_print(i); cout << " ";} cout << "]"; cout << endl;}

ll fast_exp(ll a,ll b){
    ll res = 1;
    while(b>0){
        if(b&1){
            res = res * a;
        }
        b>>=1;
        a = a * a;
    }
    return res;
}

void solve(){
    ll n;
    cin >> n;
    ll odd_divisor;
    if(n % 2 == 1) {
        odd_divisor = n;
        ll A , B;
        bool is = false;
        ll left = 0, right = sqrtl(odd_divisor);
        while(left <= right){
            if(left * left + right * right == odd_divisor){
                is = true;
                A = left, B = right;
                break;
            }
            else if(left * left + right * right < odd_divisor) left ++;
            else right --;
        }
        if(is == false) cout << -1 << nline;
        else cout << A << " " << B << nline;
    }
    else{
        ll temp = n, p = 0;
        while(temp % 2 == 0){
            temp /= 2;
            p ++;
        }
        odd_divisor = temp;
        if(odd_divisor == 1){
            if(p % 2 == 0) cout << 0 << " " << sqrtl(n) << nline;
            else cout << sqrtl(n/2) << " " << sqrtl(n/2) << nline;
            return;
        }
        // if(p % 2 == 1){
        //     cout << -1 << nline;;
        //     return;
        // }
        ll A , B;
        bool is = false;
        ll left = 0, right = sqrtl(odd_divisor);
        while(left <= right){
            if(left * left + right * right == odd_divisor){
                is = true;
                A = left, B = right;
                break;
            }
            else if(left * left + right * right < odd_divisor) left ++;
            else right --;
        }
        if(is == false) cout << -1 << nline;
        else cout << fast_exp(2, p/2) * A << " " << fast_exp(2, p/2) * B << nline;
    }
}

int main() {
    fast_cin();
    ll test_cases;
    cin >> test_cases;
    for(ll it=1;it<=test_cases;it++) {
        solve();
    }
    return 0;
}