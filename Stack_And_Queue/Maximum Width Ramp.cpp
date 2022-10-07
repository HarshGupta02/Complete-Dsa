// METHOD 1 : TIME = O(N * LOG N), SPACE = O(N)

class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();
        vector<int>min_prefix(n), max_suffix(n);
        min_prefix[0] = nums[0], max_suffix[n - 1] = nums[n - 1];
        for(int i = 1; i < n; i ++){
            min_prefix[i] = min(min_prefix[i - 1], nums[i]);
            max_suffix[n - i - 1] = max(max_suffix[n - i], nums[n - i - 1]);
        }
        reverse(max_suffix.begin(), max_suffix.end());
        int nax = 0;
        for(int i = 0; i < n; i ++){
            int x = min_prefix[i];
            auto it = lower_bound(max_suffix.begin(), max_suffix.end(), x);
            if(it == max_suffix.end()) return 0;
            int idx = it - max_suffix.begin();
            nax = max(nax, (n - idx - 1) - i);
        }
        return nax;
    }
};


// METHOD 2 : TIME = O(N), SPACE = O(N)

/*
here first we insert all elements in decreasing order in a stack. then we iterate the 
array from the back and we keep on removing elements from the stack until the element at
top is lesser than curr element and keep on updating ans. and so we never have to refill
the stack because it gurantees that the elements that are removed will never contribute
to the ans with elements less than curr elements.

*/

class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();
        stack<int>stk;
        for(int i = 0; i < n; i ++){
            if(stk.empty() or nums[stk.top()] > nums[i]) stk.push(i);
        }
        int nax = 0;
        for(int i = n - 1; i >= 0; i --){
            while(!stk.empty() and nums[i] >= nums[stk.top()]) {
                nax = max(nax, i - stk.top());
                stk.pop();
            }
        }
        return nax;
    }
};