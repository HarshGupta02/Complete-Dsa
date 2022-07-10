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
