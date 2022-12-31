/*

so we should always start from the cells that have value 0 so as
to maintain the property of absolute difference as 1.

so first of all cover/surround each zero from 1's in either
direction and then run a single source bfs from any 0 and keep on increasing the 
value after each bfs level

so first we run bfs on 0 values , then on all 1 values and then on all 2 values and 
then all 3 values and so on..

*/

class Solution {
public:
    
    array<int, 4> dx = {0, 1, 0, -1};
    array<int, 4> dy = {1, 0, -1, 0};
    
    bool isSafe(int x, int y, int n, int m, vector<vector<int>> &grid){
        return (x >= 0 and x < n and y >= 0 and y < m and grid[x][y] == -1);
    }
    
    vector<vector<int>> highestPeak(vector<vector<int>>& w) {
        int n = w.size(), m = w[0].size();
        vector<vector<int>> grid(n, vector<int> (m, -1));
        queue<pair<int, int>> q;
        for(int i = 0; i < n; i ++){
            for(int j = 0; j < m; j ++){
                if(w[i][j] == 1) {
                    grid[i][j] = 0;
                    q.push({i, j});
                }
            }
        }
        while(!q.empty()){
            int curr_x = q.front().first, curr_y = q.front().second;
            q.pop();
            for(int k = 0; k < 4; k ++){
                int x = curr_x + dx[k], y = curr_y + dy[k];
                if(isSafe(x, y, n, m, grid)){
                    grid[x][y] = 1 + grid[curr_x][curr_y];
                    q.push({x, y});
                }
            }
        }
        return grid;
    }
};