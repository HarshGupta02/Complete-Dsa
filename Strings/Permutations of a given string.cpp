class Solution {
public:
    
    void f(int n,int i,vector<int>nums,vector<vector<int>>&ans){
        if(i == n){
            ans.push_back(nums);
            return;
        }
        for(int j=i;j<n;j++){
            if(i != j and nums[i] == nums[j]) continue;
            swap(nums[i],nums[j]);
            f(n,i+1,nums,ans);
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        f(n,0,nums,ans);
        return ans;
    }
};