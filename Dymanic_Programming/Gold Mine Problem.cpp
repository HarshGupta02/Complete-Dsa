class Solution{
public:
    int maxGold(int n, int m, vector<vector<int>> M)
    {
        vector<vector<int>>dp(n ,vector<int>(m));
        for(int i = 0; i < n ; i ++) dp[i][0] = M[i][0];
        for(int j = 1; j < m ; j ++){
            for(int i = 0; i < n ; i++){
                int maxi = INT_MIN;
                if(i - 1 >= 0) maxi = max(maxi , dp[i - 1][j - 1]);
                if(i >= 0) maxi = max(maxi , dp[i][j - 1]);
                if(i + 1 < n) maxi = max(maxi , dp[i + 1][j - 1]);
                dp[i][j] = maxi + M[i][j];
            }
        }
        int ans = INT_MIN;
        for(int i = 0; i < n ; i++) ans = max(ans , dp[i][m - 1]);
        return ans;
    }
};