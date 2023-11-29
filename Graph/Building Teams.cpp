#include<bits/stdc++.h>
using namespace std;
#define int long long int
static const int MOD = (int)1e9 + 7;

int n, m;
vector<vector<int>> adj;
vector<bool> seen;
vector<int> color;
bool possible = true;

void dfs(int src, int par) {
    seen[src] = true;
    if(par == -1) color[src] = 0;
    else color[src] = 1 - color[par];
    for(auto neigh : adj[src]) {
        if(seen[neigh]) continue;
        dfs(neigh, src);
    }
    for(auto neigh : adj[src]) {
        if(color[src] == color[neigh]) {
            possible = false;
            return;
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    adj.resize(n); seen.resize(n, false); color.resize(n, -1);
    for(int i = 0; i < m; i ++) {
        int u, v;
        cin >> u >> v;
        u --; v --;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i = 0; i < n; i ++) {
        if(seen[i]) continue;
        dfs(i, -1);
        if(!possible) {
            cout << "IMPOSSIBLE\n";
            return 0;
        }
    }
    for(auto it : color) cout << it + 1 << " ";
    return 0;
}