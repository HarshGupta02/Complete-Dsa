class Solution{
	public:
	int findWinner(int N, int X, int Y)
	{
	    vector<vector<bool>>dp(3 ,vector<bool>(N + 1 , true));
	    dp[1][0] = false; dp[2][0] = false;
	    dp[1][1] = true; dp[2][1] = true;
	    for(int i = 2; i <= N ; i ++){
            
	        if(i >= X) dp[1][i] = dp[1][i] and dp[2][i - X];
	        if(i >= Y) dp[1][i] = dp[1][i] and dp[2][i - Y];
	        if(i >= 1) dp[1][i] = dp[1][i] and dp[2][i - 1];
	        
	        dp[1][i] = !dp[1][i];
	        
	        if(i >= X) dp[2][i] = dp[2][i] and dp[1][i - X];
	        if(i >= Y) dp[2][i] = dp[2][i] and dp[1][i - Y];
	        if(i >= 1) dp[2][i] = dp[2][i] and dp[1][i - 1];
	        
	        dp[2][i] = !dp[2][i];
	    }
	    if(dp[1][N] == true) return 1;
	    return 0;
	}
};