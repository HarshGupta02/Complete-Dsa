// METHOD 1:

class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int ans = 0;
        for(int i = 0; i < n; i ++){
            auto it = upper_bound(nums.begin() + i, nums.end(), nums[i] + k);
            it --;
            if(it != nums.end()){
                ans ++;
                i = it - nums.begin();
            }
        }
        return ans;
    }
};

// METHOD 2:

class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int ans = 1, mini = nums[0], maxi = nums[0];
        for(int i = 0; i < n; i ++){
            mini = min(mini, nums[i]);
            maxi = max(maxi, nums[i]);
            if(maxi - mini > k){
                ans ++;
                mini = nums[i];
                maxi = nums[i];
            }
        }
        return ans;
    }
};