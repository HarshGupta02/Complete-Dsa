class Solution {
public:

    bool possible = true;
    
    // color = 0 -> not colored
    // color = 1 -> red colored
    // color = -1 -> blue colored.
    
    void dfs(int src,int par,int V,vector<bool> &visited, vector<int> adj[],vector<int> &color){
        visited[src] = true;
        if(par == -1) color[src] = 1;
        else if(color[par] == 1) color[src] = -1;
        else color[src] = 1;
        for(auto neigh : adj[src]){
            if(color[neigh] == color[src]){
                possible = false; return;
            }
        }
        for(auto neigh : adj[src]){
            if(!visited[neigh]) dfs(neigh,src,V,visited,adj,color);
        }
    }
    
	bool isBipartite(int V, vector<int>adj[]){
	    vector<bool>visited(V,false);
	    vector<int>color(V);
	    for(int i = 0; i < V; i ++){
	        if(!visited[i]) dfs(i,-1,V,visited,adj,color);
	    }
	    return possible;
	}

};