/*
center of a tree are basically the middle nodes in the diameter or longest path in
the tree. if diameter is of odd length so there is only 1 center but if the 
diameter is of even length so there are 2 centers. so a tree cannot have more than
two centers.

so here we basically start from the leaf nodes, remove all the leaves, look at next
set of leaves and we keep on doing this until there are atmost 2 elements left in
as leaves. (just like khan's algo).

also if we root the tree at these centers, so we get the tree with the minimum
heigh (also called MHT (MINIMUM HEIGHT TREES)).

*/

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<int> degree(n, 0);
        for(int i = 0; i < n - 1; i ++) {
            int u = edges[i][0], v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            degree[u] ++; degree[v] ++;
        }
        if(n == 1) return {0};
        if(n == 2) return {edges[0][0], edges[0][1]};
        vector<int> leaves;
        for(int i = 0; i < n; i ++) {
            if(degree[i] == 1) {
                leaves.push_back(i);
                degree[i] = 0;
            }
        }
        int remains = n;
        while(remains > 2) {
            remains -= leaves.size();
            int sz = leaves.size();
            vector<int> temp;
            for(int i = 0; i < sz; i ++) {
                int curr_node = leaves[i];
                for(auto neigh : adj[curr_node]) {
                    degree[neigh] --;
                    if(degree[neigh] == 1) {
                        temp.push_back(neigh);
                        degree[neigh] = 0;
                    }
                }
            }
            leaves = temp;
        }
        return leaves;
    }
};