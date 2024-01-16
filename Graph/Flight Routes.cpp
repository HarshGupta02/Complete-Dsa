#include<bits/stdc++.h>
using namespace std;
#define int long long int
static const int MOD = (int)1e9 + 7;
using pi = pair<int, int>;
int n, m, k;
vector<vector<pi>> adj;

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m >> k;
    adj.resize(n);
    for(int i = 0; i < m; i ++) {
        int u, v, w;
        cin >> u >> v >> w;
        u --; v --;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    vector<int> dist(n, 1e18);
    dist[0] = 0;
    priority_queue<int> k_shortest;
    priority_queue<pi, vector<pi>, greater<pi>> pq;
    pq.push({0, 0});
    while(!pq.empty()) {
        int curr_dist = pq.top().first, curr_node = pq.top().second;
        pq.pop();
        for(auto neigh : adj[curr_node]) {
            int new_node = neigh.first, w = neigh.second;
            if(new_node == n - 1) {
                k_shortest.push(dist[curr_node] + w);
                if(k_shortest.size() > k) k_shortest.pop();
            }
            if(dist[curr_node] + w < dist[new_node]) {
                dist[new_node] = dist[curr_node] + w;
                pq.push({dist[new_node], new_node});
            }
        }
    }
    vector<int> ans;
    while(!k_shortest.empty()) {
        ans.push_back(k_shortest.top());
        k_shortest.pop();
    }
    reverse(ans.begin(), ans.end());
    for(auto it : ans) cout << it << " ";
    cout << "\n";
    return 0;
}