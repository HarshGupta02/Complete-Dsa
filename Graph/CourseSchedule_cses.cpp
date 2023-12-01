#include<bits/stdc++.h>
using namespace std;
#define int long long int
static const int MOD = (int)1e9 + 7;

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    vector<int> degree(n, 0);
    for(int i = 0; i < m; i ++) {
        int a, b;
        cin >> a >> b;
        a --; b --;
        adj[a].push_back(b);
        degree[b] ++;
    }
    queue<int> q;
    vector<int> ans;
    for(int i = 0; i < n; i ++) {
        if(degree[i] == 0) q.push(i);
    }
    while(!q.empty()) {
        int sz = q.size();
        while(sz --) {
            int curr = q.front(); q.pop();
            ans.push_back(curr);
            for(auto neigh : adj[curr]) {
                degree[neigh] --;
                if(degree[neigh] == 0) q.push(neigh);
            }
        }
    }
    for(int i = 0; i < n; i ++) {
        if(degree[i] > 0) {
            cout << "IMPOSSIBLE\n";
            return 0;
        }
    }
    for(auto it : ans) cout << it + 1 << " ";
    cout << "\n";
    return 0;
}