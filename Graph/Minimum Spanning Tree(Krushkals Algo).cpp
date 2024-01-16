class DSU{
public:
    vector<int> parent, rank;
    DSU(int n) {
        parent.resize(n); rank.resize(n, 1);
        for(int i = 0; i < n; i ++) parent[i] = i;
    }
    
    int get_parent(int a) {
        return (parent[a] == a ? a : get_parent(parent[a]));
    }
    
    void mergee(int a, int b) {
        a = get_parent(a);
        b = get_parent(b);  
        if(rank[b] < rank[a]) parent[b] = a;
        else if(rank[a] < rank[b]) parent[a] = b;
        else {
            rank[a] ++;
            parent[b] = a;
        }
    }
};

class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[]){
        vector<pair<int, pair<int, int>>> edges;
        for(int i = 0; i < V; i ++) {
            for(auto it : adj[i]) {
                int v = it[0], w = it[1];
                edges.push_back({w, {i, v}});
            }
        }
        sort(edges.begin(), edges.end());
        DSU dsu(V);
        int sum = 0;
        for(auto it : edges) {
            int wt = it.first, u = it.second.first, v = it.second.second;
            if(dsu.get_parent(u) != dsu.get_parent(v)) {
                dsu.mergee(u, v);
                sum += wt;
            }
        }
        return sum;
    }
};