class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    
    vector<int> bfs(int source , int V , vector<int> adj[]){
        vector<bool>visited(V , false);
        vector<int>res;
        queue<int>q;
        q.push(source);
        visited[0] = true;
        while(!q.empty()){
            int x = q.front();
            res.push_back(x);
            q.pop();
            for(auto it : adj[x]){
                if(!visited[it]){
                    visited[it] = true;
                    q.push(it);
                }
            }
        }
        return res;
    }
    
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        vector<int>ans = bfs(0,V,adj);
        return ans;
    }
};