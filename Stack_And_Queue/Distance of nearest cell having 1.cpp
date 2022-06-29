class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    // here we have tried to replace each 1 with 0 and vice
	    // versa and then tried to find min distance just like
	    // dijkstra.
	    int n = grid.size() , m = grid[0].size();
	    vector<vector<int>>ans(n,vector<int>(m,INT_MAX));
	    queue<pair<int,int>>q;
	    for(int i =0 ; i < n ; i ++){
	        for(int j = 0; j < m ; j++){
	            if(grid[i][j] == 1){
	                ans[i][j] = 0;
	                q.push({i,j});
	            }
	        }
	    }
	    /// ans[i][j] stores the min distance to reach  0 from 1
	    // which is same as min dist to reach 1 from 0.
	    while(!q.empty()){
	        int i = q.front().first , j = q.front().second;
	        q.pop();
	        if(i - 1 >= 0 and ans[i][j] + 1 < ans[i - 1][j]){
	            ans[i - 1][j] = ans[i][j] + 1;
	            q.push({i - 1,j});
	        }
	        if(i + 1 < n and ans[i][j] + 1 < ans[i + 1][j]){
	            ans[i + 1][j] = ans[i][j] + 1;
	            q.push({i + 1, j});
	        }
	        if(j - 1 >= 0 and ans[i][j] + 1 < ans[i][j - 1]){
	            ans[i][j - 1] = ans[i][j] + 1;
	            q.push({i , j - 1});
	        }
	        if(j + 1 < m and ans[i][j] + 1 < ans[i][j + 1]){
	            ans[i][j + 1] = ans[i][j] + 1;
	            q.push({i , j + 1});
	        }
	    }
	    return ans;
	}
};