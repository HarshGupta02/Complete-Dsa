/*

here for each word , we decide whether we can place the word in the current line or in the 
new line . if number of spaces left < arr[i] , then we have to insert the word to new line
else in the same line only. if we insert in new line , then we have to include the cost of
extra spaces in the prev line , otherwise not.

dp[i][j] = tells the cost of including the i'th word with j spaces left.

*/


class Solution {
public:
    int dp[505][2005];
    int f(vector<int>nums, int n , int rem , int i , int k){
        if(i == n) return 0;
        if(dp[i][rem] != -1) return dp[i][rem];
        int ans;
        if(nums[i] > rem){
            ans = (rem + 1) * (rem + 1) + f(nums , n , k - nums[i] - 1 , i + 1 , k);
        }else{
            int a = (rem + 1) * (rem + 1) + f(nums , n , k - nums[i] - 1 , i + 1 , k);
            int b = f(nums , n , rem - nums[i] - 1 , i + 1 , k);
            ans = min(a , b);
        }
        return dp[i][rem] = ans;
    }

    int solveWordWrap(vector<int>nums, int k) 
    { 
        int n = nums.size();
        memset(dp, -1 , sizeof(dp));
        return f(nums,n,k,0,k);
    } 
};