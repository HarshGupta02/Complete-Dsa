/*

here we know that we cannot include both the first and the last element
together so if we select first element so we not select last element and 
vice versa. not selecting both is not greedily good because we can include
either of them to increase the profit.

*/

class Solution {
public:
    
    int f(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        vector<int>dp(n);
        dp[0] = nums[0]; dp[1] = max(nums[0], nums[1]);
        for(int i = 2; i < n ; i ++){
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }
        return dp[n - 1];
    }
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        vector<int>temp1, temp2, temp3;
        for(int i = 0; i < n - 1; i ++) temp1.push_back(nums[i]);
        for(int i = 1; i < n; i ++) temp2.push_back(nums[i]);
        return max(f(temp1), f(temp2));
    }
};