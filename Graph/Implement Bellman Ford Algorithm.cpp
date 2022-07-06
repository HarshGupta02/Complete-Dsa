// here we relax all the edges of the graph exactly n - 1 times as if dist[u] + w < dist[v] so
// dist[v] = dist[u] + w;

// after n - 1 iterations we have the shortest distance of all nodes from a single source. if we
// again relax one more time and if there is any updation in dist[] then there is a negative 
// cycle.

// this algo can detect negative cycles in DG(any) and in UG(for only postive edge weights and 
// not for negative edge weight).

class Solution {
public:
	int isNegativeWeightCycle(int n, vector<vector<int>>edges){
	    int m = edges.size();
	    vector<int>dist(n,INT_MAX);
	    dist[0] = 0;
	    for(int i = 0; i < n - 1 ; i ++){
	        for(auto it : edges){
	            if(dist[it[0]] != INT_MAX and dist[it[0]] + it[2] < dist[it[1]]){
	                dist[it[1]] = dist[it[0]] + it[2];
	            }
	        }
	    }
	    for(auto it : edges){
	        if(dist[it[0]] != INT_MAX and dist[it[0]] + it[2] < dist[it[1]]) return 1;
	    }
	    return 0;
	}
};