#include <bits/stdc++.h>
using namespace std;
  
#define int long long
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
static const int MOD = (int)1e9+7;

int n, ans;
vector<vector<int>> dp;
vector<char> val;

void dfs(int src, int par, int op) {
    bool isChild = (dp[src][0] == 0 and dp[src][1] == 0);
    if(isChild) {
        ans = min(ans, op);
        return;
    }
    if(val[src] == 'L') {
        if(dp[src][0]) dfs(dp[src][0], src, op);
        if(dp[src][1]) dfs(dp[src][1], src, op + 1);
    }else if(val[src] == 'R') {
        if(dp[src][0]) dfs(dp[src][0], src, op + 1);
        if(dp[src][1]) dfs(dp[src][1], src, op);
    }else {
        if(dp[src][0]) dfs(dp[src][0], src, op + 1);
        if(dp[src][1]) dfs(dp[src][1], src, op + 1);
    }
}

void solve(){
    cin >> n;
    dp.resize(n + 1, vector<int> (2));
    val.resize(n + 1);
    for(int i = 1; i <= n; i ++) cin >> val[i];
    for(int i = 1; i <= n; i ++) {
        int l, r;
        cin >> l >> r;
        dp[i][0] = l; dp[i][1] = r;
    }
    int op = 0;
    dfs(1, -1, op);
    cout << ans << "\n";
}

signed main() {
    fast_cin();
    int test_cases;
    cin >> test_cases;
    for(int it = 1; it <= test_cases; it ++) {
        val.clear(); dp.clear();
        ans = 1e9;
        solve();
    }
    return 0;
}