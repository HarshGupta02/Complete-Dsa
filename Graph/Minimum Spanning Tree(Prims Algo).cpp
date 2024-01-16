class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[]){
        int sum = 0;
        vector<bool> seen(V, false);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 0});
        while(!pq.empty()) {
            int wt = pq.top().first, node = pq.top().second; pq.pop();
            if(seen[node]) continue;
            seen[node] = true;
            sum += wt;
            for(auto neigh : adj[node]) {
                int new_node = neigh[0], new_wt = neigh[1];
                if(seen[new_node]) continue;
                pq.push({new_wt, new_node});
            }
        }
        return sum;
    }
};