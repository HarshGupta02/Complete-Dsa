class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        int m = flights.size();
        vector<vector<int>>v(n,vector<int>(n,1e5));
        for(int i = 0 ; i < n ; i ++){
            v[i][i] = 0;
        }
        vector<vector<pair<int,int>>>adj(n);
        for(int i = 0 ; i < m ; i ++){
            adj[flights[i][1]].push_back({flights[i][0],flights[i][2]});
            v[flights[i][0]][flights[i][1]] = flights[i][2];
        }
        int dp[n][n][k + 1];
        for(int i = 0; i < n ; i ++){
            for(int j = 0; j < n ; j ++){
                for(int x = 0; x <= k ; x ++){
                    if(i == j) dp[i][j][x] = 0;
                    else{
                        dp[i][j][0] = v[i][j];
                    }
                }
            }
        }
        for(int K = 1 ; K <= k ; K ++){
            for(int i = 0; i < n ; i ++){
                for(int j = 0 ; j < n ; j ++){
                    int mini = 1e5;
                    for(auto neigh : adj[j]){
                        mini = min(mini , dp[i][neigh.first][K - 1] + neigh.second);
                    }
                    mini = min(mini , dp[i][j][K - 1]);
                    dp[i][j][K] = mini;
                }
            }
        }
        return (dp[src][dst][k] == 1e5) ? -1 : dp[src][dst][k]; 
    }
};


// 10
// [[3,4,4],[2,5,6],[4,7,10],[9,6,5],[7,4,4],[6,2,10],[6,8,6],[7,9,4],
// [1,5,4],[1,0,4],[9,7,3],[7,0,5],[6,5,8],[1,7,6],[4,0,9],[5,9,1],[8,7,3],
// [1,2,6],[4,1,5],[5,2,4],[1,9,1],[7,8,10],[0,4,2],[7,2,8]]
// 6
// 0
// 7

//METHOD 2: 


struct Node{
    int weight, node, level;
    Node(int w, int n, int lvl){
        this -> weight = w;
        this -> node = n;
        this -> level = lvl;
    }
};

class Solution {
public:
    
    struct cmp{
        bool operator()(const Node &a, const Node &b){
            return a.weight < b.weight;
        }
    };
    
    vector<vector<pair<int,int>>>adj;
    
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        adj.resize(n);
        for(auto curr : flights){
            int u = curr[0], v = curr[1], w = curr[2];
            adj[u].push_back({v,w});
        }
        priority_queue<Node,vector<Node>,cmp>pq;
        int level = 0;
        pq.push(Node(0, src, level));
        int ans = 0;
        while(!pq.empty()){
            auto curr = pq.top();
            pq.pop();
            int w = curr.weight, curr_node = curr.node, lvl = curr.level;
            if(curr_node == dst) {
                ans += w;
                return ans;
            }
            if(lvl > k){
                pq.pop(); continue;
            }
            ans += w;
            for(auto neigh : adj[curr_node]) {
                pq.push(Node(neigh.second,neigh.first,lvl + 1));
            }
        }
        return -1;
    }
};

// METHOD 3: 

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for(int i = 0; i < flights.size(); i ++){
            int u = flights[i][0], v = flights[i][1], w = flights[i][2];
            adj[u].push_back({v, w});
        }
        vector<int> d(n, INT_MAX);
        d[src] = 0;
        queue<pair<int, pair<int, int>>> q; // {stops, {node, dist}}
        q.push({0, {src, 0}});
        
        while(!q.empty()){
            auto p = q.front(); q.pop();
            int stops = p.first, node = p.second.first, cost = p.second.second;
            if(stops > k) continue;
            for(auto neigh : adj[node]){
                int adjNode = neigh.first, w = neigh.second;
                if(cost + w <= d[adjNode] and stops <= k){
                    d[adjNode] = cost + w;
                    q.push({stops + 1, {adjNode, d[adjNode]}});
                }
            }
        }
        
        return (d[dst] == INT_MAX ? -1 : d[dst]);
    }
};


