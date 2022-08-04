class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto curr : times){
            int u = curr[0], v = curr[1], w = curr[2];
            u --; v --;
            adj[u].push_back({v,w});
        }
        vector<int>dist(n, INT_MAX);
        k --;
        int src = k;
        dist[src] = 0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq; /// {dist, node}
        pq.push({0,src});
        while(!pq.empty()){
            auto curr = pq.top();
            pq.pop();
            int curr_node = curr.second;
            int curr_dist = curr.first;
            for(auto neigh : adj[curr_node]){
                int child_node = neigh.first;
                int child_dist = neigh.second;
                if(curr_dist + child_dist < dist[child_node]){
                    dist[child_node] = curr_dist + child_dist;
                    pq.push({dist[child_node], child_node});
                }
            }
        }
        int nax = -1;
        for(auto it : dist) nax = max(nax, it);
        return (nax == INT_MAX ? -1 : nax);
    }
};