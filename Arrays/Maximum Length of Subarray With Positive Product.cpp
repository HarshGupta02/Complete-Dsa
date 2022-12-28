/*
so here we see that if number of negatives are even so ans is size of the array.
if not then we consider all subarrays between 2 consecutive zeros and then for each 
subarray, we find the first the negative and the last negative and we just remove 
either the left part from the first negative or remove the right part from the last
negative and hence we get even number of negatives and we take the whole array as the 
answer.
*/

class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int n = nums.size();
        int i = 0, ans = 0;
        while(i < n){
            int left = i;
            while(left < n and nums[left] == 0) left ++;
            // so now left points to the start of a potential array
            // and right points to the end of a potential array at a 0 value
            
            // [[left1....right1][left2......right2][left3......right3]...]
            int right = left, negative = 0, first_neg = -1, last_neg = -1;
            while(right < n and nums[right] != 0){
                if(nums[right] < 0) {
                    negative ++;
                    if(first_neg == -1) first_neg = right;
                    last_neg = right;
                }
                right ++;
            }
            // now within each subarray from left to right, we have a first negative and 
            // a last negative
            if(negative % 2 == 0) ans = max(ans, right - left);
            else{
                // here we remove the left part of 1st negative as now number of negatives
                // becomes even.
                if(first_neg != -1) ans = max(ans, right - first_neg - 1);
                
                // here we remove the right part of last negative as now number of negatives
                // becomes even
                if(last_neg != -1) ans = max(ans, last_neg - left);
            }
            i = right + 1;
        }
        return ans;
    }
};