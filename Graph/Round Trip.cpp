#include<bits/stdc++.h>
using namespace std;
#define int long long int
static const int MOD = (int)1e9 + 7;

int n, m;
vector<vector<int>> adj;
vector<bool> seen, instack;
vector<int> ans;
bool possible = false;

void dfs(int src, int par, stack<int> &stk) {
    seen[src] = true;
    instack[src] = true;
    stk.push(src);
    for(auto neigh : adj[src]) {
        if(neigh == par) continue;
        if(instack[neigh] and !possible) {
            possible = true;
            while(!stk.empty() and stk.top() != neigh) {
                ans.push_back(stk.top());
                stk.pop();
            }
            ans.push_back(neigh);
            reverse(ans.begin(), ans.end());
            ans.push_back(neigh);
            continue;
        }
        if(seen[neigh]) continue;
        dfs(neigh, src, stk);
    }
    if(!stk.empty()) stk.pop();
    instack[src] = false;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    adj.resize(n); seen.resize(n, false); instack.resize(n, false);
    for(int i = 0; i < m; i ++) {
        int u, v;
        cin >> u >> v;
        u --; v --;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i = 0; i < n; i ++) {
        if(seen[i]) continue;
        stack<int> stk;
        dfs(i, -1, stk);
        if(possible) break;
    }
    if(!possible) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    cout << (int) ans.size() << "\n";
    for(auto it : ans) cout << it + 1 << " ";
    cout << "\n";
    return 0;
}