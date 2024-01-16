#include <bits/stdc++.h>
using namespace std;
  
#define int long long
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
static const int MOD = (int)1e9+7;

class DSU{
    public:
    vector<int>parent, rank;
    
    DSU(int n){
        parent.resize(n); rank.resize(n, 0);
        for(int i = 0; i < n ; i ++) parent[i] = i;
    }
    
    int get_parent(int a){
        return parent[a] = (parent[a] == a ? a : get_parent(parent[a]));
    }
    
    void Merge(int a, int b){
        a = get_parent(a);
        b = get_parent(b);
        if(a == b) return;
        if(rank[a] > rank[b]) parent[b] = a;
        else if(rank[a] < rank[b]) parent[a] = b;
        else{
            rank[a] ++; 
            parent[b] = a;
        }
    }
};

void solve(){
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for(int i = 0; i < n; i ++) cin >> a[i];
    vector<vector<int>> edges;
    DSU dsu(n);
    for(int i = 1; i <= m; i ++) {
        int u, v;
        cin >> u >> v;
        u --; v --;
        edges.push_back({u, v});
        if(a[u] == a[v]) dsu.Merge(u, v);
    }
    unordered_map<int, vector<int>> adj;
    for(auto it : edges) {
        int u = dsu.get_parent(it[0]);
        int v = dsu.get_parent(it[1]);
        if(u == v) continue;
        if(a[u] < a[v]) adj[u].push_back(v);
        if(a[v] < a[u]) adj[v].push_back(u);
    }
    vector<int> dist(n, -1), seen(n, 0);
    int root_par = dsu.get_parent(0);
    dist[root_par] = 1; seen[root_par] = 1;
    queue<int> q;
    q.push(root_par);
    while(!q.empty()) {
        int sz = q.size();
        while(sz --) {
            int curr = q.front(); q.pop();
            for(auto neigh : adj[curr]) {
                dist[neigh] = max(dist[neigh], 1 + dist[curr]);
                if(!seen[neigh]) {
                    seen[neigh] = 1;
                    q.push(neigh);
                }
            }
        }
    }
    int final_par = dsu.get_parent(n - 1);
    if(dist[final_par] < 0) dist[final_par] = 0;
    cout << dist[final_par] << "\n";
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