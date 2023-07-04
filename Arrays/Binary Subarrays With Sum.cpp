// METHOD1:

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

// METHOD 2: COUNT NO OF SUBARRAY WITH SUM K

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        unordered_map<int, int> mp;
        mp[0] = 1;
        int sum = 0, ans = 0;
        for(int i = 0; i < n; i ++) {
            sum += nums[i];
            if(mp.find(sum - goal) != mp.end()) ans += mp[sum - goal];
            mp[sum] ++;
        }
        return ans;
    }
};

// METHOD 3:

/*
in this method, to find no of subarray with sum k, we find no of subarray with sum atmost k 
minus the no of subarray with sum atmost k - 1. the result is no of subarray with sum exactly
k. 
for atmost k as sum, if sum < goal so we add all the no of new subarray that the head comes
at the end.
*/

class Solution {
public:
    
    int atMost(int n, vector<int> &nums, int goal) {
        if(goal < 0) return 0;
        int sum = 0, ans = 0;
        int i = 0, j = 0;
        while(i < n and j < n) {
            sum += nums[j];
            while(sum > goal) {
                sum -= nums[i];
                i ++;
            }
            ans += (j - i) + 1;
            j ++;
        }
        return ans;
    }
    
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        return atMost(n, nums, goal) - atMost(n, nums, goal - 1);
    }
};