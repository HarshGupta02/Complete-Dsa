#include<bits/stdc++.h>
using namespace std;
#define int long long int
static const int MOD = (int)1e9 + 7;

int n, m;
vector<vector<int>> adj;
int dp[100005];

int dfs(int src) {
    if(src == n - 1) return 1;
    if(dp[src] != -1) return dp[src];
    int ans = 0;
    for(auto neigh : adj[src]) {
        ans = (ans + dfs(neigh)) % MOD;
    }
    return dp[src] = ans % MOD;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    adj.resize(n);
    for(int i = 0; i < m; i ++) {
        int a, b;
        cin >> a >> b;
        a --; b --;
        adj[a].push_back(b);
    }
    memset(dp, -1, sizeof(dp));
    cout << dfs(0) << "\n";
    return 0;
}