// TIME = O(M + N + M * N + M * N + M * N + N + M) ~ O(M * N), SPACE = O(1)

/*
here instead of declaring two arrays for 0th row and 0th col, we used the first row and 
the first col as those arrays and saved the space and then checked for original zeros in 
the first row and the first col before hand.
*/

class Solution {
public:
    void setZeroes(vector<vector<int>>& a) {
        int m = a.size(), n = a[0].size();
        bool present_row = false, present_col = false;
        /// this variables assume that there is no zero at the first row and the first column.
        for(int i = 0; i < m; i ++){
            if(a[i][0] == 0){
                present_col = true; break;
            }
        }
        for(int i = 0; i < n; i ++){
            if(a[0][i] == 0){
                present_row = true; break;
            }
        }
        /// marked the rows and cols with zeros for submatrix a((m - 1) * (n - 1)).
        for(int i = 1; i < m; i ++){
            for(int j = 1; j < n; j ++){
                if(a[i][j] == 0) {
                    a[0][j] = a[i][0] = 0;
                }
            }
        }
        // marked all corresponding rows and cols with values as 0 for first row and first col.
        for(int i = 1; i < m; i ++) if(a[i][0] == 0) for(int j = 0; j < n; j ++) a[i][j] = 0;
        for(int i = 1; i < n; i ++) if(a[0][i] == 0) for(int j = 0; j < m; j ++) a[j][i] = 0;
        // check if need to make first row and first col as 0
        if(present_row) for(int i = 0; i < n ; i ++) a[0][i] = 0;
        if(present_col) for(int i = 0; i < m; i ++) a[i][0] = 0;
    }
};