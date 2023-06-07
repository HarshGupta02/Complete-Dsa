class Solution {
public:
    using ll = long long int;
    static const ll MOD = 1e9 + 7;
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<ll, ll>>> adj(n);
        for(int i = 0; i < roads.size(); i ++) {
            ll u = roads[i][0], v = roads[i][1], w = roads[i][2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
        pq.push({0, 0});
        vector<ll> dist(n, 1e18);
        vector<ll> dp(n, 0);
        dist[0] = 0; dp[0] = 1;
        while(!pq.empty()) {
            ll curr_dist = pq.top().first, curr_node = pq.top().second; pq.pop();
            for(auto neigh : adj[curr_node]) {
                ll new_node = neigh.first, new_dist = neigh.second;
                if((curr_dist + new_dist) < dist[new_node]) {
                    dist[new_node] = curr_dist + new_dist;
                    pq.push({dist[new_node], new_node});   
                    dp[new_node] = dp[curr_node];
                }else if((curr_dist + new_dist) == dist[new_node]){
                    dp[new_node] = (dp[new_node] + dp[curr_node]) % MOD;
                }
            }
        }
        return dp[n - 1] % MOD;
    }
};