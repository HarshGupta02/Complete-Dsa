class Solution {
public:
    vector<vector<int>>adj;
    vector<int>indegree;
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        adj.resize(n); indegree.resize(n, 0);
        for(int i = 0; i < n ; i ++){
            for(int j = 0; j < graph[i].size(); j ++){
                int u = i, v = graph[i][j];
                adj[v].push_back(u);
                indegree[u] ++;
            }
        }
        vector<int>ans;
        queue<int>q;
        for(int i = 0; i < n ; i ++){
            if(indegree[i] == 0) q.push(i);
        }
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            ans.push_back(curr);
            for(auto neigh : adj[curr]){
                indegree[neigh] --;
                if(indegree[neigh] == 0) q.push(neigh);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};