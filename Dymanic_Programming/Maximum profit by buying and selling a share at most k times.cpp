/// METHOD 1 : TIME = O(K * N * N) , SPACE = O(N * K)

/*
WE USED THE FACT THAT DP[I][J] = TELLS THE MAX PROFIT THAT CAN BE MADE IF WE PERFORM
AT MOST I TRANSACTIONS TILL J'TH DAY. IT CAN EITHER BE MAX OF 
1. I TRANSACTIONS PERFORMED ON J - 1 TH DAY
2. MAX OF ALL TRANSACTIONS PERFOMED ON 1 LESS TRANSACTIONS AND LESS THAN J'TH DAY.

*/

class Solution {
  public:
    int maxProfit(int K, int N, int A[]) {
        vector<vector<int>>dp(K + 1, vector<int>(N , 0));
        for(int i = 1; i <= K; i ++){
            for(int j = 1; j < N; j ++){
                int nax = dp[i][j - 1];
                for(int pd = 0; pd <= j - 1 ; pd ++){
                    nax = max(nax , dp[i - 1][pd] + A[j] - A[pd]);
                }
                dp[i][j] = nax;
            }
        }
        return dp[K][N - 1];
    }
};

// METHOD 2 : TIME = O(K * N) , SPACE = O(K * N)

class Solution {
  public:
    int maxProfit(int K, int N, int A[]) {
        vector<vector<int>>dp(K + 1, vector<int>(N , 0));
        for(int i = 1; i <= K; i ++){
            int maxi = INT_MIN;
            for(int j = 1; j < N; j ++){
                maxi = max(maxi , dp[i - 1][j - 1] - A[j - 1]);
                dp[i][j] = max(maxi + A[j] , dp[i][j - 1]);
            }
        }
        return dp[K][N - 1];
    }
};