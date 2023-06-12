/*
to rotate right, we see that each column is being  converted to a row and vice versa 
and so we first take the transpose of the given matrix and then we reverse each row.

to rotate left, first do reversing each row then do transpose

*/

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n =  matrix.size();
        // transpose
        for(int i = 0; i < n; i ++){
            for(int j = i; j < n; j ++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        // reverse each row of the transposed matrix
        for(int i = 0; i < n; i ++){
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};