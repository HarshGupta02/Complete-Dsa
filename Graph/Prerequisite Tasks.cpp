class Solution {
public:

    bool has_cycle = false;
    
    void dfs(int src, int N , vector<bool> &visited , vector<bool> &visited_dfs,vector<vector<int>> &adj){
        visited[src] = true;
        visited_dfs[src] = true;
        for(auto neigh : adj[src]){
            if(!visited[neigh]) dfs(neigh , N , visited,visited_dfs,adj);
            else if(visited_dfs[neigh]){
                has_cycle = true;
            }else continue;
        }
        visited_dfs[src] = false;
    }

	bool isPossible(int N, vector<pair<int, int> >& prerequisites) {
	    vector<vector<int>> adj(N);
	    int p = prerequisites.size();
	    for(int i = 0 ; i < p; i ++){
	        int a = prerequisites[i].first;
	        int b = prerequisites[i].second;
	        adj[a].push_back(b);
	    }
	    vector<bool>visited(N,false) , visited_dfs(N,false);
	    for(int i = 0; i < N ; i ++){
	        if(!visited[i]) dfs(i , N , visited,visited_dfs,adj);
	    }
	    return !has_cycle;
	}
};