// TIME = O(N), SPACE = O(N)

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        stack<int>stk;
        vector<int>ans(n,-1);
        for(int i = 0; i < n; i ++){
            if(stk.empty() or nums[stk.top()] > nums[i]) stk.push(i);
            else{
                while(!stk.empty() and nums[stk.top()] < nums[i]){
                    ans[stk.top()] = nums[i];
                    stk.pop();
                }
                stk.push(i);
            }
        }
        for(int i = 0; i < n; i ++){
            if(!stk.empty() and nums[stk.top()] > nums[i]) continue;
            while(!stk.empty() and nums[stk.top()] < nums[i]){
                ans[stk.top()] = nums[i];
                stk.pop();
            }
        }
        return ans;
    }
};