class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>ans;
        ans.push_back(nums[0]);
        for(int i = 1; i < nums.size(); i ++){
            while(!ans.empty() and ans.back() > nums[i] and ans.size() - 1 + (n - i) >= k) ans.pop_back();
            ans.push_back(nums[i]);
        }
        vector<int>v;
        for(int i = 0; i < k; i ++) v.push_back(ans[i]);
        return v;
    }
};