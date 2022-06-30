/// TIME = O(N * R) , SPACE = O(N * R)

class Solution{
public:
    using ll = long long int;
    const ll MOD = 1e9 + 7;
    int nCr(int n, int r){
        vector<vector<ll>>dp(n + 1, vector<ll>(r + 1,0));
        for(int i = 0; i <= n ; i ++) dp[i][0] = 1;
        for(int i = 1; i <= n ; i++){
            for(int j = 1 ; j <= r ;j ++){
                if(i < j) continue;
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
                dp[i][j] %= MOD;
            }
        }
        return dp[n][r] % MOD;
    }
};

// TIME = O(N * R) , SPACE = O(2 * R) ~ O(R)

class Solution{
public:
    using ll = long long int;
    const ll MOD = 1e9 + 7;
    int nCr(int n, int r){
        // vector<vector<ll>>dp(n + 1, vector<ll>(r + 1,0));
        vector<ll>prev(r + 1,0) , curr(r + 1,0);
        // for(int i = 0; i <= n ; i ++) dp[i][0] = 1;
        prev[0] = 1;
        for(int i = 1; i <= n ; i++){
            curr[0] = 1;
            for(int j = 1 ; j <= r ;j ++){
                if(i < j) continue;
                curr[j] = prev[j] + prev[j - 1];
                curr[j] %= MOD;
            }
            prev = curr;
        }
        return prev[r] % MOD;
    }
};