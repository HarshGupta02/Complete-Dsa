class Solution {
public:
    vector<vector<int>>ans;
    vector<vector<int>>adj;
    
    void f(int src, vector<int>&temp, int n){
        if(src == n - 1){
            ans.push_back(temp);
            return;
        }
        for(auto neigh : adj[src]){
            temp.push_back(neigh);
            f(neigh, temp, n);
            temp.pop_back();
        }
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        adj.resize(n);
        for(int i = 0; i < n ; i ++){
            for(int j = 0; j < graph[i].size(); j ++){
                int u = i, v = graph[i][j];
                adj[u].push_back(v);
            }
        }
        vector<int>temp; temp.push_back(0);
        f(0,temp,n);
        return ans;
    }
};