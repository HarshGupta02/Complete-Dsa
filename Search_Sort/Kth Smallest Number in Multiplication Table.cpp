/*
here we try to find all possible values of the kth smallest element and a number will be a 
candidate if there are atleast k numbers <= mid and these we find these numbers in each row.
*/

class Solution {
public:
    
    bool check(int mid, int k, int m, int n){
        int cnt = 0;
        for(int row = 1; row <= m; row ++){
            cnt += min(n, mid/row);// include only those numbers which are in the matrix.
        }
        if(cnt >= k) return true;
        return false;
        
    }
    
    int findKthNumber(int m, int n, int k) {
        if(m >= n) swap(m, n);
        int low = 1, high = m * n;
        int ans = 0;
        while(low <= high){
            int mid = low + (high - low)/2;
            // check if there are k elements <= mid.
            if(check(mid, k, m, n)){
                ans = mid;
                high = mid - 1;
            }else low = mid + 1;
        }
        return ans;
    }
};