#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
const int MOD = 1e9+7;

#define nline "\n"
#define all(a) (a).begin(),(a).end()
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

ll dp[100005][2][6];


ll go(ll l, int chance, int last) {
    if(l <= 0) {
        if(chance == 0 and last == 4) return 1;
        return 0;
    }
    if(dp[l][chance][last + 1] != -1) return dp[l][chance][last + 1];
    ll ans = 0;
    ans = (ans + go(l - 1, 1 - chance, 1)) % MOD;
    ans = (ans + go(l - 2, chance, 2)) % MOD;
    ans = (ans + go(l - 3, chance, 3)) % MOD;
    ans = (ans + go(l - 4, chance, 4)) % MOD;
    return dp[l][chance][last + 1] = ans;
}

void precompute() {
    memset(dp, -1, sizeof(dp));
    int ans = 0;
    for(int l = 1; l <= 100000; l ++) {
        ans = (ans + go(l, 0, -1)) % MOD;
    }
}

void solve(){
    ll l;
    cin >> l;
    cout << dp[l][0][0] << "\n";
}

int main() {
    fast_cin();
    precompute();
    ll test_cases;
    cin >> test_cases;
    for(ll it=1;it<=test_cases;it++) {
        solve();
    }
    return 0;
}