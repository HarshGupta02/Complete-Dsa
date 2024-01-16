#include <bits/stdc++.h>
using namespace std;
  
#define int long long
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
static const int MOD = (int)1e9+7;

int n, a, b;
vector<vector<int>> adj;
vector<int> degree;

void solve(){
    adj.clear(); degree.clear();
    cin >> n >> a >> b;
    adj.resize(n + 1); degree.resize(n + 1, 0);
    for(int i = 1; i <= n; i ++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        degree[u] ++; degree[v] ++;
    }
    int two_deg = 0, three_deg = 0;
    for(int i = 1; i <= n; i ++) {
        if(degree[i] == 2) two_deg ++;
        else if(degree[i] == 3) three_deg ++;
    }
    if(two_deg == n) {
        // whole cycle
    }else if(three_deg == 1) {
        // one end
        
    }else {
        // two end
    }
}

signed main() {
    fast_cin();
    int test_cases;
    cin >> test_cases;
    for(int it = 1; it <= test_cases; it ++) {
        solve();
    }
    return 0;
}