class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int curr = 0;
        for(int i = 0; i < n ; i ++){
            if(nums[i] == 0) curr ++;
            else{
                swap(nums[i], nums[i - curr]);
            }
        }`
    }
};