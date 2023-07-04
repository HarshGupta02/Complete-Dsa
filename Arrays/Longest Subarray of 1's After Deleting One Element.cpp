class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = 0;
        int ans = 0, cnt = 0;
        while(i < n and j < n) {
            if(nums[i] == 0) cnt ++;
            while(cnt > 1) {
                if(nums[j] == 0) cnt --;
                j ++;
            }
            ans = max(ans, (i - j) + 1);
            i ++;
        }
        return ans - 1;
    }
};