class Solution {
public:
	vector<int> DistinctSum(vector<int>nums){
	    int n = nums.size();
	    int sum = 0;
	    for(auto it : nums) sum += it;
	    vector<vector<bool>>dp(n + 1, vector<bool>(sum + 1, false));
	    for(int i = 0; i <= n; i ++) dp[i][0] = true;
	    for(int i = 1; i <= n; i ++){
	        for(int j = 1; j <= sum; j ++){
	            if(nums[i - 1] > j) dp[i][j] = dp[i - 1][j];
	            else dp[i][j] = dp[i - 1][j] | dp[i - 1][j - nums[i - 1]];
	        }
	    }
	    vector<int>ans;
	    for(int i = 0; i <= sum; i ++){
	        if(dp[n][i] == true) ans.push_back(i);
	    }
	    return ans;
	}
};

// dp[i][j] = true if we can make a sum of j by either including or not including the ith element else false;