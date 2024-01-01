#include <bits/stdc++.h>
using namespace std;
  
#define int long long
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
static const int MOD = (int)1e9+7;

const int LOG = 20;
vector<vector<int>> adj, dp;
vector<int> depth;

void dfs(int src, int par) {
    for(auto neigh : adj[src]) {
        if(neigh == par) continue;
        depth[neigh] = 1 + depth[src];
        dp[neigh][0] = src;
        for(int i = 1; i <= LOG; i ++) {
            dp[neigh][i] = dp[dp[neigh][i - 1]][i - 1];
        }
        dfs(neigh, src);
    }
}

int moveUp(int node, int val) {
    for(int i = LOG; i >= 0; i --) {
        if(val & (1 << i)) node = dp[node][i];
    }
    return node;
}

void solve(){
    adj.clear(); dp.clear(); depth.clear();
    int n, q;
    cin >> n >> q;
    adj.resize(n + 1); depth.resize(n + 1, 0);
    dp.resize(n + 1, vector<int> (LOG + 1, 0));
    for(int i = 2; i <= n; i ++) {
        int par; 
        cin >> par;
        adj[par].push_back(i);
    }
    dfs(1, 0);
    for(int i = 0; i < q; i ++) {
        int x, k;
        cin >> x >> k;
        int ancestor = moveUp(x, k);
        if(ancestor == 0) ancestor = -1;
        cout << ancestor << "\n";
    }
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