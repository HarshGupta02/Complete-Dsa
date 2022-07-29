class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();
        int low = 0, high = n - 1;
        bool found = false;
        int needed;
        while(low <= high){
            int mid = low + (high - low)/2;
            int leftist = matrix[mid][0] , rightist = matrix[mid][m - 1];
            if(target < leftist){
                high = mid - 1;
            }else if(target > rightist){
                low = mid + 1;
            }else{
                needed = mid;
                found = true; break;
            }
        }
        if(!found) return false;
        low = 0, high = m - 1;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(matrix[needed][mid] == target) return true;
            if(matrix[needed][mid] < target) low = mid + 1;
            else high = mid - 1;
        }
        return false;
    }
};