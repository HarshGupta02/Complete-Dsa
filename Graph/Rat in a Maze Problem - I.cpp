class Solution{
    public:
    
    int dx[4] = {0,-1,0,1};
    int dy[4] = {-1,0,1,0};
    char dir[4] = {'L','U','R','D'};
    
    bool isSafe(int x,int y,vector<vector<int>> m , int n, vector<vector<bool>>&visited){
        return (x >= 0 and x < n and y >= 0 and y < n and visited[x][y] == false and m[x][y] == 1);
    }
    
    void dfs(int source_x , int source_y,vector<vector<int>> m,int n,vector<vector<bool>>&visited,vector<string> &ans,string path){
        if(source_x == n - 1 and source_y == n - 1){
            ans.push_back(path); return;
        }
        visited[source_x][source_y] = true;
        for(int i = 0; i < 4 ;i ++){
            int new_x = source_x + dx[i];
            int new_y = source_y + dy[i];
            if(isSafe(new_x , new_y , m , n , visited)){
                dfs(new_x , new_y , m , n , visited, ans , path + dir[i]);
            }
        }
        visited[source_x][source_y] = false;
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string>ans;
        vector<vector<bool>>visited(n , vector<bool>(n , false));
        if(m[0][0] == 0 or m[n - 1][n - 1] == 0) return ans;
        dfs(0,0,m,n,visited,ans,"");
        return ans;
    }
};

// LURD