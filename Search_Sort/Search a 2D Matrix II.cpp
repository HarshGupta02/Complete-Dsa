// TIME = O(N + M), SPACE = O(1)

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();
        int r = 0, c = m - 1;
        while(r >= 0 and r < n and c >= 0 and c < m){
            if(matrix[r][c] == target) return true;
            if(matrix[r][c] > target) c--;
            else r ++;
        }
        return false;
    }
};

// so we start to search from the top right element because that element will be
// largest element in the first row and smallest element in the last column.