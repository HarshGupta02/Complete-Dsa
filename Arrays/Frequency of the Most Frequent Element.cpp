/*
so here we try to make the elements equal to the elements that are already present
in the array so as to minimize the number of operations. and we sort the array so
that we can apply operations on elements smaller than a[i] to make them a[i].

so for a window range of [l....r], we check if we can make all elements equal to 
nums[r] if nums[r] * (window_len) <= (window_sum) + k.

if not possible so we cannot expand the window. (proof known) so decrement l and 
then check again.

*/

class Solution {
public:
    using ll = long long int;
    int maxFrequency(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int i = 0, j = 0;
        ll curr = 0, ans = 0;
        while(i < n and j < n) {
            curr += nums[j];
            while(i <= j and (ll)nums[j] * ((ll)j - i + 1) > ((ll)curr + k)) {
                curr -= nums[i]; i ++;
            }
            ans = max(ans, ((ll)j - i + 1));
            j ++;
        }
        return ans;
    }
};