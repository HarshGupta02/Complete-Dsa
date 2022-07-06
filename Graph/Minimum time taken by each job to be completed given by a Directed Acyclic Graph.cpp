// KAHN'S ALGORITHM - AN ACTIVITY WILL ONLY BE PERFORMED WHEN ALL OF IT'S INDEGREE'S ARE OVER AND 
// THEN ONLY PUSH TO QUEUE AS IT IS COMPLETED.

class Solution{
    public:
        vector<int> minimumTime(int n,vector<vector<int>> &edges,int m)
        {
            vector<vector<int>>adj(n + 1);
            vector<int>Indegree(n + 1,0);
            vector<int>ans(n);
            for(int i = 0; i < m ; i ++){
                int u = edges[i][0] , v = edges[i][1];
                adj[u].push_back(v);
                Indegree[v] ++;
            }
            queue<int>q;
            for(int i = 1; i <= n ; i ++){
                if(Indegree[i] == 0){
                    q.push(i); ans[i - 1] = 1;
                }
            }
            while(!q.empty()){
                int curr_node = q.front();
                q.pop();
                for(auto neigh : adj[curr_node]){
                    Indegree[neigh] --;
                    if(Indegree[neigh] == 0){
                        ans[neigh - 1] = ans[curr_node - 1] + 1;
                        q.push(neigh);
                    }
                }
            }
            return ans;
        }
};