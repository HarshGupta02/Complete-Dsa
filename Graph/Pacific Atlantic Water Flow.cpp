class Solution {
public:
    
    // always start from that node which is gurantee to satisfy the 
    // given condition.
    int dx[4] = {0,-1,0,1};
    int dy[4] = {-1,0,1,0};
    
    bool isSafe(int m, int n, int x, int y, vector<vector<bool>> &visited){
        return (x >= 0 and x < m and y >= 0 and y < n and !visited[x][y]);
    }
    
    void dfs(int m, int n, int x, int y, vector<vector<bool>> &visited, vector<vector<int>> &heights){
        visited[x][y] = true;
        for(int i = 0; i < 4; i ++){
            int new_x = x + dx[i], new_y = y + dy[i];
            if(isSafe(m, n, new_x, new_y, visited) and heights[new_x][new_y] >= heights[x][y])
                dfs(m, n, new_x, new_y, visited, heights);
        }
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        vector<vector<int>>ans;
        vector<vector<bool>>pacific(m, vector<bool>(n, false));
        vector<vector<bool>>atlantic(m, vector<bool>(n, false));
        for(int i = 0; i < m; i ++){
            dfs(m, n, i, 0, pacific, heights);
            dfs(m, n, i, n - 1, atlantic, heights);
        }
        for(int i = 0; i < n; i ++){
            dfs(m, n, 0, i, pacific, heights);
            dfs(m, n, m - 1, i, atlantic, heights);
        }
        for(int i = 0; i < m; i ++){
            for(int j = 0; j < n; j ++){
                if(pacific[i][j] and atlantic[i][j]){
                    vector<int>curr = {i, j};
                    ans.push_back(curr);
                }
            }
        }
        return ans;
        
    }
};