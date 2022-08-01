/// METHOD 1: TIME = O(N * K * K) , SPACE = O(N * K)

/*

HERE SELECTING A FLOOR IS IN OUR HAND SO WE SELECT THAT FLOOR THAT GIVES MIN ATTEMPTS BUT EGG
BREAKING OR NOT IS A LUCK AND SO WE ASSUME OUR LUCK TO BE WORST AND SO WE TAKE MAX OF 
1. EGG BREAKS , 2 . EGG SURVIVES.

DP[I][J] = MIN ATTEMPTS TO FIND THE FLOOR IF WE HAVE I EGGS AND J FLOORS.

DP[I][J] = 1 + DP[I - 1][J - 1] , 1 + DP[I][K - J] ....


*/

class Solution
{
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    int eggDrop(int n, int k) 
    {
        vector<vector<int>>dp(n + 1 , vector<int>(k + 1));
        for(int i = 1 ;i <= n ; i ++){
            for(int j = 1; j <= k ; j ++){
                if(i == 1){
                    dp[i][j] = j; continue;
                }
                if(j == 1){
                    dp[i][j] = 1; continue;
                }
                int mini = INT_MAX;
                for(int x = 0 , y = j - 1; y >= 0 ; y -- , x ++){
                    mini = min(mini , max(dp[i - 1][x] , dp[i][y]));
                }
                dp[i][j] = mini + 1;
            }
        }
        return dp[n][k];
    }
};


/// METHOD 2: SPACE OPTIMISED , TIME = O(N * K * K) , SPACE = O(2 * K) ~ O(K).

class Solution
{
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    int eggDrop(int n, int k) 
    {
        vector<int>prev(k + 1) , curr(k + 1);
        for(int i = 0; i <= k ; i ++) prev[i] = i;
        for(int i = 2 ;i <= n ; i ++){
            for(int j = 2; j <= k ; j ++){
                curr[1] = 1;
                int mini = INT_MAX;
                for(int x = 0 , y = j - 1; y >= 0 ; y -- , x ++){
                    mini = min(mini , max(prev[x] , curr[y]));
                }
                curr[j] = mini + 1;
            }
            prev = curr;
        }
        return prev[k];
    }
};

// METHOD 3: TIME = O(K * N* LOGN) , SPACE = O(N * K)

/*
IF WE HAVE I EGGS AND J FLOORS THEN WE DON'T NEED TO CHECK FOR EACH I FLOOR FROM
1 TO J BECAUSE AS FLOORS INCREASES , THE NUMBER OF MOVES IN THE WORST CASE
ALSO INCREASES.
*/

// k = number of eggs, n = number of floors.

class Solution {
public:
    int superEggDrop(int k, int n) {
        if(k == 1) return n;
        if(n == 1) return 1;
        vector<vector<int>>dp(k + 1, vector<int>(n + 1,0));
        for(int i = 0; i <= k ;i ++){
            dp[i][0] = 0;
            dp[i][1] = 1;
        }
        for(int i = 0; i<= n; i ++){
            dp[0][i] = 0;
            dp[1][i] = i;
        }
        for(int i = 2; i <= k; i ++){
            for(int j = 2; j <= n ; j ++){
                int low = 1, high = j, temp = 0, ans = INT_MAX;
                while(low <= high){
                    int mid = low + (high - low)/2;
                    int left = dp[i - 1][mid - 1];
                    int right = dp[i][j - mid];
                    temp = 1 + max(left,right);
                    if(left < right) low = mid + 1;
                    else high = mid - 1;
                    ans = min(ans,temp);
                }
                dp[i][j] = ans;
            }
        }
        return dp[k][n];
    }
};