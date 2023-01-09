// METHOD 1:

class Solution {
public:
    using ll = long long int;
    vector<vector<ll>> dp;
    
    ll f(int i, int to_take, int n, vector<int> &nums){
        if(i >= n) return 0;
        if(dp[i][to_take] != -1) return dp[i][to_take];
        if(to_take == 0) return dp[i][to_take] = max(nums[i] + f(i + 1, 1, n, nums), f(i + 1, 0, n, nums));
        return dp[i][to_take] = max(f(i + 1, 1, n, nums), f(i + 1, 0, n, nums) - nums[i]);
    }
    
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        int to_take = 0; // if to_take = 0 so take even value else take odd value
        dp.resize(n, vector<ll> (2, -1));
        return f(0, to_take, n, nums);
    }
};

/*

alternating sum = (sum at even index) - (sum at odd index)

[6,2,1,2,4,5] => so we try to maximize the elements at even index
and minimise the elements at odd index

[4,2,5,3] => 

so first mark the indexes with max and min element and then if
the min lies on left so go left else go right.

=> so we either not take the odd index element and if we take it
then we will be forced to take an even index element.

=> let's take sufffix max and suffix min

=>              [6,2,1,2,4,5]
=> suffix max = [6,5,5,5,5,5]
=> suffix min = [1,1,1,2,4,5]

*/

// METHOD 2:

class Solution {
public:
    using ll = long long int;
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        ll odd_sum = 0, even_sum = 0; // odd_sum means that last element picked was an odd index element in the subsequence
        for(int i = 0; i < n; i ++){
            ll odd_temp = max(odd_sum, even_sum - nums[i]);
            ll even_temp = max(even_sum, odd_sum + nums[i]);
            even_sum = even_temp;
            odd_sum = odd_temp;
        }
        return max(odd_sum, even_sum);
    }
};