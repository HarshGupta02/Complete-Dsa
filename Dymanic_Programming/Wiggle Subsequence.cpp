class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return 1;
        if(n == 2){
            if(nums[0] == nums[1]) return 1;
            return 2;
        }
        int ans = 0;
        int prev = -1; /// prev = 0 -> last op was negative,
        // prev = 1 -> last op was positive
        
        for(int i = 0; i + 1 < n; i ++){
            if(prev == 1 and nums[i] > nums[i + 1]){
                prev = 0; ans ++; continue;
            }
            if(prev == 0 and nums[i] < nums[i + 1]){
                prev = 1; ans ++; continue;
            }
            if(prev == -1 and nums[i] > nums[i + 1]){
                prev = 0; ans ++; continue;
            }
            if(prev == -1 and nums[i] < nums[i + 1]){
                prev = 1; ans ++; continue;
            }
        }
        return ans + 1;
    }
};

/*
always try to takes peaks or valleys only and not the elements between them.


*/