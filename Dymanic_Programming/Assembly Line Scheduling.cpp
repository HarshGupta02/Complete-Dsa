// TIME = O(N) , SPACE = O(2 * N)

class Solution{
  public:
  int carAssembly(vector<vector<int>>& a, vector<vector<int>>& T, vector<int>& e, vector<int>& x){
      int n = a[0].size();
      vector<vector<int>>dp(2,vector<int>(n));
      dp[0][0] = a[0][0] + e[0]; dp[1][0] = a[1][0] + e[1];
      for(int j = 1; j < n ;j ++){
          dp[0][j] = a[0][j] + min(dp[0][j - 1] , dp[1][j - 1] + T[1][j]);
          dp[1][j] = a[1][j] + min(dp[1][j - 1] , dp[0][j - 1] + T[0][j]);
      }
      return min(dp[0][n - 1] + x[0] , dp[1][n - 1] + x[1]);
  }
};


// CAN BE DONE IN O(1) SPACE BY MAINTAINING PREV_SUM FOR BOTH .