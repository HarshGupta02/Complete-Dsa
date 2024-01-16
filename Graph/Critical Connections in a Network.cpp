class Solution {
public:
    vector<vector<int>> adj;
    vector<bool> seen;
    vector<int> in, low;
    vector<vector<int>> bridges;
    int timer = 1;
    
    void dfs(int src, int par) {
        seen[src] = true;
        in[src] = low[src] = timer;
        timer ++;
        for(auto neigh : adj[src]) {
            if(neigh == par) continue;
            if(seen[neigh]) {
                low[src] = min(low[src], low[neigh]);
            }else {
                dfs(neigh, src);
                low[src] = min(low[src], low[neigh]);
                if(in[src] < low[neigh]) bridges.push_back({src, neigh});
            }
        }
    }
    
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        adj.resize(n); seen.resize(n, false); in.resize(n, 0); low.resize(n, 0);
        for(auto it : connections) {
            int u = it[0], v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dfs(0, -1);
        return bridges;
    }
};