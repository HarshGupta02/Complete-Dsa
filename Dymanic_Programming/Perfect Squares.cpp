// TIME = O(N * SQRT(N)), SPACE = O(N)

class Solution {
public:
    int numSquares(int n) {
        vector<int>dp(n + 1, INT_MAX - 1);
        dp[0] = 0; dp[1] = 1;
        for(int i = 2; i <= n; i ++){
            for(int j = 1; j * j <= i; j ++){
                dp[i] = min(dp[i], 1 + dp[i - (j * j)]);
            }
        }
        return dp[n];
    }
};

