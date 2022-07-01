class Solution
{
    public:
    //Function to find the length of longest common subsequence in two strings.
    int lcs(int x, int y, string s1, string s2)
    {
        vector<vector<int>>dp(x + 1, vector<int>(y + 1));
        for(int i = 0; i <= x ; i ++){
            for(int j = 0; j <= y ; j ++){
                if(i == 0 or j == 0) dp[i][j] = 0;
            }
        }
        for(int i = 1; i <= x ; i ++){
            for(int j = 1; j <= y ; j ++){
                if(s1[i - 1] == s2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j] , dp[i][j - 1]);
            }
        }
        return dp[x][y];
    }
};


// SPACE OPTIMISED
class Solution
{
    public:
    //Function to find the length of longest common subsequence in two strings.
    int lcs(int x, int y, string s1, string s2)
    {
        // vector<vector<int>>dp(x + 1, vector<int>(y + 1));
        vector<int>prev(y + 1,0) , curr(y + 1,0);
        for(int i = 1; i <= x ; i ++){
            curr[0] = 0;
            for(int j = 1; j <= y ; j ++){
                if(s1[i - 1] == s2[j - 1])
                    curr[j] = 1 + prev[j - 1];
                else
                    curr[j] = max(prev[j] , curr[j - 1]);
            }
            prev = curr;
        }
        return prev[y];
    }
};