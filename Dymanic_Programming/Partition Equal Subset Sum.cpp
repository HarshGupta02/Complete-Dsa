class Solution{
public:
    int equalPartition(int N, int arr[])
    {
        int sum = 0;
        for(int i = 0; i < N ; i ++) sum += arr[i];
        if(sum % 2 == 1) return 0;
        int target = sum/2;
        vector<vector<bool>>dp(N + 1 , vector<bool>(target + 1));
        dp[0][0] = true;
        for(int i = 1; i <= N ; i ++) dp[i][0] = true;
        for(int i = 1 ; i <= N ; i ++){
            for(int j = 1; j <= target ; j ++){
                if(j < arr[i - 1])
                    dp[i][j] = dp[i - 1][j];
                else 
                    dp[i][j] = dp[i - 1][j] or dp[i - 1][j - arr[i - 1]];
            }
        }
        return dp[N][target];
    }
};