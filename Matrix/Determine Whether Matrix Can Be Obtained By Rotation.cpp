class Solution {
public:
    
    vector<vector<int>> rotate_once(vector<vector<int>> &matrix){
        int n = matrix.size();
        for(int i = 0; i < n; i ++){
            for(int j = i; j < n; j ++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        for(int i = 0; i < n; i ++){
            reverse(matrix[i].begin(), matrix[i].end());
        }
        return matrix;
    }
    
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        for(int i = 0; i < 4; i ++){
            mat = rotate_once(mat);
            if(mat == target) return true;
        }
        return false;
    }
};