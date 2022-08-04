class DSU{
    public:
    
    int get_parent(int a, vector<int> &parent){
        return parent[a] = (parent[a] == a ? a : get_parent(parent[a], parent));
    }
    
    void Merge(int a, int b, vector<int> &parent, vector<int> &rank){
        a = get_parent(a, parent);
        b = get_parent(b, parent);
        if(rank[a] > rank[b]) parent[b] = a;
        else if(rank[a] < rank[b]) parent[a] = b;
        else{
            rank[a] ++; parent[b] = a;
        }
    }
    
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int>parent(n), rank(n, 0);
        for(int i = 0; i < n ; i ++) parent[i] = i;
        DSU dsu;
        for(int i = 0; i < n ; i ++){
            for(int j = 0; j < n ; j ++){
                if(isConnected[i][j] == 0) continue;
                if(dsu.get_parent(i, parent) != dsu.get_parent(j, parent)) dsu.Merge(i, j, parent, rank);
            }
        }
        set<int>s;
        for(auto it : parent) s.insert(dsu.get_parent(it, parent));
        return (int)s.size();
    }
};