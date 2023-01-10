class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& nums) {
        int n = nums.size();
        if(is_sorted(nums.begin(), nums.end())) return nums;
        int idx1, idx2 = -1;
        for(int i = n - 2; i >= 0; i --){
            if(nums[i] > nums[i + 1]) {
                idx1 = i;
                break;
            }
        }
        for(int i = idx1 + 1; i < n; i ++){
            if(nums[i] < nums[idx1]) {
                if(idx2 == -1) idx2 = i;
                else if(nums[i] > nums[idx2]) idx2 = i;
            }
            else break;
        }
        swap(nums[idx1], nums[idx2]);
        return nums;
    }
};