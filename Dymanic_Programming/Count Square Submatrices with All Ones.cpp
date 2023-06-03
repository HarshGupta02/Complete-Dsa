/*
here we see that dp[i][j] = tells the number of sqaure submatrices that are all 1's and end on
coordinates = (i, j);

we see that dp[i][j] = 1 + min(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]);
because if a cell can end with 4 submatrices so it can also end with 3 or 2 or 1 submatrices
and hence we take the min of all three and add 1 so as to increase the dimensions by 1 in length
and breath.

*/

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int> (m, 0));
        for(int i = 0; i < m; i ++) {
            if(matrix[0][i] == 1) dp[0][i] = 1;
        }
        for(int i = 0; i < n; i ++) {
            if(matrix[i][0] == 1) dp[i][0] = 1;
        }
        int ans = 0;
        for(int i = 1; i < n; i ++) {
            for(int j = 1; j < m; j ++) {
                if(matrix[i][j] == 0) dp[i][j] = 0;
                else dp[i][j] = 1 + min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1]));
            }
        }
        for(int i = 0; i < n; i ++) {
            for(int j = 0; j < m; j ++) {
                ans += dp[i][j];
            }
        }
        return ans;
    }
};