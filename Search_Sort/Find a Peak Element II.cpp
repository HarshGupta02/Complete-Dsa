/*
so here we basically try to see the whole 2d grid from below the grid horizontally. we will see the 
peaks that are highest within each column and then if we apply the same peak element 1 login on these
peaks so the peak which is higher than the left and right peaks is the highest peak.

so we apply binary search on columns and consider a middle column and then find the max peak in that
mid column for a row say "max-row".  so we now know a column and a row. now we just check if it is
bigger that the peaks on the left and right. (we have ensured that it is maximum in that col).

if anyone is bigger on the left or right so go on that side(same logic as that of peak element 1).

*/

class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        int start_col = 0, end_col = m - 1;
        while(start_col <= end_col) {
            int mid_col = start_col + (end_col - start_col)/2;
            int max_row = 0;
            for(int row = 0; row < n; row ++) {
                if(mat[row][mid_col] > mat[max_row][mid_col]) max_row = row;
            }
            int isLeftBig = (mid_col - 1 >= 0 and mat[max_row][mid_col - 1] > mat[max_row][mid_col]) ? 1 : 0;
            int isRightBig = (mid_col + 1 < m and mat[max_row][mid_col + 1] > mat[max_row][mid_col]) ? 1 : 0;
            if(!isLeftBig and !isRightBig) return {max_row, mid_col};
            if(isRightBig) start_col = mid_col + 1;
            else end_col = mid_col - 1;
        }
        return {-1, -1};
    }
};