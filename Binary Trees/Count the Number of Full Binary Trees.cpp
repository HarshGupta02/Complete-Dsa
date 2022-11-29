class Solution{
public:
    using ll = long long int;
    const int MOD = 1e9 + 7;
    
    long long int numoffbt(long long int a[], int n){
        ll nax = -1;
        for(int i = 0; i < n; i ++) nax = max(nax, a[i]);
        vector<ll>dp(nax + 1, 0);
        for(int i = 0; i < n; i ++) dp[a[i]] = 1;
        ll ans = 0;
        for(int i = 2; i <= nax; i ++){
            if(dp[i] == 0) continue;
            for(int j = i+i; j <= nax and (j/i) <= i; j += i){
                if(dp[j] == 0) continue;
                dp[j] += (dp[i] * dp[j/i]);
                if(i != (j/i)) dp[j] += (dp[i] * dp[j/i]);
            }
            ans = (ans + dp[i]) % MOD;
        }
        return ans % MOD;
    }
};