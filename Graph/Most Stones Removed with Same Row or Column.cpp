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

// SOLUTION 3: 

/*
SO HERE WE BASICALLY TREAT EACH ROW AND EACH COL AS A SEPARATE NODE AND JUST
CHANGE THE INDICES OF THE COLUMN NODES AND FOR EACH STONE, WE KEEP ON MERGING
THE CORRESPONDING ROW_NODE AND COL_NODES.

*/

class DSU{
public:
    vector<int> parent, rank;
    DSU(int n) {
        parent.resize(n); rank.resize(n, 1);
        for(int i = 0; i < n; i ++) parent[i] = i;
    }
    
    int get_parent(int a) {
        return (parent[a] == a ? a : get_parent(parent[a]));
    }
    
    void mergee(int a, int b) {
        a = get_parent(a);
        b = get_parent(b);
        if(rank[b] < rank[a]) parent[b] = a;
        else if(rank[a] < rank[b]) parent[a] = b;
        else {
            rank[a] ++;
            parent[b] = a;
        }
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        int max_row = 0, max_col = 0;
        for(int i = 0; i < n; i ++) {
            max_row = max(max_row, stones[i][0]);
            max_col = max(max_col, stones[i][1]);
        }
        DSU dsu(max_row + max_col + 2);
        unordered_map<int, int> mp;
        for(auto it : stones) {
            int node_row = it[0], node_col = max_row + 1 + it[1];
            mp[node_row] = 1; mp[node_col] = 1;
            if(dsu.get_parent(node_row) != dsu.get_parent(node_col))
                dsu.mergee(node_row, node_col);
        }
        set<int> st;
        for(auto it : mp) {
            st.insert(dsu.get_parent(it.first));
        }
        return n - (int)st.size();
    }
};