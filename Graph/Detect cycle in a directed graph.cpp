class Solution {
  public:
    // Function to detect cycle in a directed graph.
    
    bool has_cycle = false;
    
    void dfs(int src , int V ,vector<int> adj[] , vector<bool> &visited , vector<bool> &visited_dfs){
        visited[src] = true;
        visited_dfs[src] = true;
        for(auto neigh : adj[src]){
            if(!visited[neigh]) dfs(neigh,V,adj,visited,visited_dfs);
            else if(visited_dfs[neigh]){
                has_cycle = true;
            }else continue;
        }
        visited_dfs[src] = false;
    } 
    
    bool isCyclic(int V, vector<int> adj[]) {
        vector<bool>visited(V,false) , visited_dfs(V,false);
        for(int i = 0; i < V ; i ++){
            if(!visited[i]) dfs(i,V,adj,visited,visited_dfs);
        }
        return has_cycle;
    }
};