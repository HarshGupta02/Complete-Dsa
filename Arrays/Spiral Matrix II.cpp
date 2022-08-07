class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int num = 1;
        vector<vector<int>>a(n, vector<int>(n));
        int top = 0, down = n - 1, left = 0, right = n - 1;
        int dir = 0;
        while(top <= down and left <= right){
            if(dir == 0){
                for(int i = left; i <= right; i ++) a[top][i] = (num ++);
                top ++;
            }else if(dir == 1){
                for(int i = top; i <= down; i ++) a[i][right] = (num ++);
                right --;
            }else if(dir == 2){
                for(int i = right; i >= left; i --) a[down][i] = (num ++);
                down --;
            }else{
                for(int i = down; i >= top; i --) a[i][left] = (num ++);
                left ++;
            }
            dir = (dir + 1) % 4;
        }
        return a;
    }
};