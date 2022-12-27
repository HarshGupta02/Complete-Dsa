class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        vector<int>prefix(n + 1, 0);
        for(int i = 1; i <= n ; i ++){
            if(nums[i - 1] == 1) prefix[i] = prefix[i - 1] + 1;
            else prefix[i] = prefix[i - 1];
        }
        int i = 1, j = 1;
        int ans = 0;
        while(i <= n and j <= n){
            if(prefix[j] - prefix[i - 1] < goal){
                j ++;
            }else if(prefix[j] - prefix[i - 1] == goal){
                ans ++; j ++;
            }else i ++;
        }
        return ans;
    }
};