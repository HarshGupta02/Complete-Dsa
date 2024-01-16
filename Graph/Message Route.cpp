#include<bits/stdc++.h>
using namespace std;
#define int long long int
static const int MOD = (int)1e9 + 7;

int n, m;
vector<vector<int>> adj;
vector<bool> seen;
vector<int> parent;

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    adj.resize(n); seen.resize(n); parent.resize(n, -1);
    for(int i = 0; i < m; i ++) {
        int u, v;
        cin >> u >> v;
        u --; v --;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    queue<int> q;
    q.push(0);
    seen[0] = true;
    while(!q.empty()) {
        int sz = q.size();
        while(sz --) {
            int curr_node = q.front(); q.pop();
            for(auto neigh : adj[curr_node]) {
                if(seen[neigh]) continue;
                seen[neigh] = true;
                q.push(neigh);
                parent[neigh] = curr_node;
            }
        }
    }
    if(parent[n - 1] == -1) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    int curr = n - 1;
    vector<int> path;
    while(curr != 0) {
        path.push_back(curr);
        curr = parent[curr];
    }
    path.push_back(0);
    reverse(path.begin(), path.end());
    cout << (int) path.size() << "\n";
    for(auto it : path) cout << it + 1 << " ";
    cout << "\n";
    return 0;
}