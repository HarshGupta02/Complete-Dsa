class Solution {
public:
    const int MOD = (int)1e9 + 7;
    using ll = long long int;
    int numTilings(int n) {
        if(n <= 2) return n;
        if(n == 3) return 5;
        vector<ll> dp(n + 1, 0);
        dp[1] = 1; dp[2] = 2; dp[3] = 5;
        for(int i = 4; i <= n; i ++){
            dp[i] = (dp[i] + dp[i - 3]) % MOD;
            ll p = (2 * dp[i - 1]) % MOD;
            dp[i] = (dp[i] + p) % MOD;
        }
        return dp[n] % MOD;
    }
};