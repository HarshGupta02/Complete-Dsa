// TIME = O(N * N), SPACE = O(N).

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int>dp(n, 1), hash(n);
        for(int i = 0; i < n ; i ++) hash[i] = i;
        for(int i = 1; i < n; i ++){
            for(int j = 0; j < i; j ++){
                if(nums[i] % nums[j] == 0 and dp[i] < dp[j] + 1){
                    dp[i] = dp[j] + 1;
                    hash[i] = j; /// stores the index of the last optimal element inserted.
                }
            }
        }
        // cout << *max_element(dp.begin(), dp.end()) << endl; 
        // to print the subset
        int last_index, maxi = -1;
        for(int i = 0; i < n; i ++){
            if(dp[i] > maxi) {
                last_index = i;
                maxi = dp[i];
            }
        }
        vector<int>ans; ans.push_back(nums[last_index]);
        while(last_index != hash[last_index]){
            last_index = hash[last_index];
            ans.push_back(nums[last_index]);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};