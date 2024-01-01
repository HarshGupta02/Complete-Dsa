#include <bits/stdc++.h>
using namespace std;
  
#define int long long
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
static const int MOD = (int)1e9+7;

int n;
vector<int> depth, ans;
vector<vector<int>> adj;

void dfs_depth(int src, int par) {
    int max_depth = -1;
    for(auto neigh : adj[src]) {
        if(neigh == par) continue;
        dfs_depth(neigh, src);
        max_depth = max(max_depth, depth[neigh]);
    }
    depth[src] = 1 + max_depth;
}

void dfs_dist(int src, int par, int partial_ans) {
    vector<int> prefix, suffix;
    for(auto neigh : adj[src]) {
        if(neigh == par) continue;
        prefix.push_back(depth[neigh]);
        suffix.push_back(depth[neigh]);
    }
    for(int i = 1; i < (int)prefix.size(); i ++)
        prefix[i] = max(prefix[i], prefix[i - 1]);
    for(int i = (int)suffix.size() - 2; i >= 0; i --)
        suffix[i] = max(suffix[i], suffix[i + 1]);
    ans[src] = 1 + max(partial_ans, (prefix.empty() ? -1 : prefix.back()));
    int child_no = 0;
    for(auto neigh : adj[src]) {
        if(neigh == par) continue;
        int ans1 = (child_no == 0) ? INT_MIN : prefix[child_no - 1];
        int ans2 = (child_no == (int)suffix.size() - 1) ? INT_MIN : suffix[child_no + 1];
        int new_partial_ans = 1 + max(max(ans1, ans2), partial_ans);
        dfs_dist(neigh, src, new_partial_ans);
        child_no ++;
    }
}

void solve(){
    depth.clear(); adj.clear(); ans.clear();
    cin >> n;
    depth.resize(n + 1, 0); adj.resize(n + 1);
    ans.resize(n + 1, 0);
    for(int i = 0; i < n - 1; i ++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs_depth(1, 0);
    dfs_dist(1, 0, -1);
    for(int i = 1; i <= n; i ++) cout << ans[i] << " ";
    cout << "\n";
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