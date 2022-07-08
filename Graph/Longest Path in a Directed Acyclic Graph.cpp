/*
here we perform a topo sort so that we can update the neigh of the curr node because
the curr node will be updated first then the neigh.

so we perform topo sort starting from the source.


*/


class Solution
{
    public:
    
      void dfs(int src,vector<vector<pair<int,int>>> adj,vector<bool> &visited,stack<int> &stk){
          visited[src] = true;
          for(auto neigh : adj[src]){
              if(!visited[neigh.first]) dfs(neigh.first,adj,visited,stk);
          }
          stk.push(src);
      }
    
      vector <int> maximumDistance(vector<vector<int>> edges,int v,int e,int src)
      {
          vector<vector<pair<int,int>>>adj(v);
          for(int i = 0; i < e ; i ++){
              adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
          }
          vector<int>dist(v,INT_MIN);
          vector<bool>visited(v,false); stack<int>stk;
          dfs(src,adj,visited,stk);
          dist[src] = 0;
          while(!stk.empty()){
              int curr = stk.top(); stk.pop();
              for(auto neigh : adj[curr]){
                  dist[neigh.first] = max(dist[neigh.first] , dist[curr] + neigh.second);
              }
          }
          return dist;
      }
};