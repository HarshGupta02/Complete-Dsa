// METHOD 1:

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        for(int i = 1; i < n - 1; i ++){
            int p = nums[i - 1] + nums[i + 1];
            if(p % 2 == 0 and p/2 == nums[i]) swap(nums[i], nums[i + 1]);
        }
        for(int i = n - 2; i >= 1; i --){
            int p = nums[i - 1] + nums[i + 1];
            if(p % 2 == 0 and p/2 == nums[i]) swap(nums[i - 1], nums[i]);
        }
        return nums;
    }
};

// METHOD 2:

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        int dir = nums[0] < nums[1];
        // dir = 1 => increasing
        // dir = 0 => decreasing
        for(int i = 1; i < n - 1; i ++){
            if((dir == 1 and nums[i] < nums[i + 1]) or (dir == 0 and nums[i] > nums[i + 1])) swap(nums[i], nums[i + 1]);
            dir = 1 - dir;
        }
        return nums;
    }
};

/// so to avoid the average condition, we have to create a zig zag structure
// either first increase then decrease or vice versa.