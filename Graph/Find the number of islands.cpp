class Solution {
  public:
    
    int dx[8] = {0,-1,-1,-1,0,1,1,1};
    int dy[8] = {-1,-1,0,1,1,1,0,-1};
    
    bool isSafe(int x,int y,int n,int m,vector<vector<bool>> &visited,vector<vector<char>> &M){
        return (x >= 0 and x < n and y >= 0 and y < m and visited[x][y] == false and M[x][y] == '1');
    }
    
    void dfs(int s_x,int s_y,int n,int m,vector<vector<bool>> &visited,vector<vector<char>> &M){
        visited[s_x][s_y] = true;
        for(int i = 0; i < 8 ; i ++){
            int new_x = s_x + dx[i];
            int new_y = s_y + dy[i];
            if(isSafe(new_x,new_y,n,m,visited,M)) dfs(new_x,new_y,n,m,visited,M);
        }
    }
  
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& M) {
        int n = M.size() , m = M[0].size();
        vector<vector<bool>>visited(n,vector<bool>(m,false));
        int ans = 0;
        for(int i = 0; i < n ; i ++){
            for(int j = 0; j < m ; j ++){
                if(!visited[i][j] and M[i][j] == '1'){
                    dfs(i,j,n,m,visited,M);
                    ans ++;
                }
            }
        }
        return ans;
    }
};