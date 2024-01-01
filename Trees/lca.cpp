#include<bits/stdc++.h>
using namespace std;

const int LOG = 11;
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

int main(){
    int t;
    cin >> t;
    while(t --) {
        adj.clear(); dp.clear(); depth.clear();
        int n;
        cin >> n;
        adj.resize(n + 1);
        dp.resize(n + 1, vector<int> (LOG + 1, 0));
        depth.resize(n + 1, 0);
        for(int u = 1; u <= n; u ++) {
            int m;
            cin >> m;
            while(m --) {
                int v;
                cin >> v;
                adj[u].push_back(v);
                adj[v].push_back(u);
            }
        }
        dfs(1, 0);
        int q;
        cin >> q;
        while(q --) {
            int v, w;
            cin >> v >> w;
            cout << lca(v, w) << "\n";
        }
    }
    return 0;
}
