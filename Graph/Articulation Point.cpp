class Solution {
  public:
  
    void dfs(int src, int par, int &timer, vector<int> &in, vector<int> &low, vector<bool> &seen, vector<int> adj[], vector<int> &a) {
        seen[src] = true;
        in[src] = low[src] = timer;
        timer ++;
        int childs = 0;
        for(auto neigh : adj[src]) {
            if(neigh == par) continue;
            if(!seen[neigh]) {
                childs ++;
                dfs(neigh, src, timer, in, low, seen, adj, a);
                low[src] = min(low[src], low[neigh]);
                if(low[neigh] >= in[src] and par != -1) a[src] = 1;
            }else {
                low[src] = min(low[src], in[neigh]);
            }
        }
        if(childs > 1 and par == -1) a[src] = 1;
    }
  
    vector<int> articulationPoints(int V, vector<int>adj[]) {
        vector<bool> seen(V, false);
        vector<int> in(V, 0), low(V, 0);
        vector<int> a(V, 0);
        int timer = 1;
        for(int i = 0; i < V; i ++) {
            if(seen[i]) continue;
            dfs(i, -1, timer, in, low, seen, adj, a);
        }
        vector<int> ans;
        for(int i = 0; i < V; i ++) {
            if(a[i]) ans.push_back(i);
        }
        if(ans.empty()) return {-1};
        return ans;
    }
};