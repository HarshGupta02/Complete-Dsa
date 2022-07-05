class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    
    bool has_cycle = false;
    
    void dfs(int src , int par , vector<bool>&visited,int V ,vector<int> adj[]){
        visited[src] = true;
        for(auto neigh : adj[src]){
            if(!visited[neigh]) dfs(neigh , src , visited,V,adj);
            else if(neigh != par) has_cycle |= true;
            else continue;
        }
    }
    
    bool isCycle(int V, vector<int> adj[]) {
        vector<bool>visited(V,false);
        for(int i = 0; i < V ; i ++){
            if(!visited[i]) dfs(i,-1,visited,V,adj);
        }
        return has_cycle;
    }
};