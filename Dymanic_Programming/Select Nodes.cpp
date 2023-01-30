/*
since we have to select min number of nodes so we will select some subset of nodes in the tree.
so we can either choose a node or not choose a node.
if we not choose a node then we have to choose all the childs of the current node.
if we choose a node so for each child, we can either take it or not.

so dp[i][0] = min nodes to light up subtree of i with i not lit.
and dp[i][1] = min nodes to light up subtree of i with i beign lit.

*/

class Solution{
  public:
    vector<vector<int>> adj;
    vector<vector<int>> dp;
    
    void dfs(int src, int par){
        dp[src][1] = 1;
        for(auto neigh : adj[src]){
            if(neigh == par) continue;
            dfs(neigh, src);
            dp[src][0] += dp[neigh][1];
            dp[src][1] += min(dp[neigh][0], dp[neigh][1]);
        }
    }
    
    int countVertex(int n, vector<vector<int>>edges){
        adj.resize(n);
        dp.resize(n, vector<int> (2, 0));
        for(int i = 0; i < edges.size(); i ++){
            int u = edges[i][0], v = edges[i][1];
            u --; v --;
            adj[u].push_back(v); adj[v].push_back(u);
        }
        dfs(0, -1);
        return min(dp[0][0], dp[0][1]);
    }
};