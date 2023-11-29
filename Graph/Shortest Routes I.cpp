#include<bits/stdc++.h>
using namespace std;
#define int long long int
static const int MOD = (int)1e9 + 7;
using pi = pair<int, int>;

int n, m;
vector<vector<pair<int, int>>> adj;

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    adj.resize(n);
    for(int i = 0; i < m; i ++) {
        int a, b, c;
        cin >> a >> b >> c;
        a --; b --;
        adj[a].push_back({b, c});
    }
    vector<int> dist(n, 1e18);
    priority_queue<pi, vector<pi>, greater<pi>> pq;
    pq.push({0, 0});
    dist[0] = 0;
    while(!pq.empty()) {
        int curr_dist = pq.top().first, curr_node = pq.top().second;
        pq.pop();
        if(dist[curr_node] < curr_dist) continue;
        for(auto neigh : adj[curr_node]) {
            int new_node = neigh.first, w = neigh.second;
            if(curr_dist + w < dist[new_node]) {
                dist[new_node] = curr_dist + w;
                pq.push({dist[new_node], new_node});
            }
        }
    }
    for(auto it : dist) cout << it << " ";
    return 0;
}