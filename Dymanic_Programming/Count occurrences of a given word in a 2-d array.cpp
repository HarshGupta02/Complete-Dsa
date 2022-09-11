class Solution{
    public:
    
    int dx[4] = {0,-1,0,1};
    int dy[4] = {-1,0,1,0};
    
    bool isSafe(int x, int y, int r, int c, vector<vector<bool>> &seen, int idx, vector<vector<char>> &mat, string target){
        return (x >= 0 and x < r and y >= 0 and y < c and !seen[x][y] and mat[x][y] == target[idx]);
    }
    
    void f(int idx, int i, int j, int r, int c, int n, string target, vector<vector<char>> &mat, vector<vector<bool>> &seen, int &curr){
        seen[i][j] = true;
        if(idx == n){
            curr ++;
            return;
        }
        for(int k = 0; k < 4; k ++){
            int new_x = i + dx[k], new_y = j + dy[k];
            if(isSafe(new_x, new_y, r, c, seen, idx, mat, target)){
                f(idx + 1, new_x, new_y, r, c, n, target, mat, seen, curr);
                seen[new_x][new_y] = false;
            }
        }
    }
    
    int findOccurrence(vector<vector<char>> &mat, string target){
        int r = mat.size(), c = mat[0].size();
        vector<vector<bool>> seen(r, vector<bool>(c, false));
        int ans = 0, n = target.size();
        for(int i = 0; i < r; i ++){
            for(int j = 0; j < c; j ++){
                if(mat[i][j] != target[0]) continue;
                int curr = 0;
                seen[i][j] = true;
                f(1,i, j, r, c, n, target, mat, seen, curr);
                seen[i][j] = false;
                ans += curr;
            }
        }
        return ans;
    }
};
