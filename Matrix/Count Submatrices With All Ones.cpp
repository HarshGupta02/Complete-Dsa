/*
so we basically consider each point as the top left point of a possible 
submatrice and then for each point we iterate over all possible heights and 
for each height we find the min of max number of consecutive ones in the 
particular row and add to our ans.

we can precompute the number of consecutive ones on the right and use it 
directly.

*/

class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> a(n, vector<int> (m, 0));
        for(int i = 0; i < n; i ++) {
            int cnt = 0;
            for(int j = m - 1; j >= 0; j --) {
                if(mat[i][j] == 1) cnt ++;
                else cnt = 0;
                a[i][j] = cnt;
            }
        }
        int ans = 0;
        for(int i = 0; i < n; i ++) {
            for(int j = 0; j < m; j ++) {
                int ones = INT_MAX;
                for(int ph = i; ph < n; ph ++) {
                    ones = min(ones, a[ph][j]);
                    ans += ones;
                }
            }
        }
        return ans;
    }
};