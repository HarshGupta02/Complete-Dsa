// TIME = O(N), SPACE = O(2 * N)

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        if(n < 3) return 0;
        int ans = 0;
        vector<int>diff(n, INT_MAX), dp(n, 0);
        for(int i = n - 3; i >= 0; i --){
            if(nums[i + 1] - nums[i] != nums[i + 2] - nums[i + 1]) continue;
            dp[i] ++; diff[i] = nums[i + 1] - nums[i];
            if(diff[i] == diff[i + 1]) dp[i] += dp[i + 1];
        }
        for(int i = 0; i < n; i ++) ans += dp[i];
        return ans;
    }
};

// TIME = O(N), SPACE = O(N)

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        if(n < 3) return 0;
        vector<int>dp(n, 0);
        int ans = 0;
        for(int i = n - 3; i >= 0; i --){
            if(nums[i + 1] - nums[i] != nums[i + 2] - nums[i + 1]) continue;
            dp[i] = dp[i + 1] + 1;
            ans += dp[i];
        }
        return ans;
    }
};

// TIME = O(N), SPACE = O(1)

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        if(n < 3) return 0;
        int curr = 0, sum = 0;
        for(int i = n - 3; i >= 0; i --){
            if(nums[i + 1] - nums[i] != nums[i + 2] - nums[i + 1]) curr = 0;
            else curr ++; // so curr stores the number of arthmetic subarrays that start at nums[i]
            sum += curr;
        }
        return sum;
    }
};