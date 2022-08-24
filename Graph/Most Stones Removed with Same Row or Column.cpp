// TIME = O(N * N)

class Solution {
public:
    
    vector<vector<int>>adj;
    vector<bool>seen;
    
    void dfs(int src){
        seen[src] = true;
        for(auto neigh : adj[src]){
            if(!seen[neigh]) dfs(neigh);
        }
    }
    
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        adj.resize(n); seen.resize(n, false);
        int ans = 0;
        for(int i = 0; i < n ; i ++){
            for(int j = i + 1; j < n; j ++){
                int x_i = stones[i][0], y_i = stones[i][1];
                int x_j = stones[j][0], y_j = stones[j][1];
                if(x_i == x_j or y_i == y_j){
                    adj[i].push_back(j); adj[j].push_back(i);
                }
            }
        }
        for(int i = 0; i < n ; i ++){
            if(seen[i]) continue;
            ans ++; dfs(i);
        }
        return n - ans;
    }
};

// TIME = O(N * LOGN)

/*
here we try to merge the row and columns of each stone and to differentiate btw rows
and columns we add 10001 to col so that row and col can never become same.

in the end we just find the abs parent of each x coordinate of stones and the number
of unique values gives the number of components or the number of stones that cannot
be deleted.

*/


class DSU{
public:
    
    int get_parent(int a, vector<int> &parent){
        return parent[a] = (parent[a] == a) ? a : get_parent(parent[a], parent);
    }
    
    void merge_child(int a, int b, vector<int> &parent, vector<int> &rank){
        a = get_parent(a, parent); 
        b = get_parent(b, parent);
        if(rank[a] < rank[b]) parent[a] = b;
        else if(rank[a] > rank[b]) parent[b] = a;
        else{
            rank[a] ++; parent[b] = a;
        }
    }
    
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        const int MAXN = 2e5 + 5;
        int n = stones.size();
        vector<int>parent(MAXN), rank(MAXN, 0);
        for(int i = 0; i < MAXN; i ++) parent[i] = i;
        DSU dsu;
        int ans = 0;
        for(int i = 0; i < n ; i ++){
            int x = stones[i][0], y = 10001 + stones[i][1];
            dsu.merge_child(x, y, parent, rank);
        }
        set<int>s;
        for(auto it : stones){
            s.insert(dsu.get_parent(it[0], parent));
        }
        return n - s.size();
    }
};