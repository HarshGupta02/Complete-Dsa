class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       vector<vector<int>>dp(n + 1 , vector<int>(W + 1));
       for(int i = 0; i <= n; i ++){
           for(int j = 0; j <= W ; j ++){
               if(i == 0 or j == 0) dp[i][j] = 0;
           }
       }
       for(int i = 1; i <= n ; i++){
           for(int j = 1; j <= W ; j ++){
               if(j < wt[i - 1])  dp[i][j] = dp[i - 1][j];
               else dp[i][j] = max(dp[i - 1][j] , val[i - 1] + dp[i - 1][j - wt[i - 1]]);
           }
       }
       return dp[n][W];
    }
};