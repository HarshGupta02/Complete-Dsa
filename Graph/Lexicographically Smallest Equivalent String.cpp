/*
here, we group equivalent characters in the same group using dsu find and merge and 
while merging, we always keep the minimum character of the group at the absoulte
parent.

*/

class DSU {
public:
    
    char int_to_char(int num){
        num += 97;
        char c = static_cast<char>(num);
        return c;
    }
    
    int get_parent(int a, vector<int> &parent){
        return (a == parent[a] ? a : get_parent(parent[a], parent));
    }
    
    void mergee_child(int a, int b, vector<int> &parent){
        a = get_parent(a, parent);
        b = get_parent(b, parent);
        parent[max(a, b)] = min(a, b);
    }
};

class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        vector<int> parent(26);
        for(int i = 0; i < 26; i ++) parent[i] = i;
        DSU dsu;
        int n = s1.size();
        for(int i = 0; i < n; i ++){
            if(dsu.get_parent(s1[i] - 'a', parent) != dsu.get_parent(s2[i] - 'a', parent)){
                dsu.mergee_child(s1[i] - 'a', s2[i] - 'a', parent);
            }
        }
        int m = baseStr.size();
        for(int i = 0; i < m; i ++){
            int root = dsu.get_parent(baseStr[i] - 'a', parent);
            baseStr[i] = dsu.int_to_char(root);
        }
        return baseStr;
    }
};