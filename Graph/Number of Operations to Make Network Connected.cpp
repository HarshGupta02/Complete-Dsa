/// METHOD 1:  TIME = O(V logV)

class DSU {
    public:
    int get_parent(int a,vector<int> &parent){
        return parent[a] = (parent[a] == a) ? a : get_parent(parent[a],parent);
    }
    
    void Merge_Child(int a,int b,vector<int> &parent, vector<int> &rank){
        a = get_parent(a,parent);
        b = get_parent(b,parent);
        if(rank[a] > rank[b]) parent[b] = a;
        else if(rank[a] < rank[b]) parent[a] = b;
        else{
            rank[a] ++; parent[b] = a;
        }
    }
    
};

class Solution {
public:
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<int>parent,rank;
        parent.resize(n); rank.resize(n,0);
        for(int i = 0; i < n ; i ++) parent[i] = i;
        DSU dsu;
        int needed = 0 , left = 0;
        for(int i = 0; i < connections.size() ; i ++){
            int u = connections[i][0] , v = connections[i][1];
            if(dsu.get_parent(u,parent) != dsu.get_parent(v,parent)){
                dsu.Merge_Child(u,v,parent,rank);
            }else{
                left ++;
            }
        }
        set<int>s;
        
        for(int i = 0; i < n ; i ++){
            s.insert(dsu.get_parent(i,parent));
        }
        needed = s.size() - 1;
        cout << needed << " " << left << endl;
        if(needed > left) return -1;
        return needed;
    }
};

/// METHOD 2: (EFFICIENT)

class Solution {
public:
    
    void dfs(int src,vector<bool> &visited,vector<vector<int>> &adj){
        visited[src] = true;
        for(auto neigh : adj[src]){
            if(!visited[neigh]) dfs(neigh , visited,adj);
        }
    }
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        int needed = n - 1;
        int m = connections.size();
        if(needed > m) return -1;
        vector<vector<int>>adj(n);
        for(int i = 0; i < m ; i ++){
            int u = connections[i][0] , v = connections[i][1];
            adj[u].push_back(v); adj[v].push_back(u);
        }
        int op = 0;
        vector<bool>visited(n,false);
        for(int i = 0; i < n ; i ++){
            if(!visited[i]){
                dfs(i,visited,adj); op ++;
            }
        }
        return op - 1;
    }
};