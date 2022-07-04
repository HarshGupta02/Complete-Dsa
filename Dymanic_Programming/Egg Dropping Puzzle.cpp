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