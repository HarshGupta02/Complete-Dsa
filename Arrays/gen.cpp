#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
const ll MOD = 1e9+7;

#define nline "\n"
#define all(a) (a).begin(),(a).end()
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

void solve(){
    ll n;
    cin >> n;
    for(ll a = 0; a <= n; a ++){
        ll bs = n - (a * a);
        ld x = sqrtl(bs);
        if(x == (int)sqrtl(bs)) {
            cout << "YES" << endl;
            cout << a << " " << x << endl;
            return;
        }
    }
    cout << "NO" << endl;
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