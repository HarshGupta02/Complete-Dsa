#include<bits/stdc++.h>
using namespace std;
#define int long long int
static const int MOD = (int)1e9 + 7;
using pi = pair<int, int>;

int n, m;
vector<vector<int>> adj;
vector<int> dist1, dist2;
vector<vector<int>> edges;
vector<bool> seen;
bool can = false;

void dfs(int src) {
    seen[src] = true;
    if(src == n - 1) {
        can = true;
        return;
    }
    for(auto neigh : adj[src]) {
        if(seen[neigh]) continue;
        dfs(neigh);
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    dist1.resize(n, 1e18); dist2.resize(n, 1e18);
    seen.resize(n, false); adj.resize(n);
    for(int i = 0; i < m; i ++) {
        int a, b, c;
        cin >> a >> b >> c;
        a --; b --;
        edges.push_back({a, b, -1 * c});
        adj[a].push_back(b);
    }
    if(n == 1 and m == 1) {
        if(edges[0][2] < 0) cout << "-1\n";
        else cout << "0\n";
        return 0;
    }
    dist1[0] = 0;
    for(int i = 0; i < n - 1; i ++) {
        for(auto it : edges) {
            int u = it[0], v = it[1], w = it[2];
            if(dist1[u] != 1e18 and dist1[u] + w < dist1[v]) 
                dist1[v] = dist1[u] + w;
        }
    }
    dist2 = dist1;
    for(int i = 0; i < n - 1; i ++) {
        for(auto it : edges) {
            int u = it[0], v = it[1], w = it[2];
            if(dist2[u] != 1e18 and dist2[u] + w < dist2[v]) 
                dist2[v] = dist2[u] + w;
        }
    }
    for(int i = 0; i < n - 1; i ++) {
        if(dist1[i] != dist2[i] and !seen[i]) {
            dfs(i);
            if(can) {
                cout << "-1\n";
                return 0;
            }
        }
    }
    cout << -1 * dist1[n - 1] << "\n";
    return 0;
}