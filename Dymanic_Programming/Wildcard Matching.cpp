class Solution {
public:
    bool isMatch(string s, string p) {
        int p_sz = p.size(), s_sz = s.size();
        vector<vector<bool>>dp(p_sz + 1, vector<bool>(s_sz + 1));
        for(int i = 0; i <= p_sz; i ++){
            for(int j = 0; j <= s_sz; j ++){
                if(i == 0 and j == 0) dp[i][j] = true;
                else if(i == 0) dp[i][j] = false;
                else if(j == 0) dp[i][j] = (p[i - 1] == '*' ? dp[i - 1][j] : false);
                else{
                    if(p[i - 1] == '*') dp[i][j] = dp[i - 1][j] or dp[i][j - 1];
                    else if(p[i - 1] == '?') dp[i][j] = dp[i - 1][j - 1];
                    else if(p[i - 1] == s[j - 1]) dp[i][j] = dp[i - 1][j - 1];
                    else dp[i][j] = false;
                }
            }
        }
        return dp[p_sz][s_sz];
    }
};