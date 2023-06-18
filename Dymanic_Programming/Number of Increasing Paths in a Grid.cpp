class Solution {
public:
    int n, m;
    vector<vector<int>> dp;
    static const int MOD = 1e9 + 7;
    
    int dx[4] = {0, -1, 0, 1};
    int dy[4] = {-1, 0, 1, 0};
    
    int dfs(int i, int j, vector<vector<int>> &grid) {
        if(dp[i][j] != -1) return dp[i][j];
        int ans = 1;
        for(int k = 0; k < 4; k ++) {
            int new_x = i + dx[k], new_y = j + dy[k];
            if(new_x >= 0 and new_x < n and new_y >= 0 and new_y < m and grid[i][j] < grid[new_x][new_y]) {
                ans = (ans + dfs(new_x, new_y, grid)) % MOD;
            }
        }
        return dp[i][j] = ans % MOD;
    }
    
    int countPaths(vector<vector<int>>& grid) {
        n = grid.size(); m = grid[0].size();
        dp.resize(n, vector<int> (m, -1));
        int ans = 0;
        for(int i = 0; i < n; i ++) {
            for(int j = 0; j < m; j ++) {
                ans = (ans + dfs(i, j, grid)) % MOD;
            }
        }
        return ans % MOD;
    }
};