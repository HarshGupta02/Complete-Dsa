// TIME = O(N * M) , SPACE = O(N * M)

class Solution {
  public:
    int editDistance(string s, string t) {
        int n = s.size() , m = t.size();
        if(n == 0) return m; if(m == 0) return n;
        // dp[i][j] = min operations needed to convert strings s[0 ... i] to t[0....j]
        vector<vector<int>>dp(n + 1 , vector<int>(m + 1, INT_MAX));
        for(int i = 0; i <= n; i++){
            for(int j = 0; j <= m; j++){
                if(i == 0 or j == 0) dp[i][j] = i + j;
            }
        }
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(s[i - 1] == t[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                else
                    dp[i][j] = min(dp[i][j] , 1 + min(dp[i][j - 1] , min(dp[i - 1][j] , dp[i - 1][j - 1])));
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
        if(n == 0) return m; if(m == 0) return n;
        // dp[i][j] = min operations needed to convert strings s[0 ... i] to t[0....j]
        vector<int>prev(m + 1 , 0) , curr(m + 1 , 0);
        for(int i = 0; i <= m; i++){
            prev[i] = i;
        }
        for(int i = 1; i <= n; i++){
            curr[0] = i;
            for(int j = 1; j <= m; j++){
                if(s[i - 1] == t[j - 1])
                    curr[j] = prev[j - 1];
                else
                    curr[j] = 1 + min(curr[j - 1] , min(prev[j] , prev[j - 1]));
            }
            prev = curr;
        }
        return prev[m];
    }
};