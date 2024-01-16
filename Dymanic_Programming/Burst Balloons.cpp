/*
here we have to find max profit of bursting all ballons. so first we try to find max profit by
bursting some subarray of the ballon. the max price for that subarray will be the max of all the 
profit by bursting each ballon in that subarray as the last ballon so two subarray ans we know
as dp[i][k - 1] and d[k + 1][j] and since all ballons are burst so we are left with the i - 1th 
balloon and the j + 1th ballon.
*/

class Solution {
public:
    
    int maxCoins(vector<int>& a) {
        int n = a.size();
        vector<vector<int>> dp(n, vector<int> (n, 0));
        for(int gap = 0; gap < n; gap ++){
            for(int i = 0, j = gap; i < n and j < n; i ++, j ++){
                if(gap == 0) 
                    dp[i][j] = a[i] * (i - 1 >= 0 ? a[i - 1] : 1) * (i + 1 < n ? a[i + 1] : 1);
                else {
                    for(int k = i; k <= j; k ++){
                        dp[i][j] = max(dp[i][j], a[k] * (i - 1 >= 0 ? a[i - 1] : 1) * (j + 1 < n ? a[j + 1] : 1)
                                      + (k - 1 >= i ? dp[i][k - 1] : 0) + (k + 1 <= j ? dp[k + 1][j] : 0));
                    }
                }
            }
        }
        return dp[0][n - 1];
    }
};