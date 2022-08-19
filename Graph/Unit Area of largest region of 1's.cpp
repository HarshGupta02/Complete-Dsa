class Solution
{
    public:
    //Function to find unit area of the largest region of 1s.
    
    int dx[8] = {-1,-1,0,1,1,1,0,-1};
    int dy[8] = {0,1,1,1,0,-1,-1,-1};
    
    bool isSafe(int n, int m, int x, int y, vector<vector<int>> &grid, vector<vector<bool>> &seen){
        return (x >= 0 and x < n and y >= 0 and y < m and grid[x][y] == 1 and !seen[x][y]);
    }
    
    void dfs(int n, int m, int x, int y, vector<vector<int>> &grid, vector<vector<bool>> &seen, int &cnt){
        seen[x][y] = true;
        for(int i = 0; i < 8; i ++){
            int new_x = x + dx[i], new_y = y + dy[i];
            if(isSafe(n, m, new_x, new_y, grid, seen)) {
                cnt ++;
                dfs(n, m, new_x, new_y, grid, seen, cnt);
            }
        }
    }
    
    int findMaxArea(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int ans = 0;
        vector<vector<bool>>seen(n, vector<bool>(m, false));
        for(int i = 0; i < n; i ++){
            for(int j = 0; j < m; j ++){
                if(grid[i][j] == 1 and !seen[i][j]){
                    int cnt = 1;
                    dfs(n, m, i, j, grid, seen, cnt);
                    ans = max(ans, cnt);
                } 
            }
        }
        return ans;
    }
};