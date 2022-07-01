class Solution
{
public:
    using ll = long long int;
    int countFriendsPairings(int n) 
    { 
        const ll MOD = 1e9 + 7;
        vector<ll>dp(n + 1);
        dp[1] = 1; dp[2] = 2;
        for(int i = 3; i <= n ; i++){
            ll x = (i - 1) * dp[i - 2];
            x = x % MOD;
            dp[i] = dp[i - 1] + x;
            dp[i] %= MOD;
        }
        return dp[n] % MOD;
    }
};