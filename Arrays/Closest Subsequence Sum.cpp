/*
this question uses meet in the middle concept. here we cannot generate all subsets 
as it would generate 2^40 subsets. so we divide array into 2 equal half and find
all subsets sum of both the half (2^20 subsets ~ 10^6 subsets of each half).

then we sort the second half and for each element in first half, find the subset
sum that is closest to goal - first_half sum and keep on taking the minimum 
answer.

*/

class Solution {
public:
    
    vector<int> go(int start, int end, int offset, vector<int> &nums) {
        int n = end - start + 1;
        vector<int> ans;
        for(int i = 0; i < (1 << n); i ++) {
            int sum = 0;
            for(int j = 0; j < n; j ++) {
                if(i & (1 << j)) sum += nums[j + offset];
            }
            ans.push_back(sum);
        }
        return ans;
    }
    
    int minAbsDifference(vector<int>& nums, int goal) {
        int n = nums.size();
        vector<int> fh = go(0, n/2 - 1, 0, nums);
        vector<int> sh = go(n/2, n - 1, n/2, nums);
        sort(sh.begin(), sh.end());
        int ans = INT_MAX;
        for(int i = 0; i < fh.size(); i ++) {
            int idx = lower_bound(sh.begin(), sh.end(), goal - fh[i]) - sh.begin();
            if(idx > 0) ans = min(ans, abs(goal - fh[i] - sh[idx - 1]));
            if(idx < sh.size()) ans = min(ans, abs(goal - fh[i] - sh[idx]));
            if(idx + 1 < sh.size()) ans = min(ans, abs(goal - fh[i] - sh[idx + 1]));
        }
        return ans;
    }
};