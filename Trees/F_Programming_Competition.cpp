#include <bits/stdc++.h>
using namespace std;
  
#define int long long
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
static const int MOD = (int)1e9+7;
static const int MAXN = 2e5 + 5;

int n, teams;
vector<int> subtree;
vector<vector<int>> adj;

void dfs1(int src, int par) {
    for(auto neigh : adj[src]) {
        if(neigh == par) continue;
        dfs1(neigh, src);
        subtree[src] += subtree[neigh];
    }
    subtree[src] ++;
}

void dfs2(int src, int par, int free) {
    if(free > 0) {
        free --;
        teams ++;
    }
    int total = 0;
    for(auto neigh : adj[src]) {
        if(neigh == par) continue;
        total += subtree[neigh];
    }
    for(auto neigh : adj[src]) {
        if(neigh == par) continue;
        dfs2(neigh, src, free + total - subtree[neigh]);
    }
}

void solve(){
    cin >> n;
    adj.resize(n + 1); subtree.resize(n + 1, 0);
    for(int i = 2; i <= n; i ++) {
        int p;
        cin >> p;
        adj[i].push_back(p);
        adj[p].push_back(i);
    }
    dfs1(1, 0);
    dfs2(1, 0, 0);
    cout << teams/2 << "\n";
}

signed main() {
    fast_cin();
    int test_cases;
    cin >> test_cases;
    for(int it = 1; it <= test_cases; it ++) {
        teams = 0;
        subtree.clear(); adj.clear();
        solve();
    }
    return 0;
}