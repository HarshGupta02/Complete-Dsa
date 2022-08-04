class DSU{
    public:
    
    vector<int>parent, rank;
    
    DSU(int n){
        parent.resize(n); rank.resize(n, 0);
        for(int i = 0; i < n ; i ++) parent[i] = i;
    }
    
    int get_parent(int a){
        return parent[a] = (parent[a] == a ? a : get_parent(parent[a]));
    }
    
    void Merge(int a, int b){
        a = get_parent(a);
        b = get_parent(b);
        if(rank[a] > rank[b]) parent[b] = a;
        else if(rank[a] < rank[b]) parent[a] = b;
        else{
            rank[a] ++; parent[b] = a;
        }
    }
    
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int>ans;
        DSU dsu(n);
        for(int i = 0 ; i < n ; i ++){
            int u = edges[i][0], v = edges[i][1];
            u --; v --;
            if(dsu.get_parent(u) == dsu.get_parent(v)){
                ans.push_back(u + 1); ans.push_back(v + 1);
            }
            else dsu.Merge(u, v);
        }
        return ans;
    }
};