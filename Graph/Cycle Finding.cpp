#include<bits/stdc++.h>
using namespace std;
#define int long long int
static const int MOD = (int)1e9 + 7;
using pi = pair<int, int>;

int n, m;
vector<vector<pair<int, int>>> adj;
vector<int> dist1, dist2;
vector<vector<int>> edges;
vector<bool> seen, instack;
bool cycle = false;
bool found = false;
vector<int> ans;

void dfs(int src, int sum, stack<int> &stk) {
    seen[src] = true;
    instack[src] = true;
    stk.push(src);
    for(auto neigh : adj[src]) {
        int new_node = neigh.first, w = neigh.second;
        int new_sum = sum + w;
        if(instack[new_node] and new_sum < 0 and !found) {
            found = true;
            while(!stk.empty() and stk.top() != new_node) {
                ans.push_back(stk.top());
                stk.pop();
            }
            ans.push_back(new_node);
            reverse(ans.begin(), ans.end());
            ans.push_back(new_node);
        }
        if(seen[new_node]) continue;
        dfs(new_node, new_sum, stk);
    }
    if(!stk.empty()) stk.pop();
    instack[src] = false;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    dist1.resize(n, 1e18); dist2.resize(n, 1e18);
    seen.resize(n, false); adj.resize(n);
    instack.resize(n, false);
    for(int i = 0; i < m; i ++) {
        int a, b, c;
        cin >> a >> b >> c;
        a --; b --;
        edges.push_back({a, b, c});
        adj[a].push_back({b, c});
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
            cycle = true;
            stack<int> stk;
            dfs(i, 0, stk);
            if(found) break;
        }    
    }
    if(!cycle) {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    for(auto it : ans) cout << it + 1 << " ";
    return 0;
}