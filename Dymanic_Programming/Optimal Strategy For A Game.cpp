/*
in their own chance , the player tries to max their score and when it is in opponents hand , then 
we should expect the worst score because he plays optimally so he tries to min our score .

[i......j] =
if choose i

dp[i][j] = max( arr[i] + min(dp[i + 2][j] , dp[i + 1][j - 1]) ,
                arr[j] + min(dp[i + 1][j - 1] , dp[i][j - 2]);

*/


class Solution{
    public:
    using ll = long long int;
    long long maximumAmount(int arr[], int n){
        vector<vector<int>>dp(n,vector<int>(n,0));
        for(int gap = 0 ; gap < n ; gap ++){
            for(int i = 0 , j = gap ; j < n ; i ++ , j ++){
                if(gap == 0){
                    dp[i][j] = arr[i]; 
                    continue;
                }
                if(gap == 1){
                    dp[i][j] = max(arr[i] , arr[j]);
                    continue;
                }
                dp[i][j] = max((arr[i] + min(dp[i + 2][j] , dp[i + 1][j - 1])) , (arr[j] + min(dp[i + 1][j - 1], dp[i][j - 2])));
            }
        }
        return dp[0][n - 1];
    }
};