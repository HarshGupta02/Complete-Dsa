class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	
	void dfs(int src , int V,stack<int> &stk , vector<bool> &visited, vector<int> adj[]){
	    visited[src] = true;
	    for(auto neigh : adj[src]){
	        if(!visited[neigh]) dfs(neigh , V , stk , visited , adj);
	    }
	    stk.push(src);
	}
	
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    stack<int>stk;
	    vector<int>ans;
	    vector<bool>visited(V,false);
	    for(int i = 0; i < V; i ++){
	        if(!visited[i]) dfs(i , V, stk , visited, adj);
	    }
	    while(!stk.empty()){
	        int x = stk.top();
	        ans.push_back(x);
	        stk.pop();
	    }
	    return ans;
	}
};