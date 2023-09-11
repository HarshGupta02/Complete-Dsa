/*
so here we basically have to find the shortest path so we use bfs. then
we insert all the nodes to the queue as they can be the starting for the
smallest path. and we don't need seen as each path can be reached via a 
particular paths.
*/

class Solution {
public:
    int shortestPathLength(vector<vector<int>>& adj) {
        int n = adj.size();
        int all = (1 << n) - 1;
        queue<vector<int>> q;
        set<pair<int, int>> st;
        for(int i = 0; i < n; i ++) {
            q.push({i, 0, 1 << i});
            st.insert({i, 1 << i});
        }
        while(!q.empty()) {
            int curr = q.front()[0], dist = q.front()[1], mask = q.front()[2];
            q.pop();
            for(auto neigh : adj[curr]) {
                int new_mask = mask | (1 << neigh);
                if(new_mask == all) return dist + 1;
                if(st.find({neigh, new_mask}) != st.end()) continue;
                q.push({neigh, dist + 1, new_mask});
                st.insert({neigh, new_mask});
            }
        }
        return -1;
    }
};