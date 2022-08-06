class Solution {
public:
    
    void f(int i, int n, int target, vector<int>& candidates, vector<int> &temp, vector<vector<int>> &ans){
        if(target < 0 or i == n) return;
        if(target == 0){
            ans.push_back(temp);
            return;
        }
        temp.push_back(candidates[i]);
        f(i, n, target - candidates[i], candidates, temp, ans);
        temp.pop_back();
        f(i + 1, n, target, candidates, temp, ans);
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        int i = 0;
        vector<vector<int>>ans;
        vector<int>temp;
        f(i, n, target, candidates, temp, ans);
        return ans;
    }
};