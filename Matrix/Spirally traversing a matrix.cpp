class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        vector<int>ans;
        int dir = 0;
        // 0 -> left to right, 1 -> top to down
        // 2 -> right to left, 3 -> down to top
        int top = 0, down = r - 1 , left = 0 , right = c - 1;
        while(top <= down and left <= right){
            if(dir == 0){
                for(int j = left; j <= right; j ++){
                    ans.push_back(matrix[top][j]);
                }
                top ++;
            }else if(dir == 1){
                for(int j = top ; j <= down; j ++){
                    ans.push_back(matrix[j][right]);
                }
                right --;
            }else if(dir == 2){
                for(int j = right; j >= left; j --){
                    ans.push_back(matrix[down][j]);
                }
                down --;
            }else{
                for(int j = down; j >= top ; j --){
                    ans.push_back(matrix[j][left]);
                }
                left ++;
            }
            dir = (dir + 1) % 4;
        }
        return ans;
    }
};