#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
const ll MOD = 998244353;

#define nline "\n"
#define all(a) (a).begin(),(a).end()
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

ll mod_add(ll a,ll b){
    if(a+b<=MOD)
     return a+b;
    return ((a+b+MOD)%MOD);
}

ll mod_sub(ll a,ll b){
    if(a-b<=MOD)
     return a-b;
    return ((a-b+MOD)%MOD);
}

ll mod_mul(ll a,ll b){
    if(a*b<=MOD)
     return a*b;
    return ((a*b+MOD)%MOD);
}

ll power(ll x, ll y, ll p)
{
    ll res = 1;
    x = x % p;
    while (y > 0) {
        if (y & 1)
            res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}
 
ll modInverse(ll a, ll p)
{
    return power(a, p - 2, p);
}
 
ll modFact(ll n, ll p)
{
    if (p <= n)
        return 0;
 
    ll res = (p - 1);
 
    for (ll i = n + 1; i < p; i++)
        res = (res * modInverse(i, p)) % p;
    return res;
}

void solve(){
    ll m, n;
    cin >> m >> n;
    if(m == 1 and n == 1){
        cout << 0 << nline;
        return;
    }

    // number of valid paths 
    ll ans = 1;
    for (ll i = n; i < (m + n - 1); i ++) {
        ans = mod_mul(ans, i);
        ans /= (i - n + 1);
    }

    cout << ans << nline;

    ll total = (m + n - 1);
    ll res = modFact(total, MOD);
    res = mod_mul(res, ans);
    cout << res << nline;
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