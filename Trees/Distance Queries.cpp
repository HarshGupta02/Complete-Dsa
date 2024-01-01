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

int lca(int v, int w) {
    if(depth[v] < depth[w]) swap(v, w);
    int k = depth[v] - depth[w];
    v = moveUp(v, k);
    if(v == w) return v;
    for(int i = LOG; i >= 0; i --) {
        if(dp[v][i] == dp[w][i]) continue;
        v = dp[v][i];
        w = dp[w][i];
    }
    return dp[v][0];
}

void solve(){
    adj.clear(); dp.clear(); depth.clear();
    int n, q;
    cin >> n >> q;
    adj.resize(n + 1); depth.resize(n + 1, 0);
    dp.resize(n + 1, vector<int> (LOG + 1, 0));
    for(int i = 0; i < n - 1; i ++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0);
    for(int i = 0; i < q; i ++) {
        int a, b;
        cin >> a >> b;
        int lcaa = lca(a, b);
        int dist = depth[a] + depth[b] - (2*depth[lcaa]);
        cout << dist << "\n";
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