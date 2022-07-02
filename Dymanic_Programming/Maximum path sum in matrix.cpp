class Solution{
public:
    int maximumPath(int N, vector<vector<int>> Matrix)
    {
        vector<vector<int>>dp(N, vector<int>(N,INT_MIN));
        for(int i = 0; i < N ; i ++){
            dp[0][i] = Matrix[0][i];
        }
        for(int i = 1; i < N ; i ++){
            for(int j = 0; j < N ; j ++){
                if(i - 1 >= 0) dp[i][j] = max(dp[i][j] , dp[i - 1][j]);
                if(i - 1 >= 0 and j - 1 >= 0) dp[i][j] = max(dp[i][j] , dp[i - 1][j - 1]);
                if(i - 1 >= 0 and j + 1 < N) dp[i][j] = max(dp[i][j] , dp[i - 1][j + 1]);
                dp[i][j] += Matrix[i][j];
            }
        }
        int ans = -1;
        for(int i = 0 ; i < N ;i ++){
            ans = max(ans , dp[N - 1][i]);
        }
        return ans;
    }
};