#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
const ll MOD = 1e9+7;

#define int long long
#define nline "\n"
#define all(a) (a).begin(),(a).end()
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int go(int i, int n, int mask, vector<int> &a, vector<int> &b, vector<int> &c, vector<vector<int>> &dp, vector<vector<bool>> &seen) {
    if(mask == 7) return 0;
    if(i >= n) return -1e15;
    if(seen[i][mask]) return dp[i][mask];
    seen[i][mask] = true;
    int ans = go(i + 1, n, mask, a, b, c, dp, seen);
    int b1 = mask & (1 << 0);
    int b2 = mask & (1 << 1);
    int b3 = mask & (1 << 2);
    if(b1 == 0) ans = max(ans, a[i] + go(i + 1, n, mask | (1 << 0), a, b, c, dp, seen));
    if(b2 == 0) ans = max(ans, b[i] + go(i + 1, n, mask | (1 << 1), a, b, c, dp, seen));
    if(b3 == 0) ans = max(ans, c[i] + go(i + 1, n, mask | (1 << 2), a, b, c, dp, seen));
    return dp[i][mask] = ans;
}

void solve(){
    int n;
    cin >> n;
    vector<int> a(n), b(n), c(n);
    vector<vector<int>> dp(n + 1, vector<int> (9, -1));
    vector<vector<bool>> seen(n + 1, vector<bool> (9, false));
    for(int i = 0; i < n; i ++) cin >> a[i];
    for(int i = 0; i < n; i ++) cin >> b[i];
    for(int i = 0; i < n; i ++) cin >> c[i];
    int mask = 0;
    cout << go(0, n, mask, a, b, c, dp, seen) << "\n";
}

signed main() {
    fast_cin();
    ll test_cases;
    cin >> test_cases;
    for(ll it=1;it<=test_cases;it++) {
        solve();
    }
    return 0;
}