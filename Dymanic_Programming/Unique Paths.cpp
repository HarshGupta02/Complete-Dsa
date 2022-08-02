class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int>curr(n),prev(n);
        for(int i = 0; i < n ; i ++) prev[i] = 1;
        for(int i = 1; i < m ; i ++){
            curr[0] = 1;
            for(int j = 1; j < n ; j ++){
                curr[j] = prev[j] + curr[j - 1];
            }
            prev = curr;
        }
        return prev[n - 1];
    }
};

// dp[i][j] = number of paths to reach (i,j) from 0,0.