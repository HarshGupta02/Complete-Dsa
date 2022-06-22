class Solution
{
    public:
    int FindMaxSum(int arr[], int n)
    {
        if(n == 1) return arr[0];
        if(n == 2) retusrn max(arr[0] , arr[1]);
        vector<int>dp(n);
        dp[0] = arr[0]; dp[1] = max(arr[0] , arr[1]);
        for(int i = 2; i < n ; i ++){
            dp[i] = max(dp[i - 2] + arr[i] , dp[i - 1]);
        }
        return dp[n - 1];
    }
};


// 1. either not loot this house.
// 2. try to loot but previous one was looted.
// 3. safe to loot.

// choose , cannot loot , not choose to loot , choose , cannot loot , choose 

// 3,2,1,3,2,3

//      5,5,10,100,10,5
     
// dp : 5,5,15,105,105,110
// dp[i] = max profit that can be made if i loot the ith house

// dp[i] = max(dp[i - 2] + a[i] , dp[i - 1]).