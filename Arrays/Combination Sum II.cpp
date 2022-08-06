// TIME = O(2 ^ N) IN CASE OF ALL UNIQUE ELEMENTS, SPACE = O(K * X) WHERE 
// K = AVERAGE LENGTH OF TEMP AT ANY INSTANCE AND X = NUMBER OF COMBINATIONS.

/*
HERE THE APPROACH IS THAT WE ARE CONSIDERING ALL POSSIBLE CANDIDATES FOR THE ITH POSITION 
AND FOR EACH POS, WE CHECK FOR IT'S NEXT POSITIONS ONLY ONCE AND IF THERE IS A DUPLICATE THEN
IT IS NOT CONSIDERED.
*/

class Solution {
public:
    
    void f(int i, int n, int target, vector<int> &candidates, vector<int> temp, vector<vector<int>> &ans){
        if(target == 0){
            ans.push_back(temp);
            return;
        }
        for(int idx = i; idx < n; idx ++){
            if(idx > i and candidates[idx] == candidates[idx - 1]) continue;
            if(candidates[idx] > target) break;
            temp.push_back(candidates[idx]);
            f(idx + 1, n, target - candidates[idx], candidates, temp, ans);
            temp.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int n = candidates.size();
        sort(candidates.begin(), candidates.end()); // n * logn
        vector<vector<int>>ans;
        vector<int>temp;
        int i = 0;
        f(i, n, target, candidates, temp, ans);
        return ans;
    }
};