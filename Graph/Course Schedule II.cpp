class Solution {
public:
    
    vector<vector<int>>adj;
    vector<bool>seen, instack;
    bool has_cycle = false;
    vector<int>in;
    
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
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        adj.resize(n);
        in.resize(n, 0);
        seen.resize(n, false); instack.resize(n, false);
        for(auto curr : prerequisites){
            int u = curr[0], v = curr[1];
            adj[v].push_back(u);
            in[u] ++;
        }
        for(int i = 0; i < n ; i ++){
            if(!seen[i]) dfs(i);
        }
        vector<int>ans;
        if(has_cycle) return ans;
        queue<int>q;
        for(int i = 0; i < n ; i ++) if(in[i] == 0) q.push(i);
        while(!q.empty()){
            int curr_node = q.front();
            ans.push_back(curr_node);
            q.pop();
            for(auto neigh : adj[curr_node]){
                in[neigh] --;
                if(in[neigh] == 0) q.push(neigh);
            }
        }
        return ans;
    }
};