/*
here we are visiting each node atmax 2 times only so time = O(2*N) ~ O(N).

*/

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        int prod = 1, left = 0, right = 0, ans = 0;
        while(left < n and right < n){
            if(nums[right] >= k){
                // here we have a fresh start so reset all
                prod = 1;
                right ++; left = right; continue;
            }
            prod *= nums[right];
            if(prod < k){
                ans += (right - left) + 1;
                right ++;
            }else{
                prod /= nums[left];
                // so that the nums[right] is not multiplied
                // twice.
                prod /= nums[right]; 
                left ++;
            }
        }
        return ans;
    }
};