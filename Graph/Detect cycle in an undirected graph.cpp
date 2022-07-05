// METHOD 1: USING DFS

class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    
    bool has_cycle = false;
    
    void dfs(int src , int par , vector<bool>&visited,int V ,vector<int> adj[]){
        visited[src] = true;
        for(auto neigh : adj[src]){
            if(!visited[neigh]) dfs(neigh , src , visited,V,adj);
            else if(neigh != par) has_cycle |= true;
            else continue;
        }
    }
    
    bool isCycle(int V, vector<int> adj[]) {
        vector<bool>visited(V,false);
        for(int i = 0; i < V ; i ++){
            if(!visited[i]) dfs(i,-1,visited,V,adj);
        }
        return has_cycle;
    }
};


/// METHOD 2 : USING DSU(DISJOINT SET UNION).

class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    
    int get_parent(int a,vector<int> &parent){
        return parent[a] = (parent[a] == a) ? a : get_parent(parent[a],parent);
    }
    
    void Merge_Child(int a, int b,vector<int> &parent,vector<int> &rank){
        int x = get_parent(a,parent);
        int y = get_parent(b,parent);
        if(rank[x] == rank[y]){
            rank[x] ++;
        }
        if(rank[x] > rank[y]){
            parent[b] = a;
        }else parent[a] = b;
    }
    
    bool isCycle(int V, vector<int> adj[]) {
        vector<int>parent(V) , rank(V,0);
        for(int i = 0 ;i < V; i ++) parent[i] = i;
        bool has_cycle = false;
        vector<bool>visited(V,false);
        for(int i = 0; i < V ; i++){
            visited[i] = true;
            for(auto neigh : adj[i]){
                if(visited[neigh] == true) continue;
                int p1 = get_parent(i,parent);
                int p2 = get_parent(neigh,parent);
                if(p1 == p2){
                    has_cycle = true;
                }else{
                    Merge_Child(i,neigh,parent,rank);
                }
            }
        }
        return has_cycle;
    }
};