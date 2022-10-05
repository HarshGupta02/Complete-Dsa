/*
in this problem, here we first try to active all nodes with certain value and then check
if we can join the nodes with these values to those nodes that have already been visited
and we are sure that if there are previous active nodes then their value will either be 
less than or equal to the current value and thus we merge them and form a connected
component. here we are assuming that we are processing the node's value in increasing
order so it ensures that all the connected nodes have value <= curr value that we are 
processing.

then for each value, we count the number of absolute parents of all the nodes with the 
given value and do (count,2) => count choose 2 and add to answer.

*/


class DSU{
public:
    int get_parent(int a, vector<int> &parent){
        return parent[a] = (parent[a] == a ? a : get_parent(parent[a], parent));
    }
    
    void mergee(int a, int b, vector<int> &parent, vector<int> &rank){
        a = get_parent(a, parent);
        b = get_parent(b, parent);
        if(rank[a] > rank[b]) parent[b] = a;
        else if(rank[b] > rank[a]) parent[a] = b;
        else{
            rank[a] ++; parent[b] = a;
        }
    }
};


class Solution {
public:
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n = vals.size();
        map<int, vector<int>>mp;
        vector<vector<int>> adj(n);
        vector<bool>active(n, false);
        vector<int>parent(n), rank(n, 0);
        for(int i = 0; i < n; i ++) parent[i] = i;
        DSU dsu;
        for(int i = 0; i < n - 1; i ++){
            int u = edges[i][0], v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for(int i = 0; i < n; i ++){
            mp[vals[i]].push_back(i);
        }
        int ans = n;
        for(auto it : mp){
            int val = it.first;
            vector<int>temp = it.second;
            for(auto p : temp) active[p] = true;
            for(auto p : temp){
                vector<int> v = adj[p];
                for(auto q : v){
                    if(!active[q]) continue;
                    dsu.mergee(p, q, parent, rank);
                }
            }
            map<int,int>freq;
            for(auto p : temp){
                freq[dsu.get_parent(p, parent)] ++;
            }
            for(auto r : freq){
                int f = r.second;
                ans += (f * (f - 1))/2;
            }
        }
        return ans;
    }
};