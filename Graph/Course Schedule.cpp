class Solution {
public:
    
    vector<vector<int>>adj;
    bool has_cycle = false;
    vector<bool>seen, instack;
    
    void dfs(int src){
        seen[src] = true;
        instack[src] = true;
        for(auto neigh : adj[src]){
            if(!seen[neigh]) dfs(neigh);
            else if(instack[neigh]) has_cycle = true;
            else continue;
        }
        instack[src] = false;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        adj.resize(n);
        for(auto curr : prerequisites){
            int u = curr[0], v = curr[1];
            adj[v].push_back(u);
        }
        seen.resize(n, false);
        instack.resize(n, false);
        for(int i = 0; i < n ; i ++){
            if(!seen[i]) {
                dfs(i);
            }
        }
        return !has_cycle;  
    }
};