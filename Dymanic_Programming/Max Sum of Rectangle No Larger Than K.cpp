// TIME = O(COLS * COLS * (ROWS + ROWS * LOG ROWS)) ~ O(COLS * ROWS * ROWS * LOG ROWS)
/*

HERE WE FIRST CONSIDER A SEARCH SPACE BETWEEN 2 COLUMNS AND THEN FOR EACH SEARCH SPACE
WE FIND THE SUM OF ALL CORRESSPONDING ROWS AND THEN APPLY KIND OF KADANE'S ALGO ON THE 
SUMS VECTOR.

*/

class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int rows = matrix.size(), cols = matrix[0].size(), ans = INT_MIN;
        for(int left = 0; left < cols; left ++){
            vector<int>sums(rows, 0);
            for(int right = left; right < cols; right ++){
                for(int i = 0; i < rows; i ++){
                    sums[i] += matrix[i][right];
                }
                // we have considered a vertical section of the matrix.
                // not we consider the horizontal section of the matrix.
                set<int>s;
                s.insert(0); // WHY ??
                int prefix_sum = 0, maxi = INT_MIN;
                for(auto it : sums){
                    prefix_sum += it;
                    auto p = s.lower_bound(prefix_sum - k);
                    if(p != s.end()) maxi = max(maxi, prefix_sum - *p);
                    s.insert(prefix_sum);
                }
                ans = max(ans, maxi);
            }
        }
        return ans;
    }
};