class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<vector<bool>>> seen(m, vector<vector<bool>> (n, vector<bool> (k + 1, false)));
        int dx[] = {0,1,0,-1};
        int dy[] = {1,0,-1,0};
        queue<vector<int>> q;
        vector<int> root = {0, 0, k};
        q.push(root);
        int steps = 0;
        while(!q.empty()){
            int sz = q.size();
            while(sz -- > 0){
                vector<int> temp = q.front();
                q.pop();
                if(temp[0] == m - 1 and temp[1] == n - 1) return steps;
                for(int i = 0; i < 4; i ++){
                    int new_x = temp[0] + dx[i], new_y = temp[1] + dy[i], obs = temp[2];
                    if(new_x >= 0 and new_x < m and new_y >= 0 and new_y < n){
                        if(grid[new_x][new_y] == 0 and !seen[new_x][new_y][obs]){
                            q.push({new_x, new_y, obs});
                            seen[new_x][new_y][obs] = true;
                        }else if(grid[new_x][new_y] == 1 and obs > 0 and !seen[new_x][new_y][obs - 1]){
                            q.push({new_x, new_y, obs - 1});
                            seen[new_x][new_y][obs - 1] = true;
                        }
                    }
                }
            }
            steps ++;
        }
        return -1;
    }
};