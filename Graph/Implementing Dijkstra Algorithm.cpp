class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        vector<vector<pair<int,int>>>g(V);
        for(int i = 0; i < V;i ++){
            for(int j = 0; j < adj[i].size() ; j ++){
                g[i].push_back({adj[i][j][1] , adj[i][j][0]});
            }
        }
        priority_queue<pair<int,int>>pq;
        int src = S;
        pq.push({0,src});
        vector<int>dist(V,INT_MAX);
        dist[src] = 0;
        while(!pq.empty()){
            int curr_node = pq.top().second;
            int curr_dist = pq.top().first;
            pq.pop();
            for(auto p : g[curr_node]){
                    int new_node = p.second;
                    int weight = p.first;
                    if(dist[curr_node] + weight < dist[new_node]){
                        dist[new_node] = dist[curr_node] + weight;
                        pq.push({dist[new_node],new_node});
                    }
            }
        }
        return dist;
    }
};