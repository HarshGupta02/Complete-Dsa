class Solution {
  public:
  using ll = long long int;
    long long int count(int S[], int m, int n) {
        vector<ll>dp(n + 1);
        dp[0] = 1;
        for(int i = 0 ;i < m ; i++){
            for(int j = 0; j <= n ; j++){
                if(j >= S[i]){
                    dp[j] += dp[j - S[i]];
                }
            }
        }
        return dp[n];
    }
};