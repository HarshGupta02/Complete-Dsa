class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size();
        multiset<int> st;
        int i = 0, j = 0;
        int ans = 1;
        while(i < n and j < n) {
            st.insert(nums[j]);
            while(i < j and !st.empty() and *st.rbegin() - *st.begin() > limit) {
                st.erase(st.find(nums[i]));
                i ++;
            }
            ans = max(ans, (j - i) + 1);
            j ++;
        }
        return ans;
    }
};