class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
    
    int dx[8] = {-1,-2,-2,-1,1,2,2,1};
    int dy[8] = {-2,-1,1,2,2,1,-1,-2};
    
    bool isSafe(int x,int y,int N,vector<vector<bool>> &visited){
        return (x >= 0 and x < N and y >= 0 and y < N and visited[x][y] == false);
    }
    
    void bfs(int s_x,int s_y,int t_x,int t_y,int N,vector<vector<bool>> &visited,vector<vector<long long int>> &ans){
        visited[s_x][s_y] = true;
        queue<pair<int,int>>q;
        q.push({s_x,s_y});
        ans[s_x][s_y] = 0;
        while(!q.empty()){
            int curr_x = q.front().first;
            int curr_y = q.front().second;
            q.pop();
            for(int i = 0; i < 8 ; i ++){
                int x = curr_x + dx[i];
                int y = curr_y + dy[i];
                if(isSafe(x,y,N,visited)){
                    visited[x][y] = true;
                    ans[x][y] = min(ans[x][y], 1 + ans[curr_x][curr_y]);
                    q.push({x,y});
                }
            }
        }
    }
    
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    vector<vector<bool>>visited(N,vector<bool>(N,false));
	    vector<vector<long long int>>ans(N,vector<long long int>(N,1e18));
	    int start_x = N - KnightPos[1] , start_y = KnightPos[0] - 1;
	    int target_x = N - TargetPos[1] , target_y = TargetPos[0] - 1;
	    bfs(start_x,start_y,target_x,target_y,N,visited,ans);
	    if(ans[target_x][target_y] == INT_MAX) return -1;
	    return ans[target_x][target_y];
	}
};
