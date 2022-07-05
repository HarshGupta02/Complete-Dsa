class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    
    void dfs(int source , int V , vector<int> adj[] , vector<int> &ans , vector<bool> &visited){
        visited[source] = true;
        ans.push_back(source);
        for(auto neigh : adj[source]){
            if(!visited[neigh]) dfs(neigh , V , adj , ans , visited);
        }
    }
    
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<int>ans;
        vector<bool>visited(V , false);
        dfs(0 , V, adj,ans,visited);
        return ans;
    }
};