/// here we use the gap method to calculate all substrings of the chain from i to j
/// as we try to set cuts(k) from i to j so as to divide it into groups [i...k] , [k + 1 ...j]
// and total cost will be dp[i][k] + dp[k + 1][j] + arr[i] * arr[k + 1] * arr[j + 1];
// take the min of all costs for given i and j and then set dp[i][j] to min cost.


class Solution{
public:
    int matrixMultiplication(int N, int arr[])
    {
        N --;
        vector<vector<int>>dp(N, vector<int>(N));
        for(int gap = 0 ; gap <= N - 1; gap ++){
            for(int i = 0 , j = gap ; j <= N - 1; i ++, j ++){
                if(gap == 0){
                    dp[i][j] = 0; continue;
                }
                int mini = INT_MAX;
                for(int k = i ; k <= j - 1; k ++){
                    int lc = dp[i][k];
                    int rc = dp[k + 1][j];
                    int mc = arr[i] * arr[k + 1] * arr[j + 1];
                    int total = lc + rc + mc;
                    mini = min(mini , total);
                }
                dp[i][j] = mini;
            }
        }
        return dp[0][N - 1];
    }
};