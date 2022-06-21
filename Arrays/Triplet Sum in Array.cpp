/// TIME = O(N^2 + NLOGN) ~~ O(N^2) , SPACE = O(1).

class Solution{
    public:
    bool find3Numbers(int A[], int n, int X)
    {
        sort(A , A + n);
        for(int i = 0; i < n - 1; i ++){
            int to_find = X - A[i];
            int left = i + 1 , right = n - 1;
            while(left < right){
                int curr_sum = A[left] + A[right];
                if(curr_sum == to_find) return true;
                if(curr_sum < to_find) left ++;
                else right --;
            }
        }
        return false;
    }

};