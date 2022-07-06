// KRUSHKALS ALGORITHM = HERE WE SORT ALL THE EDGES IN ASCENDING ORDER AND TAKE THEIR COST IF
// BOTH THE NODES BELONG TO DIFFERENT PARENTS AND THEN ADD THEIR COST ELSE IGNORE.

struct Node{
    int w , u , v;
};

class DSU{
    public:
    vector<int>parent,rank;
    DSU(int n){
        parent.resize(n); rank.resize(n,0);
        for(int i = 0; i < n ; i ++) parent[i] = i;
    }
    
    int get_parent(int a){
        return parent[a] = (parent[a] == a) ? a : get_parent(parent[a]);
    }
    
    void Merge_Child(int a , int b){
        a = get_parent(a);
        b = get_parent(b);
        if(rank[a] > rank[b]) parent[b] = a;
        else if(rank[a] < rank[b]) parent[a] = b;
        else{
            rank[a] ++; parent[b] = a; 
        }
    }
};

class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<Node>g;
        for(int i = 0; i < V; i ++){
            for(int j = 0 ; j < adj[i].size(); j ++){
                Node obj;
                obj.w = adj[i][j][1];
                obj.u = i; obj.v = adj[i][j][0];
                g.push_back(obj);
            }
        }
        sort(g.begin(),g.end(),[&](const Node &a ,const Node &b) -> bool{
            return a.w < b.w;
        });
        int cost = 0;
        DSU dsu(V);
        for(int i = 0 ;i < g.size(); i ++){
            int curr_w = g[i].w , curr_u = g[i].u , curr_v = g[i].v;
            int p1 = dsu.get_parent(curr_u);
            int p2 = dsu.get_parent(curr_v);
            if(p1 != p2){
                cost += curr_w;
                dsu.Merge_Child(curr_u,curr_v);
            }
        }
        return cost;
    }
};

// PRIM'S ALGORITHM = HERE WE SELECT A SOURCE NODE AND THEN KEEP ON SELECTING THE MIN WEIGHT NODE
// THAT IS NOT PRESENT IN THE MST AND IS A NEIGHBOUR OF THE NODES THAT ARE CURRENTLY IN MST.

/// TIME = O(N ^ 2)

class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<int>key(V,INT_MAX);
        vector<bool>visited(V,false);
        vector<int>parent(V,-1);
        key[0] = 0; parent[0] = -1;
        for(int i = 0; i < V - 1; i ++){
            int mini = INT_MAX; int node;
            for(int j = 0; j < V; j ++){
                if(!visited[j] and key[j] < mini){
                    mini = key[j]; node = j;
                }
            }
            visited[node] = true;
            for(auto neigh : adj[node]){
                if(!visited[neigh[0]] and neigh[1] < key[neigh[0]]){
                    key[neigh[0]] = neigh[1];
                    parent[neigh[0]] = node; 
                }
            }
        }
        int cost = 0;
        for(int i = 0; i < V; i ++){
            if(parent[i] == -1) continue;
            for(auto neigh : adj[i]){
                if(neigh[0] == parent[i]) cost += neigh[1];
            }
        }
        return cost;
    }
};

/// EFFICIENT ALGO , TIME = O(N LOGN)

class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<int>key(V,INT_MAX);
        vector<bool>visited(V,false);
        vector<int>parent(V,-1);
        key[0] = 0; parent[0] = -1;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq; // {weight,node}
        pq.push({0,0});
        while(!pq.empty()){
            int node = pq.top().second;
            pq.pop();
            visited[node] = true;
            for(auto neigh : adj[node]){
                if(!visited[neigh[0]] and neigh[1] < key[neigh[0]]){
                    key[neigh[0]] = neigh[1];
                    parent[neigh[0]] = node;
                    pq.push({neigh[1],neigh[0]});
                }
            }
        }
        int cost = 0;
        for(int i = 0; i < V; i ++){
            if(parent[i] == -1) continue;
            for(auto neigh : adj[i]){
                if(neigh[0] == parent[i]) cost += neigh[1];
            }
        }
        return cost;
    }
};