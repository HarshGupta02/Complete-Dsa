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

ll gcdExtended(ll a, ll b, ll *x, ll *y)
{
    if (a == 0)
    {
        *x = 0, *y = 1;
        return b;
    }
 
    ll x1, y1;
    ll gcd = gcdExtended(b%a, a, &x1, &y1);
    *x = y1 - (b/a) * x1;
    *y = x1;
 
    return gcd;
}

ll modInverse(ll b, ll m)
{
    ll x, y; 
    ll g = gcdExtended(b, m, &x, &y);
 
    if (g != 1)
        return -1;
 
    return (x%m + m) % m;
}
 
ll modDivide(ll a, ll b, ll m)
{
    a = a % m;
    ll inv = modInverse(b, m);
    ll c = (inv * a) % m ;
    return c;
}

void solve(){
    ll m, n;
    cin >> m >> n;
    if((m + n - 1) % 2 == 1){
        cout << 0 << nline;
        return;
    }
    ll ans = 1;
    for (ll i = n; i < (m + n - 1); i ++) {
        ans = mod_mul(ans, i);
        // ans /= (i - n + 1);
        ans = modDivide(ans, i - n + 1, MOD);
    }
    ll total = (m + n - 1);
    ll result = 1;
    for (int i = 1; i <= total; i++) result = (result * i) % MOD;
    cout << mod_mul(result, ans) << nline;
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