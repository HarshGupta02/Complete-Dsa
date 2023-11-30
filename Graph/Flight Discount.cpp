#include<bits/stdc++.h>
using namespace std;
#define int long long int
static const int MOD = (int)1e9 + 7;
using vi = vector<int>;

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
    vector<vector<int>> dist(n, vector<int> (2, 1e18));
    dist[0][0] = 0; dist[0][1] = 1e18;
    priority_queue<vi, vector<vi>, greater<vi>> pq;
    pq.push({0, 0, 0});
    while(!pq.empty()) {
        int curr_dist = pq.top()[0], curr_node = pq.top()[1], used = pq.top()[2];
        pq.pop();
        if(dist[curr_node][used] < curr_dist) continue;
        for(auto neigh : adj[curr_node]) {
            int new_node = neigh.first, w = neigh.second;
            if(dist[curr_node][0] + w < dist[new_node][0]) {
                dist[new_node][0] = dist[curr_node][0] + w;
                pq.push({dist[new_node][0], new_node, 0});
            }
            if(dist[curr_node][0] + w/2 < dist[new_node][1]) {
                dist[new_node][1] = dist[curr_node][0] + w/2;
                pq.push({dist[new_node][1], new_node, 1});
            }
            if(dist[curr_node][1] + w < dist[new_node][1]) {
                dist[new_node][1] = dist[curr_node][1] + w;
                pq.push({dist[new_node][1], new_node, 1});
            }
        }
    }
    cout << min(dist[n - 1][0], dist[n - 1][1]) << "\n";
    return 0;
}