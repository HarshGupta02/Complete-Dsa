#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
const ll MOD = 1e9+7;

#define nline "\n"
#define all(a) (a).begin(),(a).end()
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

using ll = long long int;
ll fast_exp(ll a, ll b) {
    ll res = 1;
    while(b > 0) {
        if(b & 1) res = res * a;
        b >>= 1;
        a = a * a;
    }
    return res;
}

void solve(){
    ll low, high;
    cin >> low >> high;
    ll cnt = 0;
    for(int x = 0; x <= 20; x ++) {
        for(int y = 0; y <= 20; y ++) {
            ll a = fast_exp(3, x), b = fast_exp(5, y);
            ll prod = a * b;
            assert(prod <= (ll)1e18);
            if(prod >= low and prod <= high) cnt ++;
        }
    }
    return cnt;
    cout << cnt << endl;
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