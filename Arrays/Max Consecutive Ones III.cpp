/*
so here we keep on picking elements until we have picked > k zeros. if so then we move our left
pointer and release zeros until count > k. and when cnt <= k, then keep on moving the right
pointer.
*/

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0, j = 0;
        int ans = 0, cnt = 0;
        while(i < n and j < n) {
            if(nums[i] == 0) cnt ++;
            while(cnt > k) {
                if(nums[j] == 0) cnt --;
                j ++;
            }
            ans = max(ans, (i - j) + 1);
            i ++;
        }
        return ans;
    }
};