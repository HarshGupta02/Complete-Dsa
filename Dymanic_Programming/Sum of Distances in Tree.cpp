/*
dp[par] = sum of dp[childs] + number of nodes of parent.

TIME = O(N), SPACE = O(N)

*/

class Solution {
public:
    
    vector<vector<int>> adj;
    vector<int> below;
    vector<int> dp;
    vector<bool> seen;
    vector<int> ans;
    
    void precompute(int src, int n){
        seen[src] = true;
        for(auto neigh : adj[src]){
            if(seen[neigh]) continue;
            precompute(neigh, n);
            below[src] += below[neigh];
            dp[src] += dp[neigh] + below[neigh];
        }
        below[src] ++;
    }
    
    void f(int src, int par, int par_ans, int n){
        ans[src] = dp[src] + par_ans + n - below[src];
        for(auto neigh : adj[src]){
            if(neigh == par) continue;
            f(neigh, src, ans[src] - (dp[neigh] + below[neigh]),n);
        }
    }
    
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        int m = edges.size();
        adj.resize(n);
        below.resize(n, 0); // number of nodes below the ith node excluding i
        dp.resize(n, 0); // sum of distances below the ith node.
        seen.resize(n, false);
        ans.resize(n, 0);
        for(int i = 0; i < m; i ++){
            int u = edges[i][0], v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // 0th node will always be present so let's root at 0
        precompute(0, n);
        f(0, 0, 0, n);
        return ans;
    }
};
    
