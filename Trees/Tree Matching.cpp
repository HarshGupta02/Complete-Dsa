#include <bits/stdc++.h>
using namespace std;
  
#define int long long
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
static const int MOD = (int)1e9+7;

int n;
vector<vector<int>> adj, dp;

void dfs(int src, int par, int choice) {
    if(choice == 1) {
        int all_not_chosen = 0;
        for(auto neigh : adj[src]) {
            if(neigh == par) continue;
            if(dp[neigh][1] == -1) dfs(neigh, src, 1);
            all_not_chosen += dp[neigh][1];
            if(dp[neigh][0] == -1) dfs(neigh, src, 0);
        }
        int maxi = all_not_chosen;
        for(auto neigh : adj[src]) {
            if(neigh == par) continue;
            maxi = max(maxi, 1 + dp[neigh][0] + all_not_chosen - dp[neigh][1]);
        }
        dp[src][1] = max(dp[src][1], maxi);
    }else {
        int ans = 0;
        for(auto neigh : adj[src]) {
            if(neigh == par) continue;
            if(dp[neigh][1] == -1) dfs(neigh, src, 1);
            ans += dp[neigh][1];
        }
        dp[src][0] = max(dp[src][0], ans);
    }
}

void solve(){
    adj.clear(); dp.clear();
    cin >> n;
    adj.resize(n + 1); dp.resize(n + 1, vector<int> (2, -1));
    for(int i = 0; i < n - 1; i ++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1, -1, 1);
    dfs(1, -1, 0);
    cout << max(dp[1][0], dp[1][1]) << "\n";
}

signed main() {
    fast_cin();
    int test_cases = 1;
    // cin >> test_cases;
    for(int it = 1; it <= test_cases; it ++) {
        solve();
    }
    return 0;
}