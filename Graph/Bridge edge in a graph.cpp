/*

here we maintain an intimer of each node and keep incrementing it unless we have visited
all the neighbours of a node. after that we update the lowtime of the curr node with 
the low time of all the neighbours except the parent and then if lowtime of parent < low
time of curr node then it is a bridge because we cannot the curr node can reach a minimum
of the lowtime but it is still greater than the parent's lowtime so never possible to reach
the parent after removing the edge.

if lowtime of curr node <= lowtime of parent then we can remove the edge and still reach the
parent because the curr node is connected to someone which is visited before the parent 
inspite of removing the edge.


*/


class Solution
{
	public:
	vector<int>Intime;
	int tm = 0;
	vector<int>Lowtime;
	vector<bool>visited;
	bool possible = false;
    //Function to find if the given edge is a bridge in graph.
    
    void dfs(int src,int par,vector<int> adj[],int c,int d){
        visited[src] = true; tm ++;
        Intime[src] = tm; Lowtime[src] = Intime[src];
        for(auto neigh : adj[src]){
            if(!visited[neigh]) dfs(neigh,src,adj,c,d);
        }
        int mini = Lowtime[src];
        for(auto neigh : adj[src]){
            if(neigh != par) mini = min(mini , Lowtime[neigh]);
        }
        Lowtime[src] = mini;
        if(par != -1 and Lowtime[par] < Lowtime[src]){
            if((par == c and src == d) or (par == d and src == c))
                possible = true;
        }
    }
    
    int isBridge(int V, vector<int> adj[], int c, int d) 
    {
        Intime.resize(V); Lowtime.resize(V); visited.resize(V,false);
        for(int i = 0; i < V; i ++){
            if(!visited[i]) dfs(i,-1,adj,c,d);
        }
        return possible;
    }
};