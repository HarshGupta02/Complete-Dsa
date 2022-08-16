class Solution {
public:
    using ll = long long int;
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = 0;
        ll sum = 0, ans = INT_MAX;
        while(i < n and j < n){
            sum += nums[j];
            if(sum < target){
                j ++;
            }else{
                while(sum >= target and i < n){
                    ans = min(ans, 1ll * (j - i + 1));
                    sum -= nums[i];
                    i ++;
                }
                j ++;
            }
        }
        return ans == INT_MAX ? 0 : ans;
    }
};

/*

greedy => 2 - pointer (since all are positive)
min size => 1. bfs, 2. dp, 3. binary search

7
[2,3,1,2,4,3]

*/