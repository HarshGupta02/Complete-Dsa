/*

if need to check if 2 strings are equal or not, we can use rolling hash to compare
2 strings in O(n ^ 2) and not O(n ^ 3).

hash function = ((p^i) * s[i]);

*/

class Solution {
public:
    using ll = long long int;
    ll p = 37;
    const ll MOD = 1e9 + 7;
    
    int deleteString(string s) {
        int n = s.size();
        vector<vector<ll>> hash(n, vector<ll>(n, 0));
        
        for(int i = 0; i < n; i ++){
            ll ans = 0, pwr = p;
            for(int j = i; j < n; j ++){
                ll val = (pwr * s[j]) % MOD;
                ans = (ans + val) % MOD;
                hash[i][j] = ans;
                pwr = (pwr * p) % MOD;
            }
        }
        
        vector<int>dp(n);
        dp[n - 1] = 1;
        for(int i = n - 2; i >= 0; i --){
            int len = n - i;
            int k = 1;
            int nax = 1;
            while(k <= len/2){
                if(hash[i][i + k - 1] == hash[i + k][i + k + k - 1]) 
                    nax = max(nax, 1 + dp[i + k]);
                k ++;
            }
            dp[i] = nax;
        }
        return dp[0];
    }
};