class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& a) {
        int m = a.size(), n = a[0].size();
        if(a[0][0] == 1 or a[m - 1][n - 1] == 1) return 0;
        vector<int>prev(n), curr(n);
        prev[0] = 1; curr[0] = 1;
        for(int i = 1; i < n ; i ++) prev[i] = (a[0][i] == 1) ? 0 : prev[i - 1];
        for(int i = 1; i < m ; i ++){
            curr[0] = (a[i][0] == 1) ? 0 : prev[0];
            for(int j = 1; j < n ; j ++){
                if(a[i][j] == 1) curr[j] = 0;
                else curr[j] = prev[j] + curr[j - 1];
            }
            prev = curr;
        }
        return prev[n - 1];
    }
};