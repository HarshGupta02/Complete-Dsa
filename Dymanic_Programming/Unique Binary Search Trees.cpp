class Solution {
public:
    int numTrees(int n) {
        vector<int>dp(n + 1);
        dp[0] = 1; dp[1] = 1;
        for(int i = 2; i <= n ; i ++){
            int sum = 0;
            int j = 0;
            while(j <= i - 1){
                sum += dp[j] * dp[i - j - 1];
                j ++;
            }
            dp[i] = sum;
        }
        return dp[n];
    }
};