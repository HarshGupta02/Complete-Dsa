#include<bits/stdc++.h>
using namespace std;
#define int long long int
static const int MOD = (int)1e9 + 7;
using pi = pair<int, int>;
using vi = vector<int>;

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<vector<pi>> adj(n);
    map<pair<int, int>, int> edges;
    for(int i = 0; i < m; i ++) {
        int a, b;
        cin >> a >> b;
        a --; b --;
        if(edges.find({a, b}) != edges.end()) continue;
        adj[a].push_back({b, - 1});
    }

    priority_queue<vi, vector<vi>, greater<vi>> pq;
    vector<int> dist(n, 1e18), par(n);
    dist[0] = 0; par[0] = -1;
    pq.push({0, 0, -1});
    map<vi, int> cache;
    cache[{0, 0, -1}] = 1;

    while(!pq.empty()) {
        int curr_dist = pq.top()[0], curr_node = pq.top()[1];
        int curr_par = pq.top()[2];
        pq.pop();
        if(dist[curr_node] < curr_dist) continue;
        for(auto neigh : adj[curr_node]) {
            int new_node = neigh.first, w = neigh.second;
            if(curr_dist + w < dist[new_node]) {
                dist[new_node] = curr_dist + w;
                par[new_node] = curr_node;
                if(cache[{dist[new_node], new_node, par[new_node]}]) continue;
                cache[{dist[new_node], new_node, par[new_node]}] = 1;
                pq.push({dist[new_node], new_node, par[new_node]});
            }
        }
    }
    if(dist[n - 1] == 1e18) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    cout << (-1 * dist[n - 1]) + 1 << "\n";
    vector<int> ans;
    int curr = n - 1;
    while(curr != -1) {
        ans.push_back(curr);
        curr = par[curr];
    }
    reverse(ans.begin(), ans.end());
    for(auto it : ans) cout << it + 1 << " ";
    cout << "\n";
    return 0;
}