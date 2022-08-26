/*
initially the root node has degree 0 and all other have degree 1.
on adding an edge in a rooted directed tree, if the edge ends on root then each node has
an indegree of 1 so there will be a cycle for sure and there will only be 1 such cycle so
dsu can be applied on directed graph (here only possible) and the last edge with same 
parents is the ans.

if the new edge does not end on root node, so there will be 1 node with indegree 0, 1 node
with indegree 2 and all the other nodes with indegree 1.

the node with indegree 2 has 2 edges towards him out of which one has to be removed. so we
choose the second one and check if on removal of that edge(by not processing in dsu), will
there be cycle or not. if there is still a cycle so our assumption is wrong and answer is 
1st one else 2nd one.

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
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int>parent(n + 1), rank(n + 1, 0);
        for(int i = 1; i <= n; i ++) parent[i] = i;
        DSU dsu;
        vector<int>indegree(n + 1, 0);
        for(auto it : edges){
            int u = it[0], v = it[1];
            indegree[v] ++;
        }
        bool found = false;
        int node;
        for(int i = 1; i <= n; i ++){
            if(indegree[i] == 2){
                found = true; node = i; 
                break;
            }
        }
        if(!found){
            vector<int>ans;
            for(auto it : edges){
                int u = it[0], v = it[1];
                if(dsu.get_parent(u, parent) != dsu.get_parent(v, parent)) dsu.merge_child(u, v, parent, rank);
                else ans = it;
            }
            return ans;
            
        }else{
            int possible_1, possible_2;
            vector<int>a;
            for(int i = 0; i < n; i ++){
                int u = edges[i][0], v = edges[i][1];
                if(v == node) a.push_back(i);
            }
            possible_1 = a[0], possible_2 = a[1];
            bool can = false;
            for(int i = 0; i < n; i ++){
                if(i == possible_2) continue;
                int u = edges[i][0], v = edges[i][1];
                if(dsu.get_parent(u, parent) != dsu.get_parent(v, parent)) dsu.merge_child(u, v, parent, rank);
                else return {edges[possible_1][0], edges[possible_1][1]};
            }
            return {edges[possible_2][0], edges[possible_2][1]};
        }
    }
};