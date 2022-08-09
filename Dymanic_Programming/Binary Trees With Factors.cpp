// METHOD 1: TIME = O(N * N), SPACE = O(N).

class Solution {
public:
    const int MOD = 1e9 + 7;
    using ll = long long int;
    
    ll mod_add(ll a,ll b){
        if(a+b<=MOD) return a+b;
        return ((a+b+MOD)%MOD);
    }

    ll mod_sub(ll a,ll b){
        if(a-b<=MOD)
         return a-b;
        return ((a-b+MOD)%MOD);
    }

    ll mod_mul(ll a,ll b){
        if(a*b<=MOD)
         return a*b;
        return ((a*b+MOD)%MOD);
    }
    
    int numFactoredBinaryTrees(vector<int>& a) {
        int n = a.size();
        unordered_map<ll,ll>dp;
        sort(a.begin(), a.end());
        ll ans = 0;
        for(int i = 0; i < n; i ++){
            ll curr = a[i];
            dp[curr] = 1;
            for(int j = 0; j < i; j ++){
                if(curr % a[j] == 0){
                    dp[curr] = mod_add(dp[curr], mod_mul(dp[a[j]], dp[curr/a[j]]));
                }
            }
            ans = mod_add(ans, dp[curr]);
        }
        return ans;
    }
};

/// METHOD 2: 