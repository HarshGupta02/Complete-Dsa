#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
const ll MOD = 1e9+7;

#define nline "\n"
#define all(a) (a).begin(),(a).end()
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

using ll = long long int;
const ll MAXN = 256;

bool cmp(vector<ll> &cp, vector<ll> &ct) {
    for(int i = 0; i < MAXN; i ++) {
        if(cp[i] != ct[i]) return false;
    }
    return true;
}

void solve(){
    string a, b;
    cin >> a >> b;
    ll m = b.size(), n = a.size();
    vector<ll> cp(MAXN, 0), ct(MAXN, 0);
    for(int i = 0; i < m; i ++) {
        cp[b[i]] ++;
        ct[a[i]] ++;
    }
    ll cnt = 0;
    // if(cmp(cp, ct)) cnt += (n - m + 1);
    for(int i = m; i < n; i ++) {
        if(cmp(cp, ct)) {
            ll start = i - m, endd = i - 1;
            ll left = (i - m), right = (n - endd - 1);
            cnt += (left * (right + 1)) + right + 1;
            // cnt += (n - endd + 1) * (i - m);
            // cout << (n - endd) * (i - m) << endl;
        }
        ct[a[i]] ++;
        ct[a[i - m]] --;
    }
    cout << cnt << endl;
    // return cnt;
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

using ll = long long int;
const ll MAXN = 2e5 + 2;
vector<ll> fact;
const ll MOD = 1e9 + 7;

ll mod_add(ll a,ll b){ if(a+b<=MOD) return a+b; return ((a+b+MOD)%MOD); }
ll mod_sub(ll a,ll b){ if(a-b<=MOD) return a-b; return ((a-b+MOD)%MOD); }
ll mod_mul(ll a,ll b){ if(a*b<=MOD) return a*b; return ((a*b+MOD)%MOD); }

void precompute(){
    fact.resize(MAXN);
    fact[0] = 1;
    for(int i = 1; i < MAXN; i ++) fact[i] = mod_mul(fact[i - 1], i);
}

ll fast_exp(ll a,ll b){
    ll res = 1;
    while(b > 0){
        if(b & 1) res = mod_mul(res, a);
        b >>= 1;
        a = mod_mul(a, a);
    }
    return res;
}

ll mod_inv(ll x) { return fast_exp(x, MOD - 2); }
ll divide(ll a, ll b) { return mod_mul(a, mod_inv(b)); }
ll ncr(ll n, ll r) { return divide(fact[n], mod_mul(fact[r], fact[n - r])); }