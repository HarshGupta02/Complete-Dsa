class Solution {
public:
    
    int dx[4] = {0,-1,0,1};
    int dy[4] = {-1,0,1,0};
    
    bool isSafe(int x,int y,int m,int n,vector<vector<int>> &image,vector<vector<bool>> &visited,int color,int pixel){
        return (x >= 0 and x < m and y >= 0 and y < n and visited[x][y] == false and image[x][y] == pixel);
    }
        
    void bfs(int s_x,int s_y,int m,int n,int color,vector<vector<int>> &image,vector<vector<bool>> &visited,vector<vector<int>> &ans,int pixel){
        visited[s_x][s_y] = true;
        queue<pair<int,int>>q;
        q.push({s_x,s_y});
        ans[s_x][s_y] = color;
        while(!q.empty()){
            int curr_x = q.front().first;
            int curr_y = q.front().second;
            q.pop();
            for(int i = 0; i < 4 ; i++){
                int new_x = curr_x + dx[i];
                int new_y = curr_y + dy[i];
                if(isSafe(new_x,new_y,m,n,image,visited,color,pixel)){
                    visited[new_x][new_y] = true;
                    ans[new_x][new_y] = color;
                    q.push({new_x,new_y});
                }
            }
        }
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size() , n = image[0].size();
        int src_x = sr , src_y = sc;
        vector<vector<bool>>visited(m,vector<bool>(n,false));
        vector<vector<int>>ans(m,vector<int>(n));
        ans = image;
        int pixel = image[src_x][src_y];
        bfs(src_x,src_y,m,n,color,image,visited,ans,pixel);
        return ans;
    }
};