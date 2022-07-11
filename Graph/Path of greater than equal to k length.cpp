class Solution {
public:

    void dfs(int src,int k,vector<vector<pair<int,int>>> adj,vector<bool> &visited,bool &possible,int &curr){
        visited[src] = true;
        for(auto neigh : adj[src]){
            if(!visited[neigh.first]){
                curr += neigh.second;
                dfs(neigh.first,k,adj,visited,possible,curr);
                curr -= neigh.second;
            }
        }
        if(curr >= k){
            possible = true; return;
        }
        visited[src] = false;
    }

    bool pathMoreThanK(int V, int E, int k, int *a) 
    {
        vector<vector<pair<int,int>>>adj(V);
        for(int i = 0 ; i < 3 * E; i += 3){
            adj[a[i]].push_back({a[i + 1],a[i + 2]});
            adj[a[i + 1]].push_back({a[i],a[i + 2]});
        }
        vector<bool>visited(V,false);
        bool possible = false;
        int curr = 0;
        dfs(0,k,adj,visited,possible,curr);
        return possible;
    } 
};