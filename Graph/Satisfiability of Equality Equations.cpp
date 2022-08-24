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
    bool equationsPossible(vector<string>& equations) {
        int n = equations.size();
        vector<int>parent(26), rank(26, 0);
        for(int i = 0; i < 26; i ++) parent[i] = i;
        DSU dsu;
        for(int i = 0; i < n ; i ++){
            string curr = equations[i];
            int ch1 = curr[0] - 'a', ch2 = curr[3] - 'a';
            if(curr[1] == '!') continue;
            if(dsu.get_parent(ch1, parent) != dsu.get_parent(ch2, parent))
                dsu.merge_child(ch1, ch2, parent, rank);
        }
        for(int i = 0; i < n ; i ++){
            string curr = equations[i];
            if(curr[1] == '=') continue;
            int ch1 = curr[0] - 'a', ch2 = curr[3] - 'a';
            if(dsu.get_parent(ch1, parent) == dsu.get_parent(ch2, parent)) return false;
        }
        return true;
    }
};

/*
b == a, a == b, c == a, b != d, c == d

a == b, b == c, a != c 


*/