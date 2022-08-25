class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int cutoff) {
        vector<vector<int>>dist(n, vector<int>(n, INT_MAX));
        for(int i = 0; i < n ; i ++) dist[i][i] = 0;
        for(auto it : edges) {
            dist[it[0]][it[1]] = it[2];
            dist[it[1]][it[0]] = it[2];
        }
        for(int k = 0; k < n; k ++){
            for(int i = 0; i < n; i ++){
                for(int j = 0; j < n; j ++){
                    if(dist[i][k] < INT_MAX and dist[k][j] < INT_MAX)
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
        int mini = INT_MAX;
        int city;
        for(int i = 0; i < n; i ++){
            int cnt = 0;
            for(int j = 0; j < n; j ++){
                if(i == j) continue;
                if(dist[i][j] <= cutoff) cnt ++;
            }
            if(cnt <= mini) {
                city = i;
                mini = cnt;
            }
        }
        return city;
    }
};