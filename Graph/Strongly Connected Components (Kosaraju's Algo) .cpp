/*
IN A SCC , ONE CAN REACH ANY OTHER NODE IN THE COMPONENT FROM EACH NODE. SO EVEN IF WE
REVERSE THE DIRECTION OF EDGES , IT WILL STILL REMAIN AN SCC BUT WE CANNOT GO TO OTHER
COMPONENTS BY REVERSING SO EACH CALL GIVES US THE NUMBER OF SCC COMPONENTS.

1.FIND THE TOPO SORT (???).
2.REVERSE THE EDGES
3.DFS ON EACH ELEMENT OF STACK FROM TOP.

*/



class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
	
	stack<int>stk;
	vector<bool>visited;
	vector<vector<int>>g;
	
	void dfs1(int src,int V ,vector<int> adj[]){
	    visited[src] = true;
	    for(auto neigh : adj[src]){
	        if(!visited[neigh]) dfs1(neigh,V,adj);
	    }
	    stk.push(src);
	}
	
	void dfs2(int src,int V){
	    visited[src] = true;
	    for(auto neigh : g[src]){
	        if(!visited[neigh]) dfs2(neigh,V);
	    }
	}
	
    int kosaraju(int V, vector<int> adj[])
    {
        visited.resize(V,false);
        
        for(int i = 0 ;i < V; i ++){
            if(!visited[i]) dfs1(i,V,adj);
        }
        
        g.resize(V);
        for(int i = 0 ; i < V; i ++){
            visited[i] = false;
            for(auto neigh : adj[i]){
                g[neigh].push_back(i);
            }
        }
        int scc = 0;
        while(!stk.empty()){
            int x = stk.top();
            stk.pop();
            if(!visited[x]){
                dfs2(x,V);
                scc ++;
            }
        }
        return scc;
    }
};