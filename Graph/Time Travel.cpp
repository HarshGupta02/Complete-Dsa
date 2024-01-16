#include <bits/stdc++.h>
using namespace std;
  
#define int long long
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
static const int MOD = (int)1e9+7;
using pi = pair<int, int>;

void solve(){
    int n, t;
    cin >> n >> t;
    vector<vector<pi>> adj(n + 1);
    for(int i = 1; i <= t; i ++) {
        int m;
        cin >> m;
        while(m --) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back({v, i});
            adj[v].push_back({u, i});
        }
    }
    int k;
    cin >> k;
    vector<int> a(k + 1);
    for(int i = 1; i <= k; i ++) cin >> a[i];
    vector<int> dist(n + 1, 1e18);
    priority_queue<pi, vector<pi>, greater<pi>> pq; // {curr_moment, node}
    pq.push({1, 1}); dist[1] = 1;
    cout << "\n";
    while(!pq.empty()) {
        int curr_moment = pq.top().first, curr_node = pq.top().second;
        pq.pop();
        if(curr_moment > n) continue;
        cout << curr_moment << " " << curr_node << endl;
        // did not choose any path
        // choosing the path with path no same as
        pq.push({curr_moment + 1, curr_node});
        // if(curr_moment + 1 < dist[curr_node]) {
        //     dist[curr_node] = 1 + curr_moment;
        //     pq.push({curr_moment + 1, curr_node});
        // }
        for(auto neigh : adj[curr_node]) {
            int new_node = neigh.first, moment_path_no = neigh.second;
            if(a[curr_moment] != moment_path_no) continue;
            if(dist[curr_node] + 1 < dist[new_node]) {
                dist[new_node] = moment_path_no + 1;
                pq.push({moment_path_no + 1, new_node});
            }
        }
    }
    if(dist[n] == 1e18) dist[n] = -1;
    cout << dist[n] << "\n";
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