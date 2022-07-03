class Solution{

	public:
	int findWinner(int N, int X, int Y)
	{
	    vector<vector<bool>>dp(2 ,vector<bool>(N + 1 , true));
	    dp[0][0] = false; dp[1][0] = false;
	    dp[0][1] = true; dp[1][1] = true;
	    for(int i = 2; i <= N ; i ++){
	        if(i >= X) dp[0][i] = dp[0][i] and dp[1][i - X];
	        if(i >= Y) dp[0][i] = dp[0][i] and dp[1][i - Y];
	        if(i >= 1) dp[0][i] = dp[0][i] and dp[1][i - 1];
	        
	        dp[0][i] = !dp[0][i];
	        
	        if(i >= X) dp[1][i] = dp[1][i] and dp[0][i - X];
	        if(i >= Y) dp[1][i] = dp[1][i] and dp[0][i - Y];
	        if(i >= 1) dp[1][i] = dp[1][i] and dp[0][i - 1];
	        
	        dp[1][i] = !dp[1][i];
	    }
	    if(dp[0][N] == true) return 1;
	    return 0;
	}
};