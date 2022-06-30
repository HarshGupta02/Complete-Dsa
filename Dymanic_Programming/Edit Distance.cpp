/// TIME = O(N * M) , SPACE = O(N * M)

class Solution {
  public:
    int editDistance(string s, string t) {
        int n = s.size() , m = t.size();
        vector<vector<int>>dp(n + 1 , vector<int>(m + 1));
        dp[0][0] = 0;
        for(int i = 1; i <= n ; i++) dp[i][0] = i;
        for(int i = 1; i <= m ; i++) dp[0][i] = i;
        for(int i = 1; i <= n ; i ++){
            for(int j = 1; j <= m ; j ++){
                if(s[i - 1] == t[j - 1]) dp[i][j] = dp[i - 1][j - 1];
                else dp[i][j] = 1 + min(dp[i][j - 1] , min(dp[i - 1][j - 1] , dp[i - 1][j]));
            }
        }
        return dp[n][m];
    }
};

/// TIME = O(N * M) , SPACE = O(M)

class Solution {
  public:
    int editDistance(string s, string t) {
        int n = s.size() , m = t.size();
        vector<int>prev(m + 1,0) , curr(m + 1,0);
        for(int i = 0 ; i <= m ; i++) prev[i] = i;
        for(int i = 1; i <= n ; i ++){
            curr[0] = i;
            for(int j = 1; j <= m ; j ++){
                if(s[i - 1] == t[j - 1]) curr[j] = prev[j - 1];
                else curr[j] = 1 + min(curr[j - 1] , min(prev[j - 1] , prev[j]));
            }
            prev = curr;
        }
        return prev[m];
    }
};