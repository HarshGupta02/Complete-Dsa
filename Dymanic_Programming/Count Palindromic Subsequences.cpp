class Solution{
    public:
    /*You are required to complete below method */
    using ll = long long int;
    long long int  countPS(string str)
    {
       ll n = str.size();
       const ll MOD = 1000000007;
       vector<vector<ll>>dp(n , vector<ll>(n));
       for(ll gap = 0 ; gap <= n - 1; gap ++){
           for(ll i = 0 , j = gap ; j <= n - 1 ; i ++ , j ++){
               if(gap == 0){
                   dp[i][j] = 1; continue;
               }
               if(gap == 1){
                   if(str[i] != str[j]) dp[i][j] = 2;
                   else dp[i][j] = 3; continue;
               }
               if(str[i] == str[j]){
                   dp[i][j] = ((dp[i][j - 1] + dp[i + 1][j]) % MOD + 1) % MOD;
               }else dp[i][j] = ((dp[i][j - 1] + dp[i + 1][j]) % MOD - dp[i + 1][j - 1] + MOD) % MOD;
               dp[i][j] = dp[i][j] % MOD;
           }
       }
       return dp[0][n - 1] % MOD;
    }
     
};