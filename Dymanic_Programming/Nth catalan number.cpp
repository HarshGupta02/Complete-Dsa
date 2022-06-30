class Solution
{
    public:
    //Function to find the nth catalan number.
    using ll = long long int;
    ll findCatalan(ll n) 
    {
        vector<ll>dp(n + 1);
        dp[0] = dp[1] = 1;
        for(ll i = 2 ; i <= n ; i++){
            ll j = 0 , k = i - 1;
            ll ans = 0;
            while(j < i){
                ans += dp[j] * dp[k];
                j ++; k --;
            }
            dp[i] = ans;
        }
        return dp[n];
    }
};